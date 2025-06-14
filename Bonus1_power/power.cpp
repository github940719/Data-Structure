//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "power.h"
#include <time.h>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <fstream>  // read the file
#include <sstream>  // get data from the file
using namespace std;
TForm1 *Form1 ;


long long int recursion (int x, int n) {  // x^n with naive recursion
    if (n == 0) {
        return 1 ;
    }
    return x * recursion(x, n-1) ;
}


long long int iteration(int x, int n) {  // x^n with naive iteration
    long long int ans = 1 ;
    for (int i = 0; i < n; i++) {
        ans *= x ;
    }
    return ans ;
}


long long int fastPower(long long int x, int n) {  // x^n with fast power
	long long int ans = 1 ;
	while (n) {  // n != 0
        if (n % 2) {  // n is odd
			ans *= x ;
        }
        n /= 2 ;
		x *= x ;
    }
	return ans ;
}


long long int fastPowerBitwise(long long int x, int n) {  // x^n with fast power and bitwise operator
	long long int ans = 1 ;
    while (n) {  // n != 0
        if (n & 1) {  // n is odd
			ans *= x ;
        }
        n >>= 1 ;  // n /= 2 (shift right)
		x *= x ;
    }
    return ans ;
}


int* generateRandomCoef(int n, int range) {
	int* coef = new int[n+1] ;
	for (int i = 0; i <= n; i++) {
		coef[i] = rand() % (2 * range + 1) - range - 1 ;   // -range ~ range (included)
	}
	return coef ;
}


long long int naivePolynomial(int x, int n, int* coef) {  // polynomial with naive iterataion
    long long int ans = coef[0], power = x ;
    for (int i = 1; i <= n; i++) {
        ans += (coef[i] * power) ;
        power *= x ;
    }
    return ans ;
}


