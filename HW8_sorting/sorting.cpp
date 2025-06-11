//---------------------------------------------------------------------------

#include <vcl.h>
#include <ctime>
#include <VCLTee.Series.hpp>
#pragma hdrstop

#include "sorting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

// global variable
TForm1 *Form1;
const int ALG = 10 ;  // 10 algorithms
const String algNames[ALG] = {"Selection", "Bubble", "Insertion", "MergeRec", "MergeIter","QuickRec", "QuickIter", "Heap", "Radix", "Counting"} ;
TMemo* memos[11] ;

// swap, call by reference
void swap(int& a, int& b) {
	int temp = a ;
	a = b ;
    b = temp ;
}


// copy the list
void copyList(int* originalArr, int* newArr, int len) {
	for (int i = 0; i < len; i++) {
		newArr[i] = originalArr[i] ;
	}
}


void selectionSort(int* arr, int len) {
	for (int i = 0; i < len-1; i++) {
		int minIdx = i ;  // i is the index of the smallest element
		for (int j = i+1; j < len; j++) {
			if (arr[j] < arr[minIdx]) {  // if smaller, then renew minIdx
				minIdx = j ;
			}
		}
        swap(arr[i], arr[minIdx]) ;  // swap index = i and minIdx
	}
}


void insertionSort(int* arr, int len) {
	for (int i = 1; i < len; i++) {  // insert index = i before to the right place
		int pivot = arr[i] ;
		int idx = i ;
		while (idx > 0 && arr[idx-1] > pivot) {  // pivot is smaller
			arr[idx] = arr[idx-1] ;  // move
			idx-- ;
		}
		arr[idx] = pivot ;
	}
}


void bubbleSort(int* arr, int len) {
	for (int i = len-1; i > 0; i--) {  // after this iteration, idx = i is the largest among before
		for (int j = 0; j < i; j++) {  // let the bubble float to the top from idx = 0
			if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]) ;
			}
		}
	}
}


void merge(int* arr, int* temp, int start1, int end1, int start2, int end2) {
	// the first subarray: idx = start1 to end1
	// the second subarray: idx = start2 to end2

	// deep copy!
	for (int p = start1; p <= end1; p++) {temp[p] = arr[p] ;}
	for (int p = start2; p <= end2; p++) {temp[p] = arr[p] ;}

	int k = start1, i = start1, j = start2 ;
	while (i <= end1 && j <= end2) {
		if (temp[i] <= temp[j]) {
			arr[k++] = temp[i++] ;
		}
		else {
            arr[k++] = temp[j++] ;
        }
	}
	while (i <= end1) {arr[k++] = temp[i++] ;}
	while (j <= end2) {arr[k++] = temp[j++] ;}
}


void mergeSortRecursion(int* arr, int* temp, int left, int right) {
	if (left >= right) {
		return ;  // boundary condition : one element
	}

	int mid = left + (right - left) / 2 ; // to avoid (left + right) / 2 overflow
	mergeSortRecursion(arr, temp, left, mid) ;
	mergeSortRecursion(arr, temp, mid+1, right) ;
	merge(arr, temp, left, mid, mid+1, right) ;
}


void mergeSortIteration(int* arr, int len) {
	int* temp = new int[len] ;
	for (int subLen = 1; subLen < len; subLen *= 2) {  // no need to merge when subLen >= len (boundary condition)
		for (int i = 0; i+subLen < len; i += (2*subLen)) {
			int bound = i+2*subLen-1 ;  // may overflow!
			if (bound >= len) {
                bound = len-1 ;
			}
			merge(arr, temp, i, i+subLen-1, i+subLen, bound) ;
		}
	}
	delete [] temp ;
}


void quickSortRecursion(int* arr, int left, int right) {
	if (left >= right) {
		return ;  // boundary condition : one element
	}

	int i = left + 1, j = right ;
	do {
		while (i <= j && arr[i] <= arr[left]) {i++;}  // find the first i s.t. arr[i] > arr[left]
		while (i <= j && arr[j] >= arr[left]) {j--;}  // find the first j s.t. arr[j] < arr[left]
		if (i < j) swap(arr[i], arr[j]);
	} while (i < j) ;

	if (left < j) {
        swap(arr[left], arr[j]) ;
	}
	quickSortRecursion(arr, left, j-1) ;
    quickSortRecursion(arr, j+1, right) ;
}


