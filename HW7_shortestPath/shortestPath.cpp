//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <string>
#include <climits>
#pragma hdrstop

#include "shortestPath.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n ;  // the number of vertices
int** graph = nullptr ;  // adjacency matrix
int INF = INT_MAX ;  // use to denote unconnected

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
    RadioButton2->Checked = true ;   // default: undirected
}
//---------------------------------------------------------------------------
// output the SSAD tracing info
void SSADtracing(TObject* Sender, bool* visited, int* dist, int* predecessor, int iter, int node) {
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			Form1->StringGrid2->Cells[i][iter] = "visited" ;  // visited
		}
		else if (dist[i] == INF) {
			Form1->StringGrid2->Cells[i][iter] = "INF" ;  // INF
		}
		else {
			Form1->StringGrid2->Cells[i][iter] = IntToStr(dist[i]) ;
		}
	}
	Form1->StringGrid2->Cells[n][iter] = node ;  // node
	Form1->StringGrid2->Cells[n+1][iter] = dist[node] ;  // dist
	Form1->StringGrid2->Cells[n+2][iter] = predecessor[node] ;  // pred
}


// output the shortest path
void printSingleSourcePath(TObject *Sender, int source, bool* visited, int* dist, int* predecessor)  {
	Form1->Memo1->Clear() ;
	Form1->Memo1->Lines->Add("source = " + IntToStr(source)) ;

	for (int dest = 0; dest < n; dest++) {
		Form1->Memo1->Lines->Add("") ;
		if (not visited[dest]) {
			Form1->Memo1->Lines->Add("for destination = " + IntToStr(dest) + ", No path!") ;
			continue ;
        }

		if (dest == source) {  // source to itself
			Form1->Memo1->Lines->Add("for destination = " + IntToStr(source) + ", the shortest dist = 0") ;  
			Form1->Memo1->Lines->Add("the path is : " + IntToStr(source)) ;
			continue ;
        }

		// general case     
		UnicodeString path = IntToStr(dest) ;
		int node = dest ;
		while (predecessor[node] != node) {  // not reach the source
			int prev = predecessor[node] ;
			path = IntToStr(prev) + " -> [" + IntToStr(graph[prev][node]) + "] -> " + path ;
			node = prev ;
		}
		Form1->Memo1->Lines->Add("for destination = " + IntToStr(dest) + ", the shortest dist = " + IntToStr(dist[dest])) ;
		Form1->Memo1->Lines->Add("the path is : " + path) ;
	}
}


// main function for single-source shortest path
void singleSource(TObject* Sender, int source) {  // modify (calculate) visited, predecessor, dist
	// initialize
	bool* visited = new bool[n] ;
	int* predecessor = new int[n] ;  // to record the predecessor of each node for back-tracking the path
	int* dist = new int[n] ;         // to record the shortest dist
	for (int i = 0; i < n; i++) {
		predecessor[i] = source ;  // default: source
		visited[i] = false ;
		dist[i] = graph[source][i] ;
	}
	visited[source] = true ;

	// the iteration goes from 1, 2, ..., n
	for (int iter = 1; iter < n; iter++) {  // _ is only the loop counter
		// find the unvisited node with min dist
		int node = -1, minDist = INF ;
		for (int i = 1; i < n; i++) {
			if (not visited[i] && dist[i] < minDist) {
				node = i ;
				minDist = dist[i] ;
			}
		}

		// check termination condition
		if (minDist == INF) {
			break ;   // the unconnected node's predecessor would be -1
		}

		// print the tracing info on the string grid
		SSADtracing(Sender, visited, dist, predecessor, iter, node) ;

		// visit this node
		visited[node] = true ;
		for (int i = 0; i < n; i++) {
			if (graph[node][i] == INF) {
				continue ;  // to avoid newDist > INF -> overflow!
			}
			int newDist = dist[node] + graph[node][i] ;
			if (not visited[i] && newDist < dist[i]) {
				dist[i] = newDist ;
                predecessor[i] = node ;
			}
		}
	}

	// print the path on memo
	printSingleSourcePath(Sender, source, visited, dist, predecessor) ;

	// delete the dynamic memory
	delete [] predecessor ;
	delete [] dist ;
	delete [] visited ;
}


