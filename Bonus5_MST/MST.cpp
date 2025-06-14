//---------------------------------------------------------------------------
#pragma hdrstop
#include "MST.h"
#include <climits>
#include <vcl.h>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int INF =  INT_MAX ;

struct edge {
	int x ;
	int y ;
	int cost ;
    edge(int x, int y, int c) : x(x), y(y), cost(c) {}
};

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {
    // set the min / max of the trackbar (edge density)
	TrackBar1->Min = 1 ;
	TrackBar1->Max = 100 ;
	TrackBar2->Min = 1 ;
	TrackBar2->Max = 100 ;
}
//---------------------------------------------------------------------------
// generate the graph
int generate(int n, int range, int** distMatrix, edge** edgeSet, float density) {
    int edgeCnt = 0 ;
	for (int i = 0; i < n; i++) {
		distMatrix[i] = new int[n] ;

		// j < i
		for (int j = 0; j < i; j++) distMatrix[i][j] = distMatrix[j][i] ;

		// j = i
		distMatrix[i][i] = 0 ;

		// j > i
		for (int j = i+1; j < n; j++) {
			distMatrix[i][j] = rand() % range ;
			if (distMatrix[i][j] > (range * density)) distMatrix[i][j] = INF ;  // not connected
			else edgeSet[edgeCnt++] = new edge(i, j, distMatrix[i][j]) ;
		}
	}
    return edgeCnt ;
}


// draw the distMatrix
void draw(int n, int** distMatrix, TObject* Sender) {
	Form1->StringGrid1->RowCount = n + 1 ;
	Form1->StringGrid1->ColCount = n + 1 ;
	Form1->StringGrid1->Cells[0][0] = "" ;

	// title
    for (int i = 0; i < n; i++) {
		Form1->StringGrid1->Cells[i + 1][0] = IntToStr(i) ;
		Form1->StringGrid1->Cells[0][i + 1] = IntToStr(i) ;
    }

	// write the distMatrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (distMatrix[i][j] == INF) Form1->StringGrid1->Cells[j + 1][i + 1] = "��" ;
			else Form1->StringGrid1->Cells[j + 1][i + 1] = IntToStr(distMatrix[i][j]) ;
		}
	}

    Form1->PageControl1->ActivePage = Form1->TabSheet2 ;
}


void swap(int& a, int& b) {
	int temp = a ;
	a = b ;
	b = temp ;
}


int find(int x, int* parent) {
	if (parent[x] == x) return x ;
	parent[x] = find(parent[x], parent) ;
	return parent[x] ;
}


void Union(int x, int y, int* parent) {
	parent[x] = y ;
}


void goDown(int* heap, int i, int n, edge** edgeSet) {
	while (i <= n / 2) {
		int j = 2*i ;
		if (j+1 <= n && edgeSet[heap[j+1]]->cost < edgeSet[heap[j]]->cost) {
			j++ ;	  
		}
		if (edgeSet[heap[i]]->cost < edgeSet[heap[j]]->cost) {
			break ;
		}
		else {
			swap(heap[i], heap[j]) ;
			i = j ;
		}
	}
}


