//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <string>
#include <ctime>
#pragma hdrstop

#include "rat_in_maze.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct Direction {
	int x, y ;
} ;


struct Position {
	int x, y, to = 0 ;  // to is default to be 0
};

// 4 moving directions
int sizeX = 0, sizeY = 0, startX = -1, startY = -1, endX = -1, endY = -1 ;
bool** maze = nullptr ;  // 0 if walkable, 1 if wall
bool** visited = nullptr ;  // true if visited
struct Direction dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} } ;


// stack definition
class myStack {
	private:
        int maxSize ;
        struct Position* arr = nullptr ;
        int top = -1 ;

	public:
		myStack(int maxSize) : maxSize(maxSize) {  // constructor
			arr = new struct Position[maxSize] ;
        }

        ~myStack() {  // destructor
            delete [] arr ;
            arr = nullptr ;
        }

        bool isFull() {
            return (top == maxSize - 1) ;
        }


        bool isEmpty() {
            return (top == -1) ;
        }

		void push(struct Position element) {
            if (isFull()) {
				ShowMessage("Stack is full");
            }
            arr[++top] = element ;
        }

        struct Position peek() {
            if (isEmpty()) {
				 ShowMessage("Stack is empty");
            }
            return arr[top] ;
        }

		struct Position pop() {
            if (isEmpty()) {
                 ShowMessage("Stack is empty");
            }
            return arr[top--] ;
		}

		void printPath(TObject* Sender) {
			Form1->Memo1->Lines->Add("") ;
			Form1->Memo1->Lines->Add("the rat has found a valid path as below: ") ;
			Form1->StringGrid->Cells[startY-1][startX] = 2 ;  // entrance
			Form1->StringGrid->Cells[endY+1][endX] = 2 ;  // exit

			String aPath = "" ;
			for (int i = 0; i < top; i++) {;
				Form1->StringGrid->Cells[arr[i].y][arr[i].x] = 2 ;  // this is the path
				aPath += ("(" + IntToStr(arr[i].x) + ", " + IntToStr(arr[i].y) + ")->") ;
			}
			Form1->StringGrid->Cells[arr[top].y][arr[top].x] = 2 ;  // this is the path
			Form1->Memo1->Lines->Add(aPath + ("(" + IntToStr(arr[top].x) + ", " + IntToStr(arr[top].y) + ")")) ;
		}

		void printPathAnimation(TObject* Sender) {
			Form1->StringGrid1->Cells[startY-1][startX] = 2 ;  // entrance
			Form1->StringGrid1->Cells[endY+1][endX] = 2 ;  // exit

			for (int i = 0; i < top; i++) {;
				Form1->StringGrid1->Cells[arr[i].y][arr[i].x] = 2 ;  // this is the path
			}
			Form1->StringGrid1->Cells[arr[top].y][arr[top].x] = 2 ;  // this is the path
		}
} ;


// main function
void solveMaze(TObject* Sender) {

	// create the stack to store positions which is explored
	int sizeOfStack = sizeX / 2 * (sizeY + 1) ;
	if (sizeY / 2 * (sizeX + 1) > sizeX / 2 * (sizeY + 1)) {
		sizeOfStack = sizeY / 2 * (sizeX + 1) ;
	}
	myStack explore(sizeOfStack) ;
	struct Position start{startX, startY} ;
	explore.push(start) ;
	visited[startX][startY-1] = true ;  // avoid going back to start point
	visited[startX][startY] = true ;  // avoid going back to start point

	while (!explore.isEmpty()) {
		struct Position point = explore.pop() ;
		for ( ; point.to < 4; point.to++) {  // for each remaining direction
			struct Position next{point.x + dir[point.to].x, point.y + dir[point.to].y} ;

			if (maze[next.x][next.y] == 0 && visited[next.x][next.y] == false) {
				explore.push(point) ;  // push this point
				explore.push(next) ;   // push the next node
				visited[next.x][next.y] = true ;

				if (next.x == endX && next.y == endY) {  // reach the exit
					explore.printPath(Sender) ;
					return ;
				}
				break ;
			}
		}
	}

	ShowMessage("there exists no valid path.") ;
}