struct Node {
	int left ;
	int right ;
	Node* next ;
    Node(int l, int r, Node* n) : left(l), right(r), next(n) {}
};

class Stack {
private:
	Node* head ;
public:
	Stack() : head(nullptr) {}

	void push(int left, int right) {
        head = new Node(left, right, head) ;
	}

	Node* pop() {
		if (!head) {
			ShowMessage("pop from emtpy stack!") ;
            return nullptr ;
		}
		Node* n = head ;
		head = head->next ;
        return n ;
	}

	bool empty() {
        return (head == nullptr) ;
    }
};


void quickSortIteration(int* arr, int len) {
	Stack s ;
	s.push(0, len-1) ;
	while (!s.empty()) {
		Node* n = s.pop() ;
		int left = n->left, right = n->right ;
		delete n ;

        // the below is the same as quickSortRecursion
		int i = left + 1, j = right ;
		do {
			while (i <= j && arr[i] <= arr[left]) {i++;}  // find the first i s.t. arr[i] > arr[left]
			while (i <= j && arr[j] >= arr[left]) {j--;}  // find the first j s.t. arr[j] < arr[left]
			if (i < j) swap(arr[i], arr[j]);
		} while (i < j) ;

		if (left < j) {
			swap(arr[left], arr[j]) ;
		}

		// push into stack (when the number of element < 1 i.e. no need to sort)
		if (j+1 < right) {
			s.push(j+1, right) ;
		}
		if (j-1 > left) {
			s.push(left, j-1) ;
		}
    }
}


void countingSort(int* arr, int len) {
    // find the largest element
	int maxElement = arr[0] ;
	for (int i = 1; i < len; i++) {
		maxElement = (arr[i] > maxElement ? arr[i] : maxElement) ;
	}

	int cap = maxElement+1 ;
	int* C = new int[cap] ;
	for (int i = 0; i < cap; i++) {
		C[i] = 0 ;  // initialize
	}

	for (int i = 0; i < len; i++) {
		C[arr[i]]++ ;  // counting
	}

	for (int i = 1; i < cap; i++) {
        C[i] += C[i-1] ;  // C[i] is the ending idx(not included) of i
	}

	int* temp = new int[len] ;
	copyList(arr, temp, len) ;  // copy the original arr to temp

	for (int i = len-1; i >= 0; i--) {  // maintain stability
        arr[--C[temp[i]]] = temp[i] ;  // write the data to arr
	}

	delete [] C ;
    delete [] temp ;
}


void radixSort(int* arr, int len) {
    // find the largest element
	int maxElement = arr[0] ;
	for (int i = 1; i < len; i++) {
		maxElement = (arr[i] > maxElement ? arr[i] : maxElement) ;
	}

	// find the radix
	int radix = 0 ;
	while (maxElement > 0) {
		maxElement /= 10 ;
        radix++ ;
	}

	int* temp = new int[len] ;  // to deep copy arr

	for (int i = 1, exp = 1; i <= radix; i++, exp *= 10) {
		int C[10] = {0} ;  // initialize
		for (int j = 0; j < len; j++) {
			int digit = (arr[j] / exp) % 10;
			C[digit]++ ;  // counting
		}

		for (int j = 1; j < 10; j++) {
			C[j] += C[j-1] ;  // finishing idx
		}

		copyList(arr, temp, len) ;  // copy the original arr to temp
		for (int j = len-1; j >= 0; j--) {  // to maintain the stability
			int digit = (temp[j] / exp) % 10;
            arr[--C[digit]] = temp[j] ;
		}
	}

    delete [] temp ;
}


