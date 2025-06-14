//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "linkedList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


// self defined node with single link
class SingleNode {
private:
    int val ;
	SingleNode* next ;
	friend class myStack ;
	friend class SingleList ;
	friend class myQueue ;
public:
	SingleNode(int val) : val(val), next(nullptr) {}
	SingleNode(int val, SingleNode* next) : val(val), next(next) {}
} ;


// self defined singly linked list
class SingleList {
private:
	SingleNode* head ;  // empty head

	void insertAfter(SingleNode* node, int val) {
        /*
            Singlenode* temp = new SingleNode(val) ;
			temp->next = node->next ;
            node->next = temp ;
        */
		node->next = new SingleNode(val, node->next) ;
	}

	SingleNode* searchAndReturnBefore(int target) {  // search and return the node (pointer) before the target node
        SingleNode* temp, *former ;  // "former" is the former node of "temp"
        for (temp = head->next, former = head;
			temp != head && temp->val != target;
            temp = temp->next, former = former->next) {}

		if (temp == head) {  // not found
			// we cannot return head, since the target may be found just after head
			return nullptr ;
		}
		else {
			return former ;
		}
	}

public:
	SingleList() {
        head = new SingleNode(-1) ;  // empty head, curcular list
        head->next = head ;
	}

    void deleteAllElement() {  // delete all node except the empty head
		SingleNode* node = head->next ;
		while (node != head) {  // not yet
			SingleNode* temp = node ;
			node = node->next ;
			delete temp ;
		}
		head->next = head ;
    }

	void traverse(TMemo* memo) {  // print the list in order
		String list = "" ;
		for (SingleNode* temp = head->next; temp != head; temp = temp-> next) {
			list += (IntToStr(temp->val) + "-->") ;
		}
        list += "<" ;
		memo->Lines->Add(list) ;
		memo->Lines->Add("") ;
	}

	void insertHead(int val) {   // insert at header->next
        insertAfter(head, val) ;
    }

	void insertLast(int val) {   // insert at last (and its next is header)
		SingleNode* temp ;  // temp will be the last node
		for (temp = head; temp->next != head; temp = temp->next) {}
		insertAfter(temp, val) ;
	}

	void insertMultipleNodesAtLast(int n, int range) {
		SingleNode* temp ;  // temp will be the last node
		for (temp = head; temp->next != head; temp = temp->next) {}
		for (int i = 0; i < n; i++) {
			insertAfter(temp, rand() % range) ;
			temp = temp->next ;
		}
    }

    SingleNode* search(int target) {    // search and return this node (pointer)
		SingleNode* temp ;
		for (temp = head-> next; temp != head && temp->val != target; temp = temp->next) {}

		if (temp == head) {  // not found
			return nullptr ;
		}
		else {
			return temp ;
		}
	}

	bool findAndInsertAfter(int target, int val) {
		SingleNode* temp = search(target) ;
		if (temp) {   // if found
			insertAfter(temp, val) ;
			return true ;
		}
		return false ;
    }

	bool findAndInsertBefore(int target, int val) {
		SingleNode* former = searchAndReturnBefore(target) ;
		if (former) {   // if found
			insertAfter(former, val) ;
			return true ;
		}
		return false ;
	}

    int findAndDelete(int target) {
        SingleNode* former = searchAndReturnBefore(target) ;
		if (!former) {
			return -1 ;  // not found
		}
        SingleNode* temp = former->next ;
        former->next = temp->next ;
		int val = temp->val ;
		delete temp ;
		return val ;
	}

	void reverse() {  // head->1->2->3->4->head  to   head->4->3->2->1->head
		SingleNode* p = head, *q = p->next ;
        while (q != head) {
			SingleNode* r = q->next ;  // avoid missing q->next
			q->next = p ;
			p = q ;
			q = r ;
        }
		q->next = p ;
	}
} ;


// self defined stack
class myStack {
private:
	SingleNode* top ;

public:
	myStack() {   // top is the empty node, so the real top is top->next
		top = new SingleNode(-1) ;
		top->next = top ;
    }

	void deleteAllElement() {
		SingleNode* node = top->next ;
		while (node != top) {  // not yet
			SingleNode* temp = node ;
			node = node->next ;
			delete temp ;
		}
		top->next = top ;  // reset the circular link
	}

	void push(int val) {
		top->next = new SingleNode(val, top->next) ;
		/*  n = new SingleNode(val)
			n->next = top=>next ;
			top->next = n
		*/
	}