// kruskal (return MST -> chosen edge's idx)
double kruskal(edge** edgeSet, int edgeCnt, int n, TObject* Sender = nullptr) {
	double start = clock() ;
	
	int* MST = new int[n-1] ;  // store the index of the chosen edges
	int* heap = new int[edgeCnt+1] ;  // store the index, min heap
	int* parent = new int[n] ;
	for (int i = 0; i < n; i++) {
		parent[i] = i ;
	}
	bool MSTexist = true ;
	int cost = 0 ;

	// build heap
	for (int i = 1; i <= edgeCnt; i++) {
		heap[i] = i-1 ;  // index of the edge
	}
	for (int k = edgeCnt / 2; k > 0; k--) {  // from the last parent node
		goDown(heap, k, edgeCnt, edgeSet) ;
	}

	int chosenCnt = 0 ;
	while (chosenCnt < n-1) {
	
		if (edgeCnt == 0) {
			MSTexist = false ;
			break ;	  
		}	

		// get min and rebalance
		int idx = heap[1] ;
		heap[1] = heap[edgeCnt--] ;
		goDown(heap, 1, edgeCnt, edgeSet) ;

		int x = find(edgeSet[idx]->x, parent), y =  find(edgeSet[idx]->y, parent) ;
		if (x != y) {  
			// not form a cycle
			cost += edgeSet[idx]->cost ;
			MST[chosenCnt++] = idx ;
			Union(x, y, parent) ;   
		}
	}


	// print the MST on the memo
	Form1->Memo1->Lines->Add("|V| = " + IntToStr(n)) ;
	if (Sender) {
		if (MSTexist) {
			Form1->Memo1->Lines->Add("Kruskal's MST cost = " + IntToStr(cost) + ", the chosen edges are as follow.") ;
			for (int i = 0; i < n-1; i++) Form1->Memo1->Lines->Add("edge" + IntToStr(i+1) + " (" + IntToStr(edgeSet[MST[i]]->x) + ", " + IntToStr(edgeSet[MST[i]]->y) + "), weight = " + IntToStr(edgeSet[MST[i]]->cost)) ;
		}
		else {
			Form1->Memo1->Lines->Add("Kruskal's MST: not exist") ;
		}
	}

	delete [] MST ;
	delete [] heap ;
	delete [] parent ;

	double end = clock() ;
	double time = double(end - start) / CLOCKS_PER_SEC ;
	Form1->Memo1->Lines->Add("executime time(sec) = " + FloatToStrF(time, ffFixed, 10, 10)) ;
	Form1->Memo1->Lines->Add("") ;
	return time ;	
}


// prim (return pred-> chosen edge)
double prim(int** distMatrix, int n, TObject* Sender = nullptr) {
	double start = clock() ;
	
	// initialize
	bool* visited = new bool[n] ;
	bool MSTexist = true ;
	int cost = 0 ;
	int* pred = new int[n] ;  // to record the predecessor of each node for back-tracking the path
	int* dist = new int[n] ;  // to record the temp dist
	for (int i = 0; i < n; i++) {
		pred[i] = 0 ;  // default: source = 0
		visited[i] = false ;
		dist[i] = distMatrix[0][i] ;
	}
	visited[0] = true ;

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
			MSTexist = false ;
			break ;
		}

		// visit this node
		visited[node] = true ;
		cost += minDist ;
		for (int i = 0; i < n; i++) {
			if (distMatrix[node][i] != INF && not visited[i] && distMatrix[node][i] < dist[i]) {
				dist[i] = distMatrix[node][i] ;
                pred[i] = node ;
			}
		}
	}

	// print the MST on the memo
	Form1->Memo1->Lines->Add("|V| = " + IntToStr(n)) ;
	if (Sender) {
		if (MSTexist) {
			Form1->Memo1->Lines->Add("Prim's MST cost = " + IntToStr(cost) + ", the chosen edges are as follow.") ;
			for (int i = 1; i < n; i++) Form1->Memo1->Lines->Add("edge" + IntToStr(i) + " (" + IntToStr(pred[i]) + ", " + IntToStr(i) + "), weight = " + IntToStr(distMatrix[pred[i]][i])) ;
		}
		else {
			Form1->Memo1->Lines->Add("Prim's MST: not exist") ;
		}
	}

	// delete the dynamic memory
	delete [] dist ;
	delete [] visited ;
	delete [] pred ;

	double end = clock() ;
	double time = double(end - start) / CLOCKS_PER_SEC ;
	Form1->Memo1->Lines->Add("executime time(sec) = " + FloatToStrF(time, ffFixed, 10, 10)) ;
    Form1->Memo1->Lines->Add("") ;
	return time ;
}