void printMaze(TObject* Sender) {

	Form1->StringGrid->RowCount = sizeX ;  // for print on string grid
	Form1->StringGrid->ColCount = sizeY ;
	Form1->StringGrid1->RowCount = sizeX ;  // for animation
	Form1->StringGrid1->ColCount = sizeY ;

	// print the title
	Form1->Memo1->Lines->Clear() ;
	Form1->Memo1->Lines->Add("This is a " + IntToStr(sizeX) + " * " + IntToStr(sizeY) + " maze") ;
	Form1->Memo1->Lines->Add("The entrance is at (" + IntToStr(startX) + ", " + IntToStr(startY) + ")") ;
	Form1->Memo1->Lines->Add("The exit is at (" + IntToStr(endX) + ", " + IntToStr(endY) + ")") ;

	// set the width and height of the string grid
	for (int i = 0; i < Form1->StringGrid->ColCount; i++) {
		Form1->StringGrid->ColWidths[i] = 30 ;
		Form1->StringGrid1->ColWidths[i] = 30 ;
	}
	for (int i = 0; i < Form1->StringGrid->RowCount; i++) {
		Form1->StringGrid->RowHeights[i] = 30 ;
		Form1->StringGrid1->RowHeights[i] = 30 ;
	}

	// mark 0 or 1 on the string grid
	for (int i = 0; i < sizeX; i++) {
		UnicodeString aLine = "" ;
		for (int j = 0; j < sizeY; j++) {
			aLine += IntToStr(maze[i][j]) ;
			aLine += " " ;

			// if this cell is walkable
			if (maze[i][j] == 0) {
				Form1->StringGrid->Cells[j][i] = "0";
				Form1->StringGrid1->Cells[j][i] = "0";
			}

			else {  // if this cell is the wall
				Form1->StringGrid->Cells[j][i] = "1";
                Form1->StringGrid1->Cells[j][i] = "1";
			}
		}
        Form1->Memo1->Lines->Add(aLine) ;
	}
}


void clearDynamic() {
	// clear the previous maze and predecessor
	if (maze) {
		for (int i = 0; i < sizeX; i++) {
			delete [] maze[i] ;
		}
		delete [] maze ;
		maze = nullptr ;
	}

	if (visited) {
		for (int i = 0; i < sizeX; i++) {
			delete [] visited[i] ;
		}
		delete [] visited ;
		visited = nullptr ;
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner){}
//---------------------------------------------------------------------------
// load the maze from .txt
void __fastcall TForm1::Button1Click(TObject *Sender) {

    clearDynamic() ;
	OpenDialog->Filter = "Text Files (*.txt)|*.txt";  // just show .txt file
	if (!OpenDialog->Execute()) {
		return ;
	}

	// load the txt file
	UnicodeString fileName = OpenDialog->FileName;
	std::wstring wFileName(fileName.c_str());
	std::wifstream file(wFileName);
	if (!file.is_open()) {
		ShowMessage("Fail to open the file") ;
		return ;
	}

	// initialize the maze
	file >> sizeX >> sizeY >> startX >> startY >> endX >> endY ;
	sizeX += 2 ;  // the width of the wall
	sizeY += 2 ;
	maze = new bool*[sizeX] ;
	visited = new bool*[sizeX] ;

	// read the maze and print on the memo and string grid
	for (int i = 0; i < sizeX; i++) {
		maze[i] = new bool[sizeY] ;
		visited[i] = new bool[sizeY] ;
		for (int j = 0; j < sizeY; j++) {
		visited[i][j] = false ;
			if (i == 0 || i == sizeX - 1 || j == 0 || j == sizeY - 1) {
				maze[i][j] = 1 ;  // wall of the boundry
			}
			else {
				file >> maze[i][j] ;
			}
		}
	}

	maze[startX][startY-1] = 0 ; // break the left wall of the entrance
	maze[endX][endY+1] = 0 ; // break the right wall of teh exit
	printMaze(Sender) ;
}
//---------------------------------------------------------------------------
// search for a path and print it
void __fastcall TForm1::Button2Click(TObject *Sender) {
	// path is the maze, the cell of which is the predecessor used to backtrack
	if (maze == nullptr) {
		ShowMessage("generate or load the maze first.") ;
		return ;
	}

	// reset visited
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			visited[i][j] = false ;
		}
	}

	solveMaze(Sender) ;

	// print the maze on the memo
	Form1->Memo1->Lines->Add("") ;
	for (int i = 0; i < sizeX; i++) {
		String aLine = "" ;
		for (int j = 0; j < sizeY; j++) {
			if (Form1->StringGrid->Cells[j][i] == 2) {
				aLine += "2 " ;
			}
			else {
				aLine += (IntToStr(maze[i][j]) + " ") ;
			}
		}
		Form1->Memo1->Lines->Add(aLine) ;
	}
}
//---------------------------------------------------------------------------
// draw cell on the string grid (static)
void __fastcall TForm1::StringGridDrawCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow, TRect &Rect, TGridDrawState State) {

	// set the color according to ")" or "1"
	if (StringGrid->Cells[ACol][ARow] == "1") {  // the wall
		StringGrid->Canvas->Brush->Color = TColor RGB(169, 169, 169) ;
	}
	else if (StringGrid->Cells[ACol][ARow] == "0") {  // a walkable cell
		StringGrid->Canvas->Brush->Color = TColor RGB(144, 238, 144) ;
	}
	else {  // 2 : the path
        StringGrid->Canvas->Brush->Color = TColor RGB(255, 204, 153) ;
    }

	StringGrid->Canvas->FillRect(Rect) ;
	StringGrid->Canvas->Font->Color = clBlack ; 	// the color of text
}
//---------------------------------------------------------------------------

