//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "magicSquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


int formerSize ;  // to help delete dynamic array
int size ;
int** square ;
TForm1 *Form1 ;

// for checking the sum
int* rowSum = nullptr ;
int* colSum = nullptr ;
int diagonalSum1 = 0 ;
int diagonalSum2 = 0 ;


void generateSquare() {  // generate empty magic square
	if (square) {  // not nullptr -> delete the memory of the dynamic squareay
		for (int i = 0; i < formerSize; i++) {
			delete [] square[i] ;
			square[i] = nullptr ;
		}
		delete [] square ;
	}

	// two-dimentional dynamic array
    square = new int*[size] ;
    for (int i = 0; i < size; i++) {
        square[i] = new int[size] ;
        for (int j = 0; j < size; j++) {
            square[i][j] = 0 ;
        }
	}
}


void magicOdd(int size) {  // magic square for odd size
	// move according to the user's selection, even though invalid

	// deal with the starting point
	int i = 0, j = size / 2 ;  // default: starting from the top middle
	if (Form1->RadioBottom->Checked) {
		i = (size - 1) ;  // starting from the bottom middle
	}
	else if (Form1->RadioLeft->Checked || Form1->RadioRight->Checked) {
		i = size / 2 ;
		if (Form1->RadioLeft->Checked) {
			j = 0 ;  // starting from the left middle
		}
		else {
			j = (size - 1) ;  // starting from the right middle
		}
    }
	square[i][j] = 1 ;

	// traverse
    for (int n = 2; n <= size * size; n++) {
		int nextI = (i - 1 + size) % size ;  // default: move upward
		if (Form1->RadioDownRight->Checked || Form1->RadioDownLeft->Checked) {
			nextI = (i + 1) % size ;  // move downward
		}

		int nextJ = (j - 1 + size) % size ;  // default: move leftward
		if (Form1->RadioDownRight->Checked || Form1->RadioUpRight->Checked) {
			nextJ = (j + 1) % size ;  // move rightward
		}

		if (square[nextI][nextJ]) {  // if a number has occupied this position
			if (Form1->RadioConflictLeft->Checked || Form1->RadioConflictRight->Checked) {
				if (Form1->RadioConflictLeft->Checked) {
					j = (j - 1 + size) % size ;  // move leftward
				}
				else {
					j = (j + 1) % size ;  // move rightward
                }
			}
			else if (Form1->RadioConflictUp->Checked) {
				i = (i - 1 + size) % size ;  // move upward
			}
			else {
				i = (i + 1) % size ;  // default: move downward
			}
        }
        else {  // not occupied
            i = nextI ;
            j = nextJ ;
        }
        square[i][j] = n ;
	}
}


void magic4() {  // magic square for size = 4k
    // fill in 1, 2, ..., size*size from left to right, top to bottom
    int num = 1 ;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i % 4 == j % 4) || ((i + j + 1) % 4 == 0)) {
                /*
                exception: on the left top to right bottom, or left bottom to right top diagonal
                swap square[i][j] and square[size - i - 1][size - j - 1]
                */
                square[i][j] = (1 + size * size) - num ;
            }
            else {
                square[i][j] = num ;
            }
            num++ ;
        }
    }
}


void swap(int& a, int& b) {  // swap for magic2
	int temp = a ;
    a = b ;
    b = temp ;
}


void magic2() {   // magic square for size = 2k + 2 : Strachey method
	/*
    seperate the square into 4 odd-n square as below:
    A C
    D B
    */

    // generate A as a square matric (odd-length)
    int half = size / 2 ;
	magicOdd(half) ;

    // B, C, D: corresponding cell in A + (1 or 2 or 3) * (falf * half)
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            square[i + half][j + half] = square[i][j] + half * half ;  // B
            square[i][j + half] = square[i][j] + 2 * half * half ;  // C
            square[i + half][j] = square[i][j] + 3 * half * half ;  // D
        }
    }

    // swap some position of A and B, C and D
    int quarter = half / 2 ;
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < quarter; j++) {
            // exchange the leftmost "quarter" columns (A and D)
            swap(square[i][j], square[half + i][j]) ;
        }
        for (int j = 0; j < quarter - 1; j++) {
            // exchange the rightmost "quarter - 1" (B and C)
            swap(square[i][size - 1 - j], square[half + i][size - 1 - j]) ;
        }

        // Exchange the middle cell of the leftmost column (A and D)
        swap(square[quarter][0], square[quarter + half][0]) ;

        // Exchange the central cell in A and D
        swap(square[quarter][quarter], square[quarter + half][quarter]) ;
    }
}


void memoPrint(TObject *Sender) {  // print the square on the memo
	 Form1->MemoOutput->Clear() ;
	 int len = IntToStr(size * size).Length() + 2 ;  // max number of digit + 2
	 for (int i = 0; i < size; i++) {
		String row = "" ;
		for (int j = 0; j < size; j++) {
			// space = len - digit
			int space = len - IntToStr(square[i][j]).Length();
			for (int k = 0; k < space; k++) {
				row += "  " ; // place the space
			}
			row += IntToStr(square[i][j]) ;  // write the number
		 }
		 Form1->MemoOutput->Lines->Add(row);
	 }
}