	int pop() {
		SingleNode* n = top->next ;  // n is the node we want to pop
		top->next = n->next ;  // first,  skip n
		int val = n->val ;     // second, record the val of the node to be deleted
		if (n != top) {
			delete n ;         // third, delete this node
		}
		return val ;
	}

	void traverseFromTop(TMemo* memo) {
		String list = "" ;
		for (SingleNode* temp = top->next; temp != top; temp = temp->next) {
			list += (IntToStr(temp->val) + "-->") ;
		}
		list += "<" ;   // mark the end of the list
		memo->Lines->Add(list) ;
		memo->Lines->Add("") ;
	}
} ;


class myQueue {
private:
	SingleNode* front, *rear ;  // front is the empty head

public:
	myQueue() {
		front = new SingleNode(-1) ;
		front->next = front ;
		rear = front ;
	}

	void deleteAllElement() {
		SingleNode* node = front->next ;
		while (node != front) {  // not yet
			SingleNode* temp = node ;
			node = node->next ;
			delete temp ;
		}
		front->next = front ;  // reset the circular link
		rear = front ;
	}

	void push(int val) {
		rear->next = new SingleNode(val, front) ;  // old rear->next = new rear, new rear->next = front
        rear = rear->next ;
	}

	int pop() {
		SingleNode* n = front->next ;   // n is the node we want to pop
		front->next = n-> next ;        // first,  skip n
		int val = n->val ;   // second, record the val of the node to be deleted

		if (front != rear) {
			delete n ;           // third, delete this node (if not empty)
		}

		if (front->next == front) {
            rear = front ;  // now, this is empty queue
		}
		return val ;
	}

	void traverseFromFront(TMemo* memo) {
		String list = "" ;
		for (SingleNode* temp = front->next; temp != front; temp = temp->next) {
			list += (IntToStr(temp->val) + "-->") ;
		}
		list += "<" ;   // mark the end of the list
		memo->Lines->Add(list) ;
		memo->Lines->Add("") ;
	}
} ;


// self defined node with double links
class DoubleNode {
private:
	int val ;
	DoubleNode* prev, *next ;
	friend class DoubleList ;
public:
    DoubleNode(int val, DoubleNode* prev, DoubleNode* next) : val(val), prev(prev), next(next) {}
};


// self defined doubly linked list
class DoubleList {
private:
	DoubleNode* head ;  // empty head

	void insertAfter(DoubleNode* node, int val) {
	/*
		DoubleNode* n = new DoubleNode(val) ;
		n->prev = node ;
		n->next = node->next ;
		node->next = n ;
		n->next->prev = n ;
	*/
		node->next = new DoubleNode(val, node, node->next) ;
		node->next->next->prev = node->next ;
	}

public:
	DoubleList() {
		head = new DoubleNode(-1, nullptr, nullptr) ;  // empty head, curcular list
		head->next = head ;
		head->prev = head ;
	}

	void deleteAllElement() {  // delete all node except the empty head
		DoubleNode* node = head->next ;
		while (node != head) {  // not yet
			DoubleNode* temp = node ;
			node = node->next ;
			delete temp ;
		}
		head->next = head ;
        head->prev = head ;
	}

	void traverse(TMemo* memo) {  // print the list in order
		String list = "" ;
		for (DoubleNode* temp = head->next; temp != head; temp = temp->next) {
			list += (IntToStr(temp->val) + "<->") ;
		}
		list += "<" ;   // mark the end of the list
		memo->Lines->Add(list) ;
		memo->Lines->Add("") ;
	}

	void insertHead(int val) {   // insert at header->next
        insertAfter(head, val) ;
    }

	void insertLast(int val) {   // insert at last (and its next is header)
		insertAfter(head->prev, val) ;  // head->prev is the last node
	}

	void insertMultipleNodesAtLast(int n, int range) {
		DoubleNode* temp = head->prev ;  // temp is the last node
		for (int i = 0; i < n; i++) {
			insertAfter(temp, rand() % range) ;
			temp = temp->next ;
		}
    }

    DoubleNode* search(int target) {    // search and return this node (pointer)
		DoubleNode* temp ;
		for (temp = head-> next; temp != head && temp->val != target; temp = temp->next) {}

		if (temp == head) {  // not found
			return nullptr ;
		}
		else {
			return temp ;
		}
	}

	bool findAndInsertAfter(int target, int val) {
		DoubleNode* temp = search(target) ;
		if (temp) {   // if found
			insertAfter(temp, val) ;
			return true ;
		}
		return false ;
    }

