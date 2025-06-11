#include <vcl.h>
#include "BST.h"
#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// tree
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	// two constructors
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
} ;

TreeNode* root = nullptr ;


// node, val = TreeNode*
struct SingleNode {
	TreeNode* val ;
	SingleNode* next ;
	SingleNode(TreeNode* val) : val(val), next(nullptr) {}
	SingleNode(TreeNode* val, SingleNode* next) : val(val), next(next) {}
};


// stack, val = TreeNode*
class myStack {
private:
	SingleNode* top ;

public:
	myStack() {   // top is the empty node, so the real top is top->next
		top = new SingleNode(nullptr) ;
		top->next = top ;
	}

	void push(TreeNode* val) {
		top->next = new SingleNode(val, top->next) ;
	}

	bool isEmpty() {
		return (top->next == top) ;
	}

	TreeNode* pop() {
		SingleNode* n = top->next ;  // n is the node we want to pop
		top->next = n->next ;        // first,  skip n
		TreeNode* val = n->val ;     // second, record the val of the node to be deleted
		if (n != top) {
			delete n ;  // third, delete this node
		}
		return val ;
	}
} ;


// node, val = int
struct SingleNodeInt {
	int val ;
	SingleNodeInt* next ;
	SingleNodeInt(int val) : val(val), next(nullptr) {}
	SingleNodeInt(int val, SingleNodeInt* next) : val(val), next(next) {}
};


// stack, val = TreeNode*
class myStackInt {
private:
	SingleNodeInt* top ;

public:
	myStackInt() {   // top is the empty node, so the real top is top->next
		top = new SingleNodeInt(-1) ;
		top->next = top ;
	}

	void push(int val) {
		top->next = new SingleNodeInt(val, top->next) ;
	}

	bool isEmpty() {
		return (top->next == top) ;
	}

	int pop() {
		SingleNodeInt* n = top->next ;  // n is the node we want to pop
		top->next = n->next ;        // first,  skip n
		int val = n->val ;     // second, record the val of the node to be deleted
		if (n != top) {
			delete n ;  // third, delete this node
		}
		return val ;
	}
} ;


// queue, val = TreeNode*
class myQueue {
private:
	SingleNode* front, *rear ;  // front is the empty head

public:
	myQueue() {
		front = new SingleNode(nullptr) ;
		front->next = front ;
		rear = front ;
	}

	bool isEmpty() {
		return (front == rear) ;
	}

	void push(TreeNode* val) {
		rear->next = new SingleNode(val, front) ;  // old rear->next = new rear, new rear->next = front
        rear = rear->next ;
	}

	TreeNode* pop() {
		SingleNode* n = front->next ;   // n is the node we want to pop
		front->next = n-> next ;  // first,  skip n
		TreeNode* val = n->val ;  // second, record the val of the node to be deleted

		if (front != rear) {
			delete n ;           // third, delete this node (if not empty)
		}

		if (front->next == front) {
			rear = front ;  // now, this is empty queue
		}
		return val ;
	}
};


int max(int a, int b) {
    return a > b ? a : b ;
}


// recursively draw BST
void DrawBSTRecursive(TreeNode* node, int x, int y, int dx, int dy, TCanvas* canvas) {
	if (!node) return ;

	const int radius = 20 ;
	canvas->Ellipse(x - radius, y - radius, x + radius, y + radius) ;
	canvas->TextOut(x - 7, y - 7, IntToStr(node->val)) ;

	// draw left
	if (node->left) {
		int x2 = x - dx ;
		int y2 = y + dy ;
		double len = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) ;
		double offsetX = (x2 - x) / len * radius ;
		double offsetY = (y2 - y) / len * radius ;

		canvas->MoveTo(x + offsetX, y + offsetY) ;
		canvas->LineTo(x2 - offsetX, y2 - offsetY) ;
		DrawBSTRecursive(node->left, x2, y2, max(dx / 2, 20), dy, canvas) ;
	}

	// draw right
	if (node->right) {
		int x2 = x + dx ;
		int y2 = y + dy ;
		double len = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) ;
		double offsetX = (x2 - x) / len * radius ;
		double offsetY = (y2 - y) / len * radius ;

		canvas->MoveTo(x + offsetX, y + offsetY) ;
		canvas->LineTo(x2 - offsetX, y2 - offsetY) ;
		DrawBSTRecursive(node->right, x2, y2, max(dx / 2, 20), dy, canvas) ;
	}
}


// API for drawing BST
void DrawBST(TreeNode* root, TCanvas* canvas) {
	if (!root) return ;

	int dy = 80 ;
	int dx = canvas->ClipRect.Width() / 4 ;

	int rootX = canvas->ClipRect.Width() / 2 ;
	int rootY = 40 ;

	DrawBSTRecursive(root, rootX, rootY, dx, dy, canvas) ;
}