// button for running once
void __fastcall TForm1::Button1Click(TObject *Sender) {
	
	// deal with input
	Form1->Memo1->Clear() ;
	int n, range ;
	if (!TryStrToInt(Edit1->Text, n) || !TryStrToInt(Edit5->Text, range)) {
		ShowMessage("please enter interger |V|.") ;
		return ;
	}
	if (n <= 1 || range <= 1) {
		ShowMessage("|V|, range should > 1.") ;
        return ;
	}

	// build the dist matrix (for Prim) and the edge set (for kruskal)
	int** distMatrix = new int*[n] ;
	edge** edgeSet = new edge*[n*n] ;
	int edgeCnt = generate(n, range, distMatrix, edgeSet, TrackBar1->Position / 100.0) ;

	// draw the distMatrix
    draw(n, distMatrix, Sender) ;

	// kruskal
	int* MST ;
	if (CheckBox1->Checked) kruskal(edgeSet, edgeCnt, n, Sender) ;

	// prim
	int* pred ;
	if (CheckBox2->Checked) prim(distMatrix, n, Sender) ;

    // delete memory
	for (int i = 0; i < n; i++) delete [] distMatrix[i] ;
	delete [] distMatrix ;
	for (int i = 0; i < edgeCnt; i++) delete edgeSet[i] ;
	delete [] edgeSet ;
}


//---------------------------------------------------------------------------
// button for running multiple times and draw the chart
void __fastcall TForm1::Button2Click(TObject *Sender) {
	// deal with input
	Form1->Memo1->Clear() ;
	int startN, step, rep, range ;
	if (!TryStrToInt(Edit2->Text, startN) ||
		!TryStrToInt(Edit3->Text, step) ||
		!TryStrToInt(Edit4->Text, rep) ||
		!TryStrToInt(Edit6->Text, range)) {
		ShowMessage("please enter interger.") ;
		return ;
	}
	if (startN <= 1 || step <= 1 || rep <= 1 || range <= 1) {
		ShowMessage("input should > 1.") ;
		return ;
	}

	// run the kruskal and prim
	Form1->PageControl1->ActivePage = Form1->TabSheet2 ;
	double* kruskalTime = new double[rep], *primTime = new double[rep] ;
	for (int r = 0; r < rep; r++) {
		int n = startN + r * step ;

		// build the dist matrix (for Prim) and the edge set (for kruskal)
		int** distMatrix = new int*[n] ;
		edge** edgeSet = new edge*[n*n] ;
		int edgeCnt = generate(n, range, distMatrix, edgeSet, TrackBar2->Position / 100.0) ;

		// running the two algorithms
		kruskalTime[r] = kruskal(edgeSet, edgeCnt, n) ;
		primTime[r] = prim(distMatrix, n) ;

		// delete memory
		for (int i = 0; i < n; i++) delete [] distMatrix[i] ;
		delete [] distMatrix ;
		for (int i = 0; i < edgeCnt; i++) delete edgeSet[i] ;
		delete [] edgeSet ;
	}

	// draw the chart
	Chart1->SeriesList->Clear() ;
	Chart1->Title->Text->Clear();
	TBarSeries* KruskalSeries = new TBarSeries(Chart1) ;
	TBarSeries* PrimSeries = new TBarSeries(Chart1) ;
	KruskalSeries->Title = "Kruskal" ;
	PrimSeries->Title = "Prim" ;
	Chart1->AddSeries(KruskalSeries) ;
	Chart1->AddSeries(PrimSeries) ;
	Chart1->Title->Text->Add("Kruskal vs Prim Execution Time") ;
	Chart1->LeftAxis->Title->Caption = "Time (sec)" ;
	Chart1->BottomAxis->Title->Caption = "# of node in the graph" ;
	for (int r = 0; r < rep; r++) {
		KruskalSeries->Add(kruskalTime[r], startN + r * step) ;
		PrimSeries->Add(primTime[r], startN + r * step) ;
	}
	KruskalSeries->Marks->Visible = false ;
	PrimSeries->Marks->Visible = false ;
	Form1->PageControl1->ActivePage = Form1->TabSheet3 ;
	delete [] kruskalTime ;
	delete [] primTime ;
}
//---------------------------------------------------------------------------