	bool findAndInsertBefore(int target, int val) {
		DoubleNode* temp = search(target) ;
		if (temp) {   // if found
			insertAfter(temp->prev, val) ;
			return true ;
		}
		return false ;
	}

    int findAndDelete(int target) {
		DoubleNode* temp = search(target) ;
		if (!temp) {
			return -1 ;  // not found
		}
		temp->prev->next = temp->next ;  // skip this node
		temp->next->prev = temp->prev ;
		int val = temp->val ;
		delete temp ;
		return val ;
	}

	void reverse() {  // head<->1<->2<->3<->4->head  to  head<->4<->3<->2<->1->head
		DoubleNode* curr = head ;
		do {
			// swap next and prev
			DoubleNode* temp = curr->next ;
			curr->next = curr->prev ;
			curr->prev = temp ;

			curr = temp ;  // move to next node (which was original next)
		} while (curr != head) ;  // until we go full circle
	}
} ;


// global variable
TForm1 *Form1;
SingleList singleList ;
DoubleList doubleList ;
myStack stack ;  // by singleList
myQueue queue ;  // by singleList


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	Memo1->Clear() ;
	Memo2->Clear() ;
	Memo3->Clear() ;
    Memo4->Clear() ;
}
//---------------------------------------------------------------------------

// the button for pushing
void __fastcall TForm1::Button1Click(TObject *Sender) {
    int val ;
	if (!TryStrToInt(Edit1->Text, val)) {  // check integer
		ShowMessage("please enter integer.") ;
	}

	else if (val <= 0) {   // check positive
		ShowMessage("please enter positive integer.") ;
	}

	else {   // execute push

		// stack
		stack.push(val) ;
		Memo1->Lines->Add("push " + IntToStr(val) + " into the stack.") ;
		stack.traverseFromTop(Memo1) ;  // print the stack from top

		// queue
		queue.push(val) ;
		Memo4->Lines->Add("push " + IntToStr(val) + " into the queue.") ;
        queue.traverseFromFront(Memo4) ;
    }
}
//---------------------------------------------------------------------------

// the button for poping
void __fastcall TForm1::Button2Click(TObject *Sender) {

	// stack
	 int val = stack.pop() ;
	 if (val == -1) {
		Memo1->Lines->Add("pop from empty stack.") ;
	 }
	 else {
		 Memo1->Lines->Add("pop " + IntToStr(val) + " from the stack.") ;
	 }

	// queue
	 val = queue.pop() ;
	 if (val == -1) {
		 Memo4->Lines->Add("pop from empty queue.") ;
	 }
	 else {
		 Memo4->Lines->Add("pop " + IntToStr(val) + " from the queue.") ;
	 }


	 stack.traverseFromTop(Memo1) ;  // print the stack from top
	 queue.traverseFromFront(Memo4) ;
}
//---------------------------------------------------------------------------

// button for re-run(clear the stack / queue)
void __fastcall TForm1::Button3Click(TObject *Sender) {
	Memo1->Clear() ;
	stack.deleteAllElement() ;
	Memo4->Clear() ;
    queue.deleteAllElement() ;
}
//---------------------------------------------------------------------------

// check positive integer
bool checkInput(int& val, TEdit* edit) {
	if (!TryStrToInt(edit->Text, val)) {  // check integer
		 ShowMessage("please enter integer.") ;
		 return false ;
	}
	if (val <= 0) {
		ShowMessage("please enter positive integer.") ;
		return false ;
	}
	return true ;
}


// button for insertion at first
void __fastcall TForm1::Button4Click(TObject *Sender) {
	int val ;
	if (checkInput(val, Edit2)) { // valid input
		singleList.insertHead(val) ;  // single list
		Memo2->Lines->Add("insert " + IntToStr(val) + " at head.") ;
		singleList.traverse(Memo2) ;

		doubleList.insertHead(val) ;  // double list
		Memo3->Lines->Add("insert " + IntToStr(val) + " at head.") ;
		doubleList.traverse(Memo3) ;
	}
}
//---------------------------------------------------------------------------

// button for insertion at last
void __fastcall TForm1::Button5Click(TObject *Sender) {
	int val ;
	if (checkInput(val, Edit2)) { // valid input
		singleList.insertLast(val) ;  // single list
		Memo2->Lines->Add("insert " + IntToStr(val) + " at last.") ;
		singleList.traverse(Memo2) ;

		doubleList.insertLast(val) ;  // double list
		Memo3->Lines->Add("insert " + IntToStr(val) + " at last.") ;
		doubleList.traverse(Memo3) ;
	}
}
//---------------------------------------------------------------------------
// button for reverse the entire list
void __fastcall TForm1::Button11Click(TObject *Sender) {
	singleList.reverse() ;   // single list
	Memo2->Lines->Add("reverse the list") ;
	singleList.traverse(Memo2) ;

	doubleList.reverse() ;   // double list
	Memo3->Lines->Add("reverse the list") ;
	doubleList.traverse(Memo3) ;
}
//---------------------------------------------------------------------------

