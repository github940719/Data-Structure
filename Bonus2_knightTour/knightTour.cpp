//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "knightTour.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// 8 different directions to walk toward
int nextX[8] = {2, 2, 1, -1,-2, -2, -1, 1} ;
int nextY[8] = {-1, 1, 2, 2, 1, -1, -2, -2} ;
int size ;
int** square = nullptr ;


bool validPosition(int size, int** square, int x, int y) {
    return (x >= 0 && y >= 0 && x < size && y < size && square[x][y] == 0) ;
}


int possibleWayCnt(int size, int** square, int startX, int startY) {
    int ans = 0 ;
    for (int i = 0; i < 8; i++) {
        int x = startX + nextX[i], y = startY + nextY[i] ;
        if (validPosition(size, square, x, y)) {
            ans++ ;
        }
    }
    return ans ;
}


void knightTour(int size, int startX, int startY, int** square) {
    square[startX][startY] = 1 ;
    for (int i = 2; i <= size * size; i++) {  // for the i^th step
        int leastIndex = -1, leastCnt = 0 ;
        for (int j = 0; j < 8; j++) {  // for all next direction
            if (!validPosition(size, square, startX + nextX[j], startY + nextY[j])) {
                continue ;  // ignore invalid direction
            }
            // find the valid next way count of this direction
            int nextWayCnt = possibleWayCnt(size, square, startX + nextX[j], startY + nextY[j]) ;
            if (leastIndex == -1) {  // choose this first valid way
                leastIndex = j ;
                leastCnt = nextWayCnt ;
            }
            else if (nextWayCnt > 0 && (leastCnt == 0 || nextWayCnt < leastCnt)) {  // choose this way (with least number of next valid way but > 0)
                leastIndex = j ;
                leastCnt = nextWayCnt ;
            }
        }

        // check whether the knight stuck here
		if (leastIndex == -1) {
			ShowMessage("step = " + IntToStr(i) + " stuck at x = " + IntToStr(startX) + ", y = " + IntToStr(startY)) ;
			return ;
        }

        // move
        startX += nextX[leastIndex] ;
        startY += nextY[leastIndex] ;
        square[startX][startY] = i ;
    }
}


void print(int size, int** square, TObject* Sender) {
	Form1->StringGrid1->RowCount = size ;
	Form1->StringGrid1->ColCount = size ;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (square[i][j]) {  // > 0
				Form1->StringGrid1-> Cells[j][i] = IntToStr(square[i][j]) ;
			}
			else {
				 Form1->StringGrid1-> Cells[j][i] = "" ;
			}
        }
	}
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	int startX, startY ;

	// delete the dynamic allocation memory
	if (square) {
		for (int i = 0; i < size; i++) {
			delete [] square[i] ;
		}
		delete [] square ;
	}

	// deal with invalid size
	if (!TryStrToInt(EditSize->Text, size)) {
		ShowMessage("please enter number") ;
		return ;
	}
	if (size < 4) {
		ShowMessage("size should > 3") ;
        return ;
	}

	if (Form1->CheckBoxRandom->Checked) {  // randomly generate startX and startY
		startX = rand() % size ;
        startY = rand() % size ;
	}
	else {   // deal with invalid startX or startY
		if (!TryStrToInt(EditStartX->Text, startX) ||
			!TryStrToInt(EditStartY->Text, startY)) {
			ShowMessage("please enter number") ;   // deal with invalid input
			return ;
		}
		if (startX < 0 || startY < 0 || startX >= size || startY >= size) {
			ShowMessage("0 <= x, y < size") ;
			return ;
		}
	}

	// initalize the square
    square = new int*[size] ;
    for (int i = 0; i < size; i++) {
        square[i] = new int[size] ;
        for (int j = 0; j < size; j++) {
            square[i][j] = 0 ;
        }
    }

    // generate the knight tour square
	knightTour(size, startX, startY, square) ;

	// print the knight tour on the memo
	print(size, square, Sender) ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	if (square == nullptr) {
		ShowMessage("please generate knight tour first") ;
		return ;
	}

	Form1->StringGrid2->RowCount = size ;
	Form1->StringGrid2->ColCount = size ;

	// clear the original content of the string grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            StringGrid2->Cells[j][i] = "" ;
        }
	}

	// for all numbers in the square
    int formerI = -1, formerJ = -1 ;
	for (int value = 1; value <= size * size; value++) {
		bool find = false ;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (square[i][j] == value) {

					// add this number to the string grid
					StringGrid2->Cells[j][i] = IntToStr(value) ;
					StringGrid2->Refresh() ;
					Sleep(100 + (10 - TrackBar1->Position) * 40) ;  // control the speed
					find = true ;
					formerI = i, formerJ = j ;
				}
			}
			if (find) {
				break ;
			}
		}
		if (!find) {
			ShowMessage("step = " + IntToStr(value) + " stuck at x = " + IntToStr(formerI) + ", y = " + IntToStr(formerJ)) ;
			break ;
		}
    }
}
//---------------------------------------------------------------------------