// recursive in-order traversal
void inOrder(TreeNode* root, String& ans) {
	if (root) {
		inOrder(root->left, ans) ;
		ans += ("_" + IntToStr(root->val)) ;
        inOrder(root->right, ans) ;
	}
}


// recursive pre-order traversal
void preOrder(TreeNode* root, String& ans) {
	if (root) {
		ans += ("_" + IntToStr(root->val)) ;
		preOrder(root->left, ans) ;
		preOrder(root->right, ans) ;
	}
}


// recursive post-order traversal
void postOrder(TreeNode* root, String& ans) {
	if (root) {
		postOrder(root->left, ans) ;
		postOrder(root->right, ans) ;
		ans += ("_" + IntToStr(root->val)) ;
	}
}


// iterative in-order traversal
void inOrderIter(TreeNode* root, String& ans) {
	myStack s ;
	while (root || !s.isEmpty())  {
		for (; root; root = root->left) {   // keep moving left
			s.push(root) ;
		}

		root = s.pop() ;
		ans +=  ("_" + IntToStr(root->val)) ;  // traverse
        root = root->right ;
	}
}


// iterative pre-order traversal
void preOrderIter(TreeNode* root, String& ans) {
	myStack s ;
	while (root || !s.isEmpty())  {
		for (; root; root = root->left) {   // keep moving left
			ans +=  ("_" + IntToStr(root->val)) ;   // traverse
			s.push(root) ;
		}

		root = s.pop() ;
		root = root->right ;
	}
}


// iterative post-order traversal
void postOrderIter(TreeNode* root, String& ans) {
	myStack s ;
	myStackInt reverse ;
	while (root || !s.isEmpty())  {
		for (; root; root = root->right) {   // keep moving "right"
			reverse.push(root->val) ;   // traverse
			s.push(root) ;
		}

		root = s.pop() ;
		root = root->left ;
	}

	// reverse
	while (!reverse.isEmpty()) {
		ans += ("_" + IntToStr(reverse.pop())) ;
	}
}


// iterative level-order traversal
void levelOrder(TreeNode* root, String& ans) {
	if (!root) {
		return ;  // empty root
	}

	myQueue q ;
	q.push(root) ;
	while (!q.isEmpty()) {  // queue is not emtpy
		TreeNode* node = q.pop() ;
		ans += ("_" + IntToStr(node->val)) ;
		if (node->left) {
			q.push(node->left) ;
		}
		if (node->right) {
			q.push(node->right) ;
		}
	}
}


// recursively search an element in BST
TreeNode* search(TreeNode* root, int target) {
	if (!root) {  // not found
		return nullptr ;
	}
	if (root->val == target) {   // found
		return root ;
	}
	if (target > root->val) {
		return search(root->right, target) ;
	}
	return search(root->left, target) ;
}


// recursively insert an element into BST
TreeNode* insert(TreeNode* root, int element) {
	if (!root) {  // not found -> insert!
		return new TreeNode(element) ;
	}
	if (element > root->val) {
		root->right = insert(root->right, element) ;
	}
	else if (element < root->val) {
		root->left = insert(root->left, element) ;
	}
	else {
        ShowMessage(IntToStr(element) + " is in BST, so the insertion failed.") ;
    }
    return root ;
}

// find the inorder immediate successor
TreeNode* successor(TreeNode* root) {
	TreeNode* temp = root->right ;
	while (temp->left) {
		temp = temp->left ;
	}
    return temp ;
}


// resursively delete an element from BST
TreeNode* remove(TreeNode* root, int element) {
	if (!root) {
		ShowMessage(IntToStr(element) + " is not in BST, so the deletion failed.") ;
		return nullptr ;
	}
	if (element > root->val) {
		root->right = remove(root->right, element) ;
	}
	else if (element < root->val) {
		 root->left = remove(root->left, element) ;
	}
	else {  // delete this root
		if (root->left && root->right) {   // two children
			TreeNode* temp = successor(root) ;
			root->val = temp->val ;  // copy the inorder immeidate successor to root
			root->right = remove(root->right, temp->val) ;
		}
		else if ((!root->left) && (!root->right)) {  // no children
			delete root ;
            root = nullptr ;
		}
		else {   // exactly one children
			TreeNode* temp = root->left ? root->left : root->right ;
			*root = *temp ;  // copy temp to root
            delete temp ;
        }
	}

	return root ;
}


