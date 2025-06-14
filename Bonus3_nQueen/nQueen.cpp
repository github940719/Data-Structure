//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "nQueen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int solCnt ;

// given an arr and the position (row, col) of a new-added queen
// determine whether this is valid by checking col and diagonal (before this position)
bool isValid(int row, int col, int** arr, int n) {

	for (int i = 0; i < row; i++) {  // check the column
		if (arr[i][col])
			return false ;
	}

	// check the diagonal
	for (int r = row-1, c = col-1; r >= 0 && c >= 0 ; r--, c--) {
		if (arr[r][c]) {
			return false ;
		}
	}
	for (int r = row-1, c = col+1; r >= 0 && c < n; r--, c++) {
		if (arr[r][c]) {
			return false ;
		}
	}
	
	return true ;
}


// print the 2-D memo on memo2
void print2dMemo(TMemo* memo, int** arr, int n) {
	memo->Lines->Add("solution #" + IntToStr(solCnt) + " is found.") ;
	for (int i = 0; i < n; i++) {
		String line = "" ;
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				line += "Q" ;
			}
			else {
				line += "__" ;
			}
		}
		memo->Lines->Add(line) ;
	}
	memo->Lines->Add("") ;
}


// print the 1-D memo on memo1
void print1dMemo(TMemo* memo, int** arr, int n) {
	memo->Lines->Add("solution #" + IntToStr(solCnt) + " is found.") ;
	String ans = "" ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {  // this is the queen
				ans += (IntToStr(j+1) + " ") ;
				break ;
			}
		}
	}
	memo->Lines->Add(ans) ;
	memo->Lines->Add("") ;
}


// print on the string grid
void printGrid(TObject* Sender, int** arr, int n) {
	Form1->PageControl1->ActivePageIndex = 2 ;  // turn to page 3 for string grid
	Form1->StringGrid1->RowCount = n ;
	Form1->StringGrid1->ColCount = n ;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1)
				Form1->StringGrid1->Cells[j][i] = "Q" ;
            else
                Form1->StringGrid1->Cells[j][i] = "-" ;
        }
	}
	ShowMessage("this is the solution # " + IntToStr(solCnt)) ;
}



void backtrack(int row, int** arr, int n, TObject* Sender) {  // row by row
	if (row == n) {  // termination (obtain a valid sol)
		solCnt++ ;
		print2dMemo(Form1->Memo2, arr, n) ;
		print1dMemo(Form1->Memo1, arr, n) ;
		if (Form1->CheckBox1->Checked) {
          	printGrid(Sender, arr, n) ;  
		}
		return ;
    }

	// try to put Q in this row
    for (int col = 0; col < n; col++) {
		if (isValid(row, col, arr, n)) {
			arr[row][col] = 1 ;  // put Q here     
			backtrack(row + 1, arr, n, Sender) ;   // next row 
			arr[row][col] = 0 ;  // cancel this Q        
        }
	}
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
// button to solve the nQueen
void __fastcall TForm1::Button1Click(TObject *Sender) {

    // deal with input n
	int n ;
	if (!TryStrToInt(Edit1->Text, n)) {
		ShowMessage("please enter integere size(n).") ;
		return ;
	}
	if (n < 1) {
		ShowMessage("please enter positive size(n).") ;
        return ;
	}

	// initialize the arr
	int** arr = new int*[n] ;
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n] ;
		for (int j = 0; j < n; j++) {
            arr[i][j] = 0 ;  // default : no queen
		}
	}

	// reset the memo and the string grid
	Memo1->Clear() ;
	Memo2->Clear() ;

	solCnt = 0 ;  // reset the solution count
	backtrack(0, arr, n, Sender) ;

	if (solCnt == 0) {
		Memo1->Lines->Add("no solution is found for size(n) = " + IntToStr(n)) ;
		Memo2->Lines->Add("no solution is found for size(n) = " + IntToStr(n)) ;
	}

	// delete the arr
	delete [] arr ;
}
//---------------------------------------------------------------------------