// clear the memory of the dynamic graph
void clearDynamic() {
	if (graph) {
		for (int i = 0; i < n; i++) {
			delete [] graph[i] ;
		}
		delete [] graph ;
		graph = nullptr ;
	}
}


// fill in the string grid
void fillStringGrid(TObject *Sender) {
	Form1->StringGrid1->RowCount = n+1 ;  // print the adjacency matrix
	Form1->StringGrid1->ColCount = n+1 ;
	Form1->StringGrid2->RowCount = n ;    // print the trace of SSAD
	Form1->StringGrid2->ColCount = n+3 ;
	Form1->StringGrid3->RowCount = n+1 ;  // print all-pair shortest dist
	Form1->StringGrid3->ColCount = n+1 ;
	Form1->StringGrid4->RowCount = n+1 ;  // print the transitive closure
	Form1->StringGrid4->ColCount = n+1 ;
	Form1->Memo1->Clear() ;
	Form1->Memo2->Clear() ;

	// the title of string grid 1
	for (int i = 1; i <= n; i++) {
		Form1->StringGrid1->Cells[i][0] = IntToStr(i - 1) ;  // the first col: title
		Form1->StringGrid1->Cells[0][i] = IntToStr(i - 1) ;  // the first row: title
	}
	Form1->StringGrid1->Cells[0][0] = "" ;  // empty for the left-top corner

	// fill in the graph on string grid 1 and 3 (empty), 4(empty)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == INF) {  // this edge does not exist
				Form1->StringGrid1->Cells[j + 1][i + 1] = "INF" ;	
			}
			else {
				Form1->StringGrid1->Cells[j + 1][i + 1] = IntToStr(graph[i][j]) ;
			}
			Form1->StringGrid3->Cells[j + 1][i + 1] = "" ;
			Form1->StringGrid4->Cells[j + 1][i + 1] = "" ;
		}
	}

	// print the title (node) of the dp table (all-pair) on string grid 3 and 4 (transitive closure)
	for (int i = 0; i < n; i++) {
		Form1->StringGrid3->Cells[i+1][0] = IntToStr(i) ;
		Form1->StringGrid3->Cells[0][i+1] = IntToStr(i) ;  
		Form1->StringGrid4->Cells[i+1][0] = IntToStr(i) ;
		Form1->StringGrid4->Cells[0][i+1] = IntToStr(i) ;
	}
 
	// print the title (node) of the tracing table of SSAD (string grid 2)
	for (int i = 0; i < n; i++) {
		Form1->StringGrid2->Cells[i][0] = IntToStr(i) ;
	}
	Form1->StringGrid2->Cells[n][0] = "node" ;
	Form1->StringGrid2->Cells[n+1][0] = "dist" ;
	Form1->StringGrid2->Cells[n+2][0] = "pred" ;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n+3; j++) {
			Form1->StringGrid2->Cells[j][i] = "" ;
		}
	}
}