void restoreHeap(int* arr, int start, int len) {  // maxHeap
	int i = start ;
	while (2 * i + 1 < len) {
		int j = 2*i+1 ;  // the larger child
		if (j+1 < len && arr[j+1] > arr[j]) {
            j++ ;
		}
		if (arr[j] > arr[i]) {
			swap(arr[j], arr[i]) ;
			i = j ;  // go downward
		}
		else {
            break ;
        }
    }
}


void heapSort(int* arr, int len) {
	for (int i = (len-1) / 2; i >= 0; i--) {  // from the last parent to idx = 0
		restoreHeap(arr, i, len) ;
	}

	for (int tempN = len; tempN > 0; tempN--) {
		swap(arr[0], arr[tempN]) ;  // swap arr[0] (max) and the last (arr[tempN])
		restoreHeap(arr, 0, tempN) ;
	}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {
	memos[0] = Memo1 ;
	memos[1] = Memo2 ;
	memos[2] = Memo3 ;
	memos[3] = Memo4 ;
	memos[4] = Memo5 ;
	memos[5] = Memo6 ;
	memos[6] = Memo7 ;
	memos[7] = Memo8 ;
	memos[8] = Memo9 ;
	memos[9] = Memo10 ;
	memos[10] = Memo11 ;
    for (int i = 0; i < 11; i++)
		memos[i]->Lines->Clear() ;
}
//---------------------------------------------------------------------------


// check whether the sorted arr is correct
bool checkSorted(int* arr, int len) {
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[i-1]) {
			return false ;
		}
	}
	return true ;
}


// run
void runAll(TObject* Sender, int alg, int d, int rep, int** originalArr, int* arr, float* time, float** resultTime, int tempLen) {
	for (int r = 0; r < rep; r++) {
		copyList(originalArr[r], arr, tempLen) ;
		clock_t start, end ;

		if (alg == 0) {
			start = clock() ;
			selectionSort(arr, tempLen) ;
			end = clock() ;
		}

		else if (alg == 1) {
			start = clock() ;
			bubbleSort(arr, tempLen) ;
			end = clock() ;
		}

		else if (alg == 2) {
			start = clock() ;
			insertionSort(arr, tempLen) ;
			end = clock() ;
		}

		else if (alg == 3) {
			start = clock() ;
			int* temp = new int[tempLen] ;
			mergeSortRecursion(arr, temp, 0, tempLen-1) ;
			delete [] temp ;
			end = clock() ;
		}

		else if (alg == 4) {
			start = clock() ;
			mergeSortIteration(arr, tempLen) ;
			end = clock() ;
		}

		else if (alg == 5) {
			start = clock() ;
			quickSortRecursion(arr, 0, tempLen-1) ;
			end = clock() ;
		}

		else if (alg == 6) {
			start = clock() ;
			quickSortIteration(arr, tempLen) ;
			end = clock() ;
		}

		else if (alg == 7) {
			start = clock() ;
			heapSort(arr, tempLen) ;
			end = clock() ;
		}

		else if (alg == 9) {
			start = clock() ;
			countingSort(arr, tempLen) ;
			end = clock() ;
		}

		else if (alg == 8) {
			start = clock() ;
			radixSort(arr, tempLen) ;
			end = clock() ;
		}

		if (!checkSorted(arr, tempLen)) {
			ShowMessage("the sorted result is wrong.") ;
		}
		time[r] = double(end - start) / CLOCKS_PER_SEC ;

	}

	// print on memo
	if (Form1->CheckBox11->Checked) {
		Form1->PageControl1->ActivePageIndex = 1;
		memos[alg+1]->Lines->Add("len = " + IntToStr(tempLen)) ;
		memos[alg+1]->Lines->Add("rep = " + IntToStr(rep-1)) ;
		for (int i = 0; i < tempLen; i++) {
			memos[alg+1]->Lines->Add(IntToStr(arr[i])) ;
		}
		memos[alg+1]->Lines->Add("") ;
	}

	// get average (remove the max and min running time)
	float sum = 0;
	float maxTime = time[0], minTime = time[0];
	for (int i = 0; i < rep; i++) {
		sum += time[i];
		if (time[i] > maxTime) maxTime = time[i] ;
		if (time[i] < minTime) minTime = time[i] ;
	}

	// calculate the time and print on memo1
	float avgTime = (sum - maxTime - minTime) / (rep - 2) ;
	resultTime[alg][d] = avgTime ;
	memos[0]->Lines->Add(algNames[alg] + " avg time (sec) = ") ;
	memos[0]->Lines->Add(FloatToStrF(avgTime, ffFixed, 10, 5)) ;
	memos[0]->Lines->Add("") ;
}


