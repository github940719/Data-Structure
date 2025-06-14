//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AVL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------

// tree
struct TreeNode {
	int val;
    int height ;
	TreeNode* left;
	TreeNode* right;

	// constructor (the height of a new node is 1)
	TreeNode(int val) : val(val), left(nullptr), right(nullptr), height(1) {}
} ;

TreeNode* root = nullptr ;


// get max of a and b
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


// get height of an input node
int getHeight(TreeNode* node) {
	if (node) {
		return node->height ;
	}
	else {
		return 0 ;  // the height of nullptr is 0
	}
}


// get the balance factor of an input node
int getBalanceFactor(TreeNode* node) {   // left - right
	if (node) {
		return getHeight(node->left) - getHeight(node->right) ;
	}
	else {
		return 0 ;  // the balance factor of nullptr is  0
	}
}


// left rotate, input the node to be rotated, return the new root
TreeNode* leftRotate(TreeNode* x) {
	// rotate
	TreeNode* y = x->right, *T2 = y->left ;
	y->left = x ;
	x->right = T2 ;

	// recalculate height
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1 ;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1 ;
	return y ;
}


// right rotate, input the node to be rotated, return the new root
TreeNode* rightRotate(TreeNode* y) {
	// rotate
	TreeNode* x = y->left, *T2 = x->right ;
	x->right = y ;
    y->left = T2 ;

	// recalculate height
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1 ;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1 ;
	return x ;
}


// insert a node into AVL tree
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

	// update height
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1 ;
	int balance = getBalanceFactor(root) ;

	// 4 cases
	if (balance > 1) {  // L?
		if (element < root->left->val) {  // LL
			return rightRotate(root) ;
		}
		else {  // LR
			root->left = leftRotate(root->left) ;
			return rightRotate(root) ;
		}
	}

	else if (balance < -1) {
		if (element > root->right->val) {  // RR
			return leftRotate(root) ;
		}
		else {  // RL
			root->right = rightRotate(root->right) ;
			return leftRotate(root) ;
		}
	}

	// balance
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


// delete an element from AVL tree
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

	// update height
	if (!root) {
        return nullptr ;
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1 ;
	int balance = getBalanceFactor(root) ;

	// 4 cases
	if (balance > 1) {  // L?
		if (getBalanceFactor(root->left) >= 0) {  // LL
			return rightRotate(root) ;
		}
		else {  // LR
			root->left = leftRotate(root->left) ;
			return rightRotate(root) ;
		}
	}

	else if (balance < -1) {
		if (getBalanceFactor(root->right) <= 0) {  // RR
			return leftRotate(root) ;
		}

		else {  // RL
			root->right = rightRotate(root->right) ;
			return leftRotate(root) ;
        }
	}

	// balance
	return root ;
}



// button for insertion
void __fastcall TForm1::Button1Click(TObject *Sender) {
	int element ;  // input element
	if (!TryStrToInt(Edit1->Text, element)) {
		ShowMessage("please enter integer element.") ;
		return ;
	}

	root = insert(root, element) ;
    PaintBox1->Repaint() ;
    DrawBST(root, PaintBox1->Canvas) ;
}
//---------------------------------------------------------------------------

// button for deletion
void __fastcall TForm1::Button2Click(TObject *Sender) {
	int element ;  // input element
	if (!TryStrToInt(Edit1->Text, element)) {
		ShowMessage("please enter integer element.") ;
		return ;
	}

	root = remove(root, element) ;
	PaintBox1->Repaint() ;
	DrawBST(root, PaintBox1->Canvas) ;
}
//---------------------------------------------------------------------------

// delete the entire tree by postorder traversal
void deleteTree(TreeNode* root) {
	if (root) {
		deleteTree(root->left) ;
		deleteTree(root->right) ;
		delete root ;
	}
}


// button for re-run
void __fastcall TForm1::Button3Click(TObject *Sender) {
	deleteTree(root) ;
	root = nullptr ;
	PaintBox1->Invalidate() ;  // clear paintBox1
}
//---------------------------------------------------------------------------

// button for drawing AVL
void __fastcall TForm1::Button4Click(TObject *Sender) {
	PaintBox1->Repaint() ;
	DrawBST(root, PaintBox1->Canvas) ;
}
//---------------------------------------------------------------------------