// delete the entire tree by postorder traversal
void deleteTree(TreeNode* root) {
	if (root) {
		deleteTree(root->left) ;
		deleteTree(root->right) ;
		delete root ;
	}
}

// iteratively search an element in BST
TreeNode* searchIter(TreeNode* root, int target) {
	while (root) {
		if (root->val == target) {
			return root ;  // found
		}
		if (target > root->val) {
			root = root->right ;
		}
		else if (target < root->val) {
			root = root->left ;
		}
		else {
			ShowMessage(IntToStr(target) + " is in BST, so the insertion failed.") ;
			return root ;
        }
	}
	return nullptr ;  // not found
}


// iteratively insert an element into BST
TreeNode* insertIter(TreeNode* root, int element) {
	TreeNode* former = nullptr, *temp = root ;
	while (temp) {
		former = temp ;  // move forward
		if (element > temp->val) {
			temp = temp->right ;
		}
		else if (element < temp->val) {
			temp = temp->left ;
		}
		else {
			ShowMessage(IntToStr(element) + " is in BST, so the insertion failed.") ;
			return root ;
        }
	}

	// insert an element at temp, whose father is former
	temp = new TreeNode(element) ;
	if (!root) {
		root = temp ;
	}
	else if (element < former->val) {
		former->left = temp ;
	}
	else {
        former->right = temp ;
	}
    return root ;
}