// button for reading the graph from txt.
void __fastcall TForm1::Button1Click(TObject *Sender) {
	clearDynamic() ;

    // load the txt file
	OpenDialog1->Filter = "Text Files (*.txt)|*.txt" ;  // just show .txt file
	if (!OpenDialog1->Execute()) {
		return ;
	}
	UnicodeString fileName = OpenDialog1->FileName ;
	std::wstring wFileName(fileName.c_str()) ;
	std::wifstream file(wFileName);
	if (!file.is_open()) {
		ShowMessage("Fail to open the file") ;
		return ;
	}

	// initialize the graph
	file >> n ;
	graph = new int*[n] ;
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n] ;
		for (int j = 0; j < n; j++) {
			file >> graph[i][j] ;
			if (graph[i][j] == -1) {  // not connected
				graph[i][j] = INF ;
			}
		}
	}
	fillStringGrid(Sender) ;
	PageControl1->ActivePage = TabSheet1 ;
}
//---------------------------------------------------------------------------
// button for single source to all destinations
void __fastcall TForm1::Button3Click(TObject *Sender) {
	int source = -1 ;
	if (not TryStrToInt(Edit3->Text, source)) {
		ShowMessage("please enter integer source.") ;
		return ;
	}
	if (source < 0 || source >= n) {
		ShowMessage("0 <= source < the number of vertices.") ;
		return ;
	}
	singleSource(Sender, source) ;
	PageControl1->ActivePage = TabSheet2 ;
}
//---------------------------------------------------------------------------
// button for random graph generation
void __fastcall TForm1::Button2Click(TObject *Sender) {
	clearDynamic() ;
	int range, threshold ;
	if (not TryStrToInt(Edit1->Text, n) || not TryStrToInt(Edit2->Text, range) || not TryStrToInt(Edit4->Text, threshold)) {
		ShowMessage("please enter integer n, range, threshold.") ;
		return ;
	}
	if (n <= 0 || range <= 0 || threshold <= 0) {
		ShowMessage("please enter n, range, threshold > 0") ;
		return ;
	}

	// generation
	graph = new int*[n] ;
	if (RadioButton1->Checked) {  // directed
		for (int i = 0; i < n; i++) {
			graph[i] = new int[n] ;
			for (int j = 0; j < n; j++) {
				graph[i][j] = 0 ;
				if (i != j) {
					int num = rand() % range + 1 ;  // 1 to range
					if (num > threshold) {   // not connected
						graph[i][j] = INF ;   
					}
					else {  
						graph[i][j] = num ;
					}
				}
			}
		}
	}

	else if (RadioButton2->Checked) {  // undirected
		for (int i = 0; i < n; i++) {
			graph[i] = new int[n] ;
			for (int j = 0; j < n; j++) {
				graph[i][j] = 0 ;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int num = rand() % range + 1 ;  // 1 to range
				if (num > threshold) {   // not connected
					graph[i][j] = INF ;   
				}
				else {  
					graph[i][j] = num ;
				}
				graph[j][i] = graph[i][j] ;  // symmetric
			}
		}
	}

	fillStringGrid(Sender) ;
	PageControl1->ActivePage = TabSheet1 ;
}
//---------------------------------------------------------------------------
// print DP table
void printDPtable(TObject* Sender, int** dp) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == INF) {
				Form1->StringGrid3->Cells[j+1][i+1] = "INF" ; 
			}
			else {
				Form1->StringGrid3->Cells[j+1][i+1] = IntToStr(dp[i][j]) ;
			}
		}
	}
	Form1->PageControl1->ActivePage = Form1->TabSheet4 ;
}


// find the all pair shortest dist (and record the pred2D)
void findAllPair(TObject* Sender, int** dp, int** pred2D) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[i][k] == INF || dp[k][j] == INF) {
					continue ;  // avoid overflow
				}
				int dist = dp[i][k] + dp[k][j] ;
				if (dist < dp[i][j]) {
					dp[i][j] = dist ;
					pred2D[i][j] = pred2D[k][j] ; // source = i, the pred of j = source = k, the pred of j
				}
			}
		}
		if (Form1->CheckBox1->Checked) {
			printDPtable(Sender, dp) ;
			ShowMessage("iteration (through) " + IntToStr(k)) ;
		}
	}
}