// randomly generate a maze
void generateMaze(int x, int y) {
	maze[x][y] = 0 ; // mark this cell walkable

	// check for potential moves in 4 directions
	while ((y + 2 < sizeY-1 && maze[x][y + 2] == 1) ||
		   (x - 2 > 0 && maze[x - 2][y] == 1) ||
		   (y - 2 > 0 && maze[x][y - 2] == 1) ||
		   (x + 2 < sizeX-1 && maze[x + 2][y] == 1)) {
		int i = rand() % 4 ; // choose a random direction
		int foreseeX = x + 2 * dir[i].x, foreseeY = y + 2 * dir[i].y ;
		if ((foreseeX > 0) && (foreseeY > 0) && (foreseeX < sizeX-1) &&
			(foreseeY < sizeY-1) && (maze[foreseeX][foreseeY] == 1)) {
			maze[x+dir[i].x][y+dir[i].y] = 0 ;  // break the wall
			generateMaze(foreseeX, foreseeY) ;  // recurse to the next wall
		}
	}
}

// button for randomly generate a maze
void __fastcall TForm1::Button3Click(TObject *Sender) {

	// check whether the input is integer
	if (!TryStrToInt(EditSizeX->Text, sizeX) ||
		!TryStrToInt(EditSizeY->Text, sizeY) ||
		!TryStrToInt(EditStartX->Text, startX) ||
		!TryStrToInt(EditEndX->Text, endX)) {
			ShowMessage("please enter integer.") ;
            return ;
	}
    startY = 1, endY = sizeY ;

	// check the validity
	if (sizeX < 2 || sizeY < 2) {
		ShowMessage("the size should > 1.") ;
		return ;
	}


	if (sizeX % 2 == 0 || sizeY % 2 == 0) {
		ShowMessage("the size should be odd.") ;
		return ;
	}

	if (startX < 1 || startY < 1 || endX < 1 || endY < 1 ||
		startX > sizeX || startY > sizeY || endX > sizeX || endY > sizeY) {
		ShowMessage("the position is not in the maze (or is the wall).") ;
        return ;
	}

	if (startX % 2 == 0 || endX % 2 == 0) {
		ShowMessage("x of the entrance / exit should be odd.") ;
		return ;
	}

	// initialize the maze
	sizeX += 2 ;  // include the boundry wall
    sizeY += 2 ;
	maze = new bool*[sizeX] ;
	visited = new bool*[sizeX] ;
	for (int i = 0; i < sizeX; i++) {
		maze[i] = new bool[sizeY] ;
		visited[i] = new bool[sizeY] ;
		for (int j = 0; j < sizeY; j++) {
			maze[i][j] = 1 ;  // default : wall
            visited[i][j] = false ;
		}
	}

	generateMaze(startX, endY) ;
	maze[startX][startY-1] = 0 ; // break the left wall of the entrance
	maze[endX][endY+1] = 0 ; // break the right wall of teh exit
	printMaze(Sender) ;
}