void memoPrintSum(TObject *Sender) {  // print the square on the memo with sum
	Form1->memoCheck->Clear() ;
	int len = IntToStr((1 + size * size) * size / 2).Length() + 3 ;  // rowSum + 3

	// print each row
	for (int i = 0; i < size; i++) {
		String row = "" ;
		for (int j = 0; j < size; j++) {
            int space = len - IntToStr(square[i][j]).Length();
			for (int k = 0; k < space; k++) {
				row += "  " ;
			}
			row += IntToStr(square[i][j]) ;
		}
		row += "   - " + IntToStr(rowSum[i]) ;
		Form1->memoCheck->Lines->Add(row) ;
	}

	// print the last row : col sum
	String row = "" ;
	for (int j = 0; j < size; j++) {
		row += "    | " + IntToStr(colSum[j]) ;
	}

	// print diagonalSum
	row += "   \\" + IntToStr(diagonalSum1) + "  /" + IntToStr(diagonalSum2) ;
	Form1->memoCheck->Lines->Add(row) ;
}


void gridPrint(TObject *Sender) {
	// set the row and col count
	Form1->StringGrid1->RowCount = size ;
	Form1->StringGrid1->ColCount = size ;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Form1->StringGrid1->Cells[j][i] = IntToStr(square[i][j]) ;
		}
	}
}

void gridPrintSum(TObject *Sender) {
	// set the row and col count
    Form1->StringGrid2->RowCount = size + 1;
    Form1->StringGrid2->ColCount = size + 1;

	// print each row
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Form1->StringGrid2->Cells[j][i] = IntToStr(square[i][j]);
        }
        Form1->StringGrid2->Cells[size][i] = "- " + IntToStr(rowSum[i]);
    }

	// print the last row : col sum
    for (int j = 0; j < size; j++) {
        Form1->StringGrid2->Cells[j][size] = "| " + IntToStr(colSum[j]);
    }

	// print the diagonal sum
	Form1->StringGrid2->Cells[size][size] = "\\ " + IntToStr(diagonalSum1) + " / " + IntToStr(diagonalSum2);

	for (int i = 0; i < Form1->StringGrid2->ColCount; i++) {
		Form1->StringGrid2->ColWidths[i] = IntToStr(diagonalSum1).Length() * 20;  // reset the width
	}
	Form1->StringGrid2->ColWidths[size] = (IntToStr(diagonalSum1).Length() * 2 + 6)*10;
}


void calculateSums() {  // calculate rowSum, colSum, diagonalSum1, diagonalSum2
	// delete the memory of the dynamic array
	if (rowSum) {
		delete[] rowSum ;
	}
	if (colSum) {
		delete[] colSum ;
	}

	// initialize
	rowSum = new int[size] ;
	colSum = new int[size] ;
	diagonalSum1 = 0 ;
	diagonalSum2 = 0 ;
    for (int i = 0; i < size; i++) {
		rowSum[i] = 0 ;
		colSum[i] = 0 ;
    }

	// calculate
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
			rowSum[i] += square[i][j] ;
			colSum[j] += square[i][j] ;
			if (i == j) diagonalSum1 += square[i][j] ;   // "\"
			if (i + j == size - 1) diagonalSum2 += square[i][j] ;  // "/"
        }
    }
}


void checkValid(TObject* Sender) {  // output the validity on the memoCheck
	int sum = (1 + size * size) * size / 2 ;
	bool valid = true ;

    for (int i = 0; i < size; i++) {
        if (rowSum[i] != sum || colSum[i] != sum) {
			valid = false ;
			break ;
        }
    }

    if (diagonalSum1 != sum || diagonalSum2 != sum) {
		valid = false ;
    }

	Form1->checkResult->Clear();
	Form1->checkResult->Lines->Add(IntToStr(size) + " * " + IntToStr(size) + " square matrix") ;
	Form1->checkResult->Lines->Add("theoretical sum = " + IntToStr(sum)) ;
	Form1->checkResult->Lines->Add(valid ? "valid!" : "invalid!") ;
}


__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	// deal with the input size
	if (! TryStrToInt(Form1->Edit_size->Text, size)) {
		Form1->checkResult->Lines->Add("please enter integer size!") ;
		return ;
	}
	if (size <= 2) {
		Form1->checkResult->Lines->Add("size should >= 3!") ;
		return ;
	}

	generateSquare() ;
	formerSize = size ;  // to help delete the memory of the dynamic array
	if (size % 2 == 1) {  // size is odd
		magicOdd(size) ;
	}
	else if (size % 4 == 0) {  // size = 4k
		magic4() ;
	}
	else {  // size = 2k + 2
		magic2() ;
	}

	calculateSums() ;

	// output the result
	memoPrint(Sender) ;
	gridPrint(Sender) ;
	memoPrintSum(Sender) ;
	gridPrintSum(Sender) ;
	if (Form1->selfCheck->Checked) {
		checkValid(Sender) ;
	}
}
//---------------------------------------------------------------------------