// button for re-run (linked list)
void __fastcall TForm1::Button12Click(TObject *Sender) {
	Memo2->Clear() ;
	Memo3->Clear() ;
	singleList.deleteAllElement() ;
	doubleList.deleteAllElement() ;
}
//---------------------------------------------------------------------------

// button for search target
void __fastcall TForm1::Button6Click(TObject *Sender) {
	int target ;
	if (checkInput(target, Edit3)) {
		Memo2->Lines->Add("search for " + IntToStr(target)) ;
		Memo3->Lines->Add("search for " + IntToStr(target)) ;

		// single list
		if (singleList.search(target)) {  // success
			Memo2->Lines->Add("it is in the list.") ;
		}
		else {
            Memo2->Lines->Add("it is not in the list.") ;
		}

		// double list
		if (doubleList.search(target)) {  // success
			Memo3->Lines->Add("it is in the list.") ;
		}
		else {
            Memo3->Lines->Add("it is not in the list.") ;
		}

		Memo2->Lines->Add("") ;
		Memo3->Lines->Add("") ;
	}
}
//---------------------------------------------------------------------------

// button for search and insert before
void __fastcall TForm1::Button7Click(TObject *Sender) {
	int val, target ;
	if (checkInput(val, Edit2) && checkInput(target, Edit3)) {

		// single list
		if (singleList.findAndInsertBefore(target, val)) {  // success
			Memo2->Lines->Add("target is found.") ;
		}
		else {
			Memo2->Lines->Add("target not found, so the insertion failed.") ;
		}

		// double list
		if (doubleList.findAndInsertBefore(target, val)) {  // success
			Memo3->Lines->Add("target is found.") ;
		}
		else {
			Memo3->Lines->Add("target not found, so the insertion failed.") ;
		}

		singleList.traverse(Memo2) ;
		doubleList.traverse(Memo3) ;
	}
}
//---------------------------------------------------------------------------

// button for insertion and insert after
void __fastcall TForm1::Button8Click(TObject *Sender) {
	int val, target ;
	if (checkInput(val, Edit2) && checkInput(target, Edit3)) {

		// single list
		if (singleList.findAndInsertAfter(target, val)) {  // success
			Memo2->Lines->Add("target is found.") ;
		}
		else {
			Memo2->Lines->Add("target not found, so the insertion failed.") ;
		}

		// double list
		if (doubleList.findAndInsertAfter(target, val)) {  // success
			Memo3->Lines->Add("target is found.") ;
		}
		else {
			Memo3->Lines->Add("target not found, so the insertion failed.") ;
		}
		singleList.traverse(Memo2) ;
		doubleList.traverse(Memo3) ;
	}
}
//---------------------------------------------------------------------------

// button for search and delete
void __fastcall TForm1::Button9Click(TObject *Sender) {
	int target ;
	if (checkInput(target, Edit3)) {

		// single list
		if (singleList.findAndDelete(target) != -1) {  // success
			Memo2->Lines->Add("target is found.") ;
		}
		else {
			Memo2->Lines->Add("target not found, so the deletion failed.") ;
		}

		// double list
		if (doubleList.findAndDelete(target) != -1) {  // success
			Memo3->Lines->Add("target is found.") ;
		}
		else {
			Memo3->Lines->Add("target not found, so the deletion failed.") ;
		}

		singleList.traverse(Memo2) ;
		doubleList.traverse(Memo3) ;
	}
}
//---------------------------------------------------------------------------

// insert n random nodes at last
void __fastcall TForm1::Button10Click(TObject *Sender) {
	int n, range ;
	if (checkInput(n, Edit4) && checkInput(range, Edit5)) {
		singleList.insertMultipleNodesAtLast(n, range) ;  // single list
		Memo2->Lines->Add("insert " + IntToStr(n) + " nodes at last.") ;
		singleList.traverse(Memo2) ;

		doubleList.insertMultipleNodesAtLast(n, range) ;  // double list
		Memo3->Lines->Add("insert " + IntToStr(n) + " nodes at last.") ;
		doubleList.traverse(Memo3) ;
	}
}
//---------------------------------------------------------------------------
