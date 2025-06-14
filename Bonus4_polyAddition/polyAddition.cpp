//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "polyAddition.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


class Node {
private:
	int coef ;  // coefficient
	int expo ;  // exponent
	Node* next ;
	friend class List ;  // so that class list can modify next
    friend String add() ;
public:
	Node(int coef, int expo) : coef(coef), expo(expo), next(nullptr) {}
	Node(int coef, int expo, Node* next) : coef(coef), expo(expo), next(next) {}
} ;


class List {
private:
	Node* head ;  // empty head
	Node* last ;  // to make the time complexity of insertLast O(1)
    friend String add() ;

public:
	List() {
		head = new Node(0, -1) ;
		head->next = head ;
		last = head ;
	}

	void deleteAll() {   // re-run (clear)
		Node* node = head->next ;
		while (node != head) {  // not yet
			Node* temp = node ;
			node = node->next ;
			delete temp ;
		}
		head->next = head ;
		last = head ;
	}

	String print() {
		if (head->next == head) {
			return " 0" ;  // no term yet
		}

		String poly ;
		for (Node* n = head->next; n != head; n = n->next) {
			if (n->coef > 0) {
				poly += " + " ;
			}
			else {
				poly += " - " ;
			}

			if (abs(n->coef) != 1) {  // print x^5 instead of 1x^5
				poly += (IntToStr(abs(n->coef))) ;
			}
			else if (n->expo == 0) {  // coef == 1 and expo == 0 (constant 1)
                poly += "1" ;
			}

			if (n->expo > 1) {
				poly += ("x^" + IntToStr(n->expo)) ;
			}
			else if (n->expo == 1) {
				poly += ("x") ;   // print x instead of x^1
			}
			// constant : do not print x^0
		}

        // remove the beginning +
		if (poly.SubString(1, 2) == " +") {
			poly = poly.SubString(3, poly.Length());
		}

		return poly ;
    }

	void insert(int coef, int expo) {   // coef != 0, expo >= 0, for manually add terms
		Node* prev = head ;
		Node* curr = head->next ;

		while (curr != head && curr->expo > expo) {  // go to next term
			prev = curr ;
			curr = curr->next ;
		}

		if (curr->expo == expo) {   // this term has already existed
			ShowMessage("expo = " + IntToStr(expo) + " has already existed, so the insertion failed!") ;
		}
		else {
			Node* node = new Node(coef, expo, curr) ;
			prev->next = node ;
			if (prev == last) {
				last = node ;  // this is the last term
            }
		}
	}

	void insertLast(int coef, int expo) {  // for random add term, C = A + B, since expo is guaranteed to be from high to low
		last->next = new Node(coef, expo, head) ;
        last = last->next ;
    }
} ;


// global variable
TForm1 *Form1;
List* polyA ;
List* polyB ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {
	Memo1->Clear() ;
	polyA = new List ;
    polyB = new List ;
}
//---------------------------------------------------------------------------
// add a term of poly A
void __fastcall TForm1::Button1Click(TObject *Sender) {
	int coef, expo ;   // input coef and expo
	if (!TryStrToInt(Edit1->Text, coef) || !TryStrToInt(Edit2->Text, expo)) {
		ShowMessage("please enter integer!") ;
		return ;
	}
	if (expo < 0) {
		ShowMessage("expo should >= 0!") ;
		return ;
	}
	if (coef == 0) {
		ShowMessage("coef should not = 0!") ;
		return ;
	}
	polyA->insert(coef, expo) ;
	Memo1->Lines->Add("A: " + polyA->print()) ;
	Memo1->Lines->Add("B: " + polyB->print()) ;
	Memo1->Lines->Add("") ;
}
//---------------------------------------------------------------------------
// add a term of poly B
void __fastcall TForm1::Button2Click(TObject *Sender) {
	int coef, expo ;   // input coef and expo
	if (!TryStrToInt(Edit1->Text, coef) || !TryStrToInt(Edit2->Text, expo)) {
		ShowMessage("please enter integer!") ;
		return ;
	}
	if (expo < 0) {
		ShowMessage("expo should >= 0!") ;
		return ;
	}
	if (coef == 0) {
		ShowMessage("coef should not = 0!") ;
		return ;
	}
	polyB->insert(coef, expo) ;
	Memo1->Lines->Add("A: " + polyA->print()) ;
	Memo1->Lines->Add("B: " + polyB->print()) ;
	Memo1->Lines->Add("") ;
}
//---------------------------------------------------------------------------
// re-run
void __fastcall TForm1::Button5Click(TObject *Sender) {
	polyA->deleteAll() ;
	polyB->deleteAll() ;
	Memo1->Clear() ;
}
//---------------------------------------------------------------------------
// randomly generate coef from expo = maxExpo to 0
void randomGenerate(List* poly, int maxExpo, int range) {
	for (int expo = maxExpo; expo >= 0; expo--) {
		int coef = rand() % (range * 2 + 2) - range;  // [-range, +range]
		if (coef) {  // insert only when coef != 0
			poly->insertLast(coef, expo) ;
		}
	}
}

// randomly generate terms for polyA and polyB
void __fastcall TForm1::Button3Click(TObject *Sender) {
	int maxExpo, range ;   // input maxExpo and range
	if (!TryStrToInt(Edit3->Text, maxExpo) || !TryStrToInt(Edit4->Text, range)) {
		ShowMessage("please enter integer!") ;
		return ;
	}
	if (maxExpo < 0) {
		ShowMessage("max expo should >= 0!") ;
		return ;
	}
	if (range <= 0) {
		ShowMessage("range should > 0!") ;
		return ;
	}
	polyA->deleteAll() ;
	polyB->deleteAll() ;
	randomGenerate(polyA, maxExpo, range) ;
	randomGenerate(polyB, maxExpo, range) ;
	Memo1->Lines->Add("A: " + polyA->print()) ;
	Memo1->Lines->Add("B: " + polyB->print()) ;
	Memo1->Lines->Add("") ;
}
//---------------------------------------------------------------------------
// C = A + B
String add() {
	List* polyC = new List ;
	Node* p = polyA->head->next, *q = polyB->head->next ;
	while (p != polyA->head || q != polyB->head) {
		int coef = 0, expo = 0 ;

		if (p->expo > q->expo) {
			coef = p->coef ;
			expo = p->expo ;
			p = p->next ;
		}
		else if (p->expo < q->expo) {
			coef = q->coef ;
			expo = q->expo ;
			q = q->next ;
		}
		else {
			if (p->coef + q->coef) {  // if expo are the same && coef != 0
				coef = p->coef + q->coef ;
				expo = p->expo ;
            }
			p = p->next ;
			q = q->next ;
		}

		if (coef) {
			polyC->insertLast(coef, expo) ;
		}
	}

	String ans = polyC->print() ;
    polyC->deleteAll() ;
	return ans ;
}

// button for C = A + B
void __fastcall TForm1::Button4Click(TObject *Sender) {
	Memo1->Lines->Add("C: " + add()) ;
	Memo1->Lines->Add("") ;
}
//---------------------------------------------------------------------------