void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State) {
	// set the color according to ")" or "1"
	if (StringGrid1->Cells[ACol][ARow] == "1") {  // the wall
		StringGrid1->Canvas->Brush->Color = TColor RGB(169, 169, 169) ;
	}
	else if (StringGrid1->Cells[ACol][ARow] == "0") {  // a walkable cell
		StringGrid1->Canvas->Brush->Color = TColor RGB(144, 238, 144) ;
	}
	else if (StringGrid1->Cells[ACol][ARow] == "2") {  // the path
		StringGrid1->Canvas->Brush->Color = TColor RGB(255, 204, 153) ;
	}
	else if (StringGrid1->Cells[ACol][ARow] == "@") {  // the rat
        StringGrid1->Canvas->Brush->Color = TColor RGB(255, 255, 255) ;
	}

	StringGrid1->Canvas->FillRect(Rect) ;
	StringGrid1->Canvas->Font->Color = clBlack ; 	// the color of text
}
//---------------------------------------------------------------------------
// change the color(animation)
void changeColor(TObject* Sender, struct Position& former, struct Position& position) {
	Form1->StringGrid1->Cells[former.y][former.x] = "0" ;  // remove the @
	Form1->StringGrid1->Cells[position.y][position.x] = "@" ;
	Form1->StringGrid1->Invalidate(); // renew, no flash
	Application->ProcessMessages(); // allow UI to renew
	Sleep(50 + (10 - Form1->TrackBar1->Position) * 20) ;  // control the speed
	former = position ;
}

// button for animation
void __fastcall TForm1::Button4Click(TObject *Sender) {
	// the following is similar to solveMaze, but with animation
	if (maze == nullptr) {
		ShowMessage("please generate or load the maze first.") ;
		return ;
	}

	// reset visited
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			visited[i][j] = false ;
		}
	}

	// reset the color
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			// if someone press "animation" twice for the same maze
			if (StringGrid1->Cells[j][i] == "2") {   // last time this is a path
				StringGrid1->Cells[j][i] = "0" ;  // reset it to walkable
			}
		}
	}

    // create the stack to store Points to be explored
	int sizeOfStack = sizeX / 2 * (sizeY + 1) ;
	if (sizeY / 2 * (sizeX + 1) > sizeX / 2 * (sizeY + 1)) {
		sizeOfStack = sizeY / 2 * (sizeX + 1) ;
	}
	myStack explore(sizeOfStack) ;
	struct Position start{startX, startY} ;
	explore.push(start) ;

	// first put the rat on the entrance
	StringGrid1->DoubleBuffered = true ;
	StringGrid1->Cells[startY-1][startX] = "@" ;
	struct Position former{startX, startY-1} ;
	visited[startX][startY-1] = true ;  // avoid going back to start point
	visited[startX][startY] = true ;  // avoid going back to start point

	while (!explore.isEmpty()) {
		struct Position point = explore.pop() ;
		changeColor(Sender, former, point) ;

		for ( ; point.to < 4; point.to++) {  // for each remaining direction
			struct Position next{point.x + dir[point.to].x, point.y + dir[point.to].y} ;
			if (maze[next.x][next.y] == 0 && visited[next.x][next.y] == false) {
				explore.push(point) ;  // push this point
				explore.push(next) ;   // push the next node
				visited[next.x][next.y] = true ;

				if (next.x == endX && next.y == endY) {  // reach the exit
					former.x = point.x, former.y = point.y ;
                    point.x = next.x, point.y = next.y ;
					changeColor(Sender, former, point) ;
					explore.printPathAnimation(Sender) ;
					return ;
				}
				break ;
			}
		}

        former.x = point.x, former.y = point.y ;
	}
	ShowMessage("there exists no valid path.") ;
}
//---------------------------------------------------------------------------