long long int hornerPolynomial(int x, int n, int* coef) {  // polynomial with horner's method

    // e.g. P(x, n = 4) = a0 + x {a1 + x [a2 + x (a3 + x * a4)]}
    long long int ans = coef[n] ;  // highest coefficient
    for (int i = n-1; i >= 0; i--) {  // from high to low
        ans *= x ;
        ans += coef[i] ;
    }
    return ans ;
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {}
//---------------------------------------------------------------------------

// test algorithm of x^n
void testAlgorithm(const UnicodeString& algorithm, int x, int n, int repetition, int decimal, TMemo* Memo1) {
	clock_t tBegin, tEnd ;
	long long int ans = 0 ;

	// call the corresponding algorithm
	if (algorithm == "recursion") {
		tBegin = clock() ;
		for (int i = 0; i < repetition; i++) {
			ans = recursion(x, n) ;
		}
		tEnd = clock() ;
	}

	else if (algorithm == "iteration") {
		tBegin = clock() ;
		for (int i = 0; i < repetition; i++) {
			ans = iteration(x, n) ;
		}
		tEnd = clock() ;
	}

	else if (algorithm == "fastPower") {
		tBegin = clock() ;
		for (int i = 0; i < repetition; i++) { {
			ans = fastPower(x, n) ;
		}
		tEnd = clock() ;
	}
	}
	else {
		tBegin = clock() ;
		for (int i = 0; i < repetition; i++) {
            ans = fastPowerBitwise(x, n) ;
		}
		tEnd = clock() ;
	}

    // output the result
	float sec = (float)(tEnd - tBegin) / CLOCKS_PER_SEC ;
	Memo1->Lines->Add("by " + algorithm + ", the ans = " + IntToStr(ans)) ;
	Memo1->Lines->Add("CPU time (sec) = " + FloatToStrF(sec, ffFixed, 10, decimal)) ;
	Memo1->Lines->Add("") ;
}


// test polynomial algorithm
void testPolynomial(const UnicodeString& algorithm, int x, int n, int* coef, int repetition, int decimal, TMemo* Memo) {
	clock_t tBegin, tEnd ;
	long long int ans = 0 ;

	// call the corresponding algorithm
	if (algorithm == "naive") {
		tBegin = clock() ;
		for (int i = 0; i < repetition; i++) {
			ans = naivePolynomial(x, n, coef) ;
		}
		tEnd = clock() ;
	}

	else {
		tBegin = clock() ;
		for (int i = 0; i < repetition; i++) {
			ans = hornerPolynomial(x, n, coef) ;
		}
		tEnd = clock() ;
    }

    // output the result
	float sec = (float)(tEnd - tBegin) / CLOCKS_PER_SEC ;
	Memo->Lines->Add("by " + algorithm + ", the ans = " + IntToStr(ans)) ;
	Memo->Lines->Add("CPU time (sec) = " + FloatToStrF(sec, ffFixed, 10, decimal)) ;
	Memo->Lines->Add("") ;
}


void outputPolynomial (int x, int n, int repetition, int* coef, int decimal, TMemo* Memo) { // output the polynomial
	String poly ;
	for (int i = n; i >= 1; i--) {
		if (coef[i] > 0) {  // positive
			poly += ("+" + IntToStr(coef[i])) ;
		}
		else if (coef[i] < 0) {  // negative
			poly += ("-" + IntToStr(-coef[i])) ;
		}
		// no need to output coef[i] = 0
		poly += ("*" + IntToStr(x) + "^" + IntToStr(i) + " ") ;
	}

	// constant term
	if (coef[0] > 0) {
		poly += ("+" + IntToStr(coef[0])) ;
	}
	else {
		poly += ("-" + IntToStr(-coef[0])) ;
	}

	Memo->Lines->Add(poly) ;
	Memo->Lines->Add("") ;

	// apply the two algorithms to solve the polynomial
	testPolynomial("naive", x, n, coef, repetition, decimal, Memo) ;
	testPolynomial("horner", x, n, coef, repetition, decimal, Memo) ;
}


// button for calculating x^n
void __fastcall TForm1::Button1Click(TObject *Sender) {
	int x, n, repetition, decimal ;
	Memo1->Clear() ;

	// check number
	if (!TryStrToInt(EditN->Text, n) ||
		!TryStrToInt(EditX->Text, x) ||
		!TryStrToInt(EditRepetition->Text, repetition) ||
		!TryStrToInt(EditDecimal->Text, decimal)) {  // fail to convert
		Memo1->Lines->Add("please type integer n, x, and repetition!") ;
		return ;
	}

	// check positive
	if (n < 0 || repetition < 1 || decimal < 1) {
		Memo1->Lines->Add("please type non-negative n and positive repetition / decimal!") ;
		return ;
	}

	// test 4 different algorithm
	Memo1->Lines->Add(IntToStr(x) + " ^ " + IntToStr(n) + " = ") ;
	if (CheckBoxRecursion->Checked) {
		testAlgorithm("recursion", x, n, repetition, decimal, Memo1) ;
	}
	if (CheckBoxIteration->Checked) {
		testAlgorithm("iteration", x, n, repetition, decimal, Memo1) ;
	}
	if (CheckBoxFastPower->Checked) {
		testAlgorithm("fastPower", x, n, repetition, decimal, Memo1) ;
	}
	if (CheckBoxBitwise->Checked) {
		testAlgorithm("fastPowerBitwise", x, n, repetition, decimal, Memo1) ;
	}
}
//---------------------------------------------------------------------------

// button for polynomial
void __fastcall TForm1::ButtonCalRanClick(TObject *Sender) {
	int x_max, n, repetition, decimal, range ;
	Memo2->Clear() ;

	// check number
	if (!TryStrToInt(EditN2->Text, n) ||
		!TryStrToInt(EditX2->Text, x_max) ||
		!TryStrToInt(EditRepetition2->Text, repetition) ||
		!TryStrToInt(EditDecimal2->Text, decimal) ||
		!TryStrToInt(EditRange->Text, range)) {  // fail to convert
		Memo2->Lines->Add("please type integer n, max_x, range, and repetition!") ;
		return ;
	}

	// check positive
	if (x_max < 0 || repetition < 1 || decimal < 1 || range < 0) {
		Memo2->Lines->Add("please type non-negative x_max, n and positive repetition / decimal / range!") ;
		return ;
	}

	// generate coef
	int* coef = generateRandomCoef(n, range) ;

	// output the polynomial and calculate the ans
	for (int x = 0; x <= x_max; x++) {  // x from 0 to x_max
		outputPolynomial(x, n, repetition, coef, decimal, Memo2) ;
        Memo2->Lines->Add("") ;
	}

	// delete coef
	delete [] coef ;
}
//---------------------------------------------------------------------------

// button for reading txt. to get coef
void __fastcall TForm1::ButtonTxtClick(TObject *Sender) {
	// check number
	int max_x, repetition, decimal ;
	if (!TryStrToInt(EditX2->Text, max_x) ||
		!TryStrToInt(EditRepetition2->Text, repetition) ||
		!TryStrToInt(EditDecimal2->Text, decimal)) {  // fail to convert
		Memo2->Lines->Add("please type integer n, max_x, range, and repetition!") ;
		return ;
	}

	// check positive
	if (max_x < 0 || repetition < 1 || decimal < 1) {
		Memo2->Lines->Add("please type non-negative max_x and positive repetition / decimal!") ;
		return ;
	}

	// read txt. to get coef and n
    OpenDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
	OpenDialog1->FilterIndex = 1;


	if (OpenDialog1->Execute()) {

		// get file path
		string filePath = AnsiString(OpenDialog1->FileName).c_str() ;

		// open the file
		ifstream file(filePath) ;
		if (!file.is_open()) {
			ShowMessage("the file cannot be opened�I") ;
            return ;
        }

		// calculate n (according to the number of lines)
		int n = -1 ;
		string line ;
        while (std::getline(file, line)) {
			n++ ;
        }

		// dynamically allocate the memory for coef
        int* coef = new int[n+1];

		// read the coef
        file.clear() ;
		file.seekg(0, std::ios::beg) ;  // remove the reader to the front of the file
		int index = 0 ;
		while (getline(file, line)) {
			stringstream ss(line) ;
			ss >> coef[index] ;
			index++ ;
		}

		// close the file
		file.close() ;
		for (int x = 0; x < max_x; x++) {
			outputPolynomial(x, n, repetition, coef, decimal, Memo2) ;
            Memo2->Lines->Add("") ;
		}
		delete[] coef ;
	}
}
//---------------------------------------------------------------------------