// print the all-pair path
void allPairPath(TObject* Sender, int** dp, int** pred2D) {
	Form1->Memo2->Clear() ;
	for (int source = 0; source < n; source++) {
		for (int dest = 0; dest < n; dest++) {
			Form1->Memo2->Lines->Add("") ;
			if (dp[source][dest] == INF) {
				Form1->Memo2->Lines->Add("for" + IntToStr(source) + "-" + IntToStr(dest) + ", No path!") ;    
			}
			else if (source == dest) {
				Form1->Memo2->Lines->Add("for" + IntToStr(source) + "-" + IntToStr(dest) + ", the shortest dist = 0") ;     
				Form1->Memo2->Lines->Add("the path is : " + IntToStr(source)) ;
			}
			else {  // general case		
				UnicodeString path = IntToStr(dest) ;
				int node = dest ;
				while (pred2D[source][node] != node) {  // not reach the source
					int prev = pred2D[source][node] ;
					path = IntToStr(prev) + " -> [" + IntToStr(graph[prev][node]) + "] -> " + path ;
					node = prev ;
				}
				Form1->Memo2->Lines->Add("for" + IntToStr(source) + "-" + IntToStr(dest) + ", the shortest dist = " + IntToStr(dp[source][dest])) ;
				Form1->Memo2->Lines->Add("the path is : " + path) ;
			}
		}
	}
}


// button for all pairs shortest path
void __fastcall TForm1::Button4Click(TObject *Sender) {
	// initialize the dp table  
	int** dp = new int*[n] ;  // for dynamic programming (all pair)
	for (int i = 0; i < n; i++) {
		dp[i] = new int[n] ;
		for (int j = 0; j < n; j++) {
			dp[i][j] = graph[i][j] ;
		}
	}

	int** pred2D = new int*[n] ;  // predecessor in all pair
	for (int i = 0; i < n; i++) {
		pred2D[i] = new int[n] ;
		for (int j = 0; j < n; j++) {
			pred2D[i][j] = i ;  // default source: i (from i to j)
		}
	}
	
	findAllPair(Sender, dp, pred2D) ;
	printDPtable(Sender, dp) ;

	// print the path
	allPairPath(Sender, dp, pred2D) ;

	// delete the memory
	for (int i = 0; i < n; i++) {
		delete [] dp[i] ;
	}
	delete [] dp ;        
	for (int i = 0; i < n; i++) {
		delete [] pred2D[i] ;
	}
	delete [] pred2D ;
}
//---------------------------------------------------------------------------
void DFS(TObject* Sender, int i, int j, bool* visited) {  // source = i, current at j
	for (int k = 0; k < n; k++) {
		if (not visited[k] && graph[j][k] != INF) {  
			visited[k] = true ;
			Form1->StringGrid4->Cells[k+1][i+1] = "1" ;  // i is connected to k
			DFS(Sender, i, k, visited);
        }
	}
}


bool symmetric() {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (graph[i][j] != graph[j][i]) {
				return false ;
			}
		}
	}
	return true ;
}


// button for transitive closure
void __fastcall TForm1::Button5Click(TObject *Sender) {

	if (not symmetric()) {   // directed: by the method similar to shortest path
		// initialize the dp table  
		bool** dp = new bool*[n] ;  // for dynamic programming (all pair)
		for (int i = 0; i < n; i++) {
			dp[i] = new bool[n] ;
			for (int j = 0; j < n; j++) {
				dp[i][j] = (graph[i][j] != INF) ;  // != INF: 1, == INF: 0
			}
		}

		// generate the all-pair dp table
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]) ;
				}
			}
		}
	
		// print the transitive closure
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (not dp[i][j]) { // not connected
					Form1->StringGrid4->Cells[j+1][i+1] = "0" ;	
				}
				else { // connected
					Form1->StringGrid4->Cells[j+1][i+1] = "1" ;
				}
			}
		}
		
		// delete the memory
		for (int i = 0; i < n; i++) {
			delete [] dp[i] ;
		}
		delete [] dp ;         
	}

	else {  // undirected: by DFS for all nodes
		bool* visited = new bool[n] ;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {  // reset visited
				visited[j] = false ;
				Form1->StringGrid4->Cells[j+1][i+1] = "0" ;  // initialize as 0
			}
			DFS(Sender, i, i, visited) ;  // source = i, current at i	
		}


		delete [] visited ;
    }
	
	Form1->PageControl1->ActivePage = Form1->TabSheet7 ;
}
//---------------------------------------------------------------------------