// iteratively delete an element from BST
TreeNode* removeIter(TreeNode* root, int element) {
	TreeNode* tempParent = nullptr, *temp = root ;

	while (temp) {
		if (element == temp->val) {   // we want to delete temp

			if (temp->left && temp->right) {  // two children
				// find inorder immediate successor and its parent
				TreeNode* succParent = temp, *succ = temp->right ;
				while (succ->left) {
					succParent = succ ;
					succ = succ->left ;
				}

				// exchange the node pointer
				if (succ->val > succParent->val) {
					succParent-> right = succ->right ;
				}
				else {
					succParent->left = succ->right ;
                }

				succ->right = temp->right ;
				succ->left = temp->left ;

				if (!tempParent) {  // no parent  i.e. we want to delete the root
					root = succ ;
				}
				else if (element > tempParent->val) {
					tempParent->right = succ ;
				}
				else {
					tempParent->left = succ ;
				}
			}

			else if (temp->left || temp->right) {   // one child
				TreeNode* succ = temp->left ? temp->left : temp->right ;
				if (!tempParent) {  // no parent
                    root = succ ;
				}
				else if (element > tempParent->val) {
					tempParent->right = succ ;
				}
				else {
					tempParent->left = succ ;
				}
			}

			else {  // no children
				if (!tempParent) {
					root = nullptr ;
				}
				else if (element > tempParent->val) {
					tempParent->right = nullptr ;
				}
				else {
                    tempParent->left = nullptr ;
                }
			}


			delete temp ;
			return root ;
		}

		else {
			tempParent = temp ;  // move forward
			if (element > temp->val) {
				temp = temp->right ;
			}
			else {
				temp = temp->left ;
            }
        }
	}
	ShowMessage(IntToStr(element) + " is not in BST, so the deletion failed.") ;
    return root ;
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
    RadioButton1->Checked = True ;  // default : recursion
}
//---------------------------------------------------------------------------
//button : insert one element into BST
void __fastcall TForm1::Button1Click(TObject *Sender) {
	int element ;  // input element
	if (!TryStrToInt(Edit1->Text, element)) {
		ShowMessage("please enter integer element.") ;
		return ;
	}
	if (RadioButton1->Checked) {  // recursive
		root = insert(root, element) ;
		Memo1->Lines->Add("insert (recursive) " + IntToStr(element) + " to BST.") ;
	}
	else {  // iterative
		root = insertIter(root, element) ;
		Memo1->Lines->Add("insert (iterative) " + IntToStr(element) + " to BST.") ;
	}
	Button6->Click();   // inorder traversal
}
//---------------------------------------------------------------------------
// button for inorder traversal
void __fastcall TForm1::Button6Click(TObject *Sender) {
	String ans = "" ;
	if (RadioButton1->Checked) {  // recursive
		inOrder(root, ans) ;
        Memo1->Lines->Add("in-order (recursive): " + ans) ;
	}
	else {  // iterative
		inOrderIter(root, ans) ;
        Memo1->Lines->Add("in-order (iterative): " + ans) ;
	}
	Memo1->Lines->Add("") ;
	PaintBox1->Repaint() ;
	DrawBST(root, PaintBox1->Canvas) ;
}
//---------------------------------------------------------------------------
// button for preorder traversal
void __fastcall TForm1::Button5Click(TObject *Sender) {
	String ans = "" ;
	if (RadioButton1->Checked) {  // recursive
		preOrder(root, ans) ;
		Memo1->Lines->Add("pre-order (recursive): " + ans) ;
	}
	else {  // iterative
		preOrderIter(root, ans) ;
        Memo1->Lines->Add("pre-order (iterative): " + ans) ;
	}
	Memo1->Lines->Add("") ;
	DrawBST(root, PaintBox1->Canvas) ;
}
//---------------------------------------------------------------------------
// button for postorder traversal
void __fastcall TForm1::Button7Click(TObject *Sender) {
	String ans = "" ;
	if (RadioButton1->Checked) {  // recursive
		postOrder(root, ans) ;
		Memo1->Lines->Add("post-order (recursive): " + ans) ;
	}
	else {  // iterative
		postOrderIter(root, ans) ;
		Memo1->Lines->Add("post-order (iterative): " + ans) ;
	}
	Memo1->Lines->Add("") ;
	DrawBST(root, PaintBox1->Canvas) ;
}
//---------------------------------------------------------------------------
// button for search
void __fastcall TForm1::Button4Click(TObject *Sender) {
	int element ;  // input element
	if (!TryStrToInt(Edit5->Text, element)) {
		ShowMessage("please enter integer element.") ;
		return ;
	}

	if (RadioButton1->Checked) {  // recursive
		if (search(root, element)) {
			Memo1->Lines->Add(IntToStr(element) + " is found in BST (recursive).") ;
		}
		else {
			Memo1->Lines->Add(IntToStr(element) + " is not in BST (recursive).") ;
		}
	}
	else {  // iterative
		if (searchIter(root, element)) {
			Memo1->Lines->Add(IntToStr(element) + " is found in BST (iterative).") ;
		}
		else {
			Memo1->Lines->Add(IntToStr(element) + " is not in BST (iterative).") ;
		}
	}

	Memo1->Lines->Add("") ;
}
//---------------------------------------------------------------------------
// button for deletion
void __fastcall TForm1::Button3Click(TObject *Sender) {
	int element ;  // input element
	if (!TryStrToInt(Edit4->Text, element)) {
		ShowMessage("please enter integer element.") ;
		return ;
	}

	if (RadioButton1->Checked) {  // recursive
		root = remove(root, element) ;
		Memo1->Lines->Add("delete " + IntToStr(element) + " from BST (recursive).") ;
	}
	else {  // iterative
		root = removeIter(root, element) ;
		Memo1->Lines->Add("delete " + IntToStr(element) + " from BST (iterative).") ;
	}
	Button6->Click();   // inorder traversal
}
//---------------------------------------------------------------------------
// button for re-run
void __fastcall TForm1::Button9Click(TObject *Sender) {
	Memo1->Clear() ;
	deleteTree(root) ;
	root = nullptr ;
	PaintBox1->Invalidate() ;  // clear paintBox1
}
//---------------------------------------------------------------------------
// insert k random numbers within range n into BST
void __fastcall TForm1::Button2Click(TObject *Sender) {
	int k, range ;  // input
	if (!TryStrToInt(Edit2->Text, k) || !TryStrToInt(Edit3->Text, range)) {
		ShowMessage("please enter integer k and range.") ;
		return ;
	}

	if (range < k) {
		ShowMessage("range should >= k") ;
		return ;
	}

	for (int i = 0; i < k; i++) {
		int val = rand() % range + 1, count = 0 ;
		while (search(root, val) && count++ < 20) {  // random a number not in BST
			val = rand() % range + 1 ;
		}

		if (count >= 20) {
			ShowMessage("we have tried 20 random numbers, but all of them are in BST now. Please try again or increase the range.") ;
			return ;
		}

		if (RadioButton1->Checked) {  // recursive
			root = insert(root, val) ;
		}
		else {   // iterative
			root = insertIter(root, val) ;
		}
	}

	if (RadioButton1->Checked) {  // recursive
		Memo1->Lines->Add("randomly insert (recursive) " + IntToStr(k) + " numbers into BST.") ;
	}
	else {   // iterative
		Memo1->Lines->Add("randomly insert (iterative) " + IntToStr(k) + " numbers into BST.") ;
	}
	Button6->Click();   // inorder traversal
}
//---------------------------------------------------------------------------
// button for level order traversal
void __fastcall TForm1::Button8Click(TObject *Sender) {
	String ans = "" ;
	levelOrder(root, ans) ;
	Memo1->Lines->Add("level-order: " + ans) ;
	Memo1->Lines->Add("") ;
	DrawBST(root, PaintBox1->Canvas) ;
}
//---------------------------------------------------------------------------