// button for running the chosen algorithms
void __fastcall TForm1::Button1Click(TObject *Sender) {
	for (int i = 0; i < 11; i++) {
        memos[i]->Lines->Clear() ;
	}

	// check input validity
    int len, range, rep, step, dataPoint ;
	if (!TryStrToInt(Edit1->Text, len) ||
		!TryStrToInt(Edit2->Text, range) ||
		!TryStrToInt(Edit3->Text, rep) ||
		!TryStrToInt(Edit4->Text, step) ||
		!TryStrToInt(Edit5->Text, dataPoint)) {
		ShowMessage("please enter integer input.") ;
		return ;
	}

	if (len < 1 || range < 1 || rep < 3 || step < 1 || dataPoint < 1) {
		ShowMessage("please enter positive input (rep >= 3).") ;
        return ;
	}

	// record the running time for each alg for each data point
	float** resultTime = new float*[ALG] ;
	for (int alg = 0; alg < ALG; alg++) {
		resultTime[alg] = new float[dataPoint] ;
		for (int d = 0; d < dataPoint; d++) {
			resultTime[alg][d] = 0 ;  // initialize
		}
	}

	float* time = new float[rep] ;
    bool algUsed[ALG] = {0} ;

	// run the chosen algorithm
	for (int d = 0; d < dataPoint; d++) {

		// random generation for arr
		int tempLen = len + d * step ;
		int** originalArr = new int*[rep] ;  // let all of the algorithms run the same "rep" arr
		for (int r = 0; r < rep; r++) {
			originalArr[r] = new int[tempLen] ;
			for (int i = 0; i < tempLen; i++) {
				originalArr[r][i] = rand() % range ;
			}
		}

		int* arr = new int[tempLen] ;

		for (int i = 0; i < 10; ++i) {
			// dynamically get the pointer of checkbox
			TCheckBox* cb = dynamic_cast<TCheckBox*>(FindComponent("CheckBox" + IntToStr(i + 1)));
			if (cb && cb->Checked) {
				algUsed[i] = true;
				runAll(Sender, i, d, rep, originalArr, arr, time, resultTime, tempLen);
			}
		}

		// delete dynamic memory
		delete [] arr ;
		for (int r = 0; r < rep; r++) {
			delete [] originalArr[r] ;
		}
		delete [] originalArr ;
	}


	// draw the line chart
	Chart1->SeriesList->Clear() ;
	Chart1->View3D = false;
	Chart1->Legend->Visible = true;
	Chart1->Legend->LegendStyle = lsSeries;
	for (int alg = 0; alg < 10; alg++) {
		if (!algUsed[alg]) {
			continue ;  // this alg is not used
		}
		TLineSeries* series = new TLineSeries(Chart1);
		series->Title = algNames[alg];

		for (int d = 0; d < dataPoint; d++) {
			int arraySize = len + d * step;
			series->AddXY(arraySize, resultTime[alg][d]);
		}

		series->LinePen->Width = 3;
		Chart1->AddSeries(series);
	}

	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Sorting Algorithm Execution Time");

	Chart1->BottomAxis->Title->Caption = "Array Size";
	Chart1->LeftAxis->Title->Caption = "Time (sec)";
	Form1->PageControl1->ActivePageIndex = 0;


	delete [] time ;
	for (int alg = 0; alg < ALG; alg++) {
		delete [] resultTime[alg] ;
	}
    delete [] resultTime ;
}
//---------------------------------------------------------------------------
