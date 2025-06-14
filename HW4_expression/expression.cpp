//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "expression.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// definition of myStack
class myStack {
	private:
        int maxSize ;
		String* arr = nullptr ;
        int top = -1 ;

    public:
        myStack(int maxSize) : maxSize(maxSize) {
			arr = new String[maxSize] ;
        }

        ~myStack() {
            delete [] arr ;
            arr = nullptr ;
        }

		void push(String element) {
            arr[++top] = element ;
        }

		String peek() {
            return arr[top] ;
        }

		String pop() {
            return arr[top--] ;
		}

		String print() {
			String content = "" ;
			for (int i = 0; i <= top; i++) {
				content += arr[i] ;
				content += (",  ") ;
			}
			return (content) ;
        }
} ;


// return the priority when pop outside the stack
int outPriority(String c) {  // the larger the number, the higher the precedence
	if (c == "^") {
        return 3 ;
    }
    if (c == "*" || c == "/" || c == "%") {
        return 2 ;
    }
    if (c == "+" || c == "-") {
        return 1 ;
    }
	if (c == "(") {
        return 0 ;
	}

	return -1 ;  // end of the stack  (#)
}


// return the priority when push into the stack
int inPriority(String c) {  // the larger the number, the higher the precedence
    if (c == "(") {
		return 5 ;
    }
    if (c == "^") {
		return 4 ;  // larger than the outPriority("^")
    }
    if (c == "*" || c == "/" || c == "%") {
        return 2 ;
    }
    if (c == "+" || c == "-") {
        return 1 ;
	}
	return -1 ;   // # (end of stack)
}


// return whether the input if operand (true) or operator (false)
bool isOperand(String str) {  // A to Z
	char c = str.c_str()[0] ;
    return (c - 'A' >= 0 && c - 'A' < 26) ;
}


// evaluateExpression
int evaluateExpression(String expression) {
	int len = expression.Length() ;
	for (int i = 1; i <= len; i++) {
		String c = expression[i] ;
		if (!isOperand(c) && inPriority(c) == -1 && c != ")") {
            ShowMessage("undefined token : " + c) ;   // not operand, not operator
			return -1 ;
		}
	}
	return len ;
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner){}
//---------------------------------------------------------------------------
// infix to postfix
void __fastcall TForm1::Button4Click(TObject *Sender) {
	String infix = Edit2->Text ;
	int len = evaluateExpression(infix) ;

	if (len == -1) {
        return ;  // this is an invalid expression
	}

	String postfix = "" ;
	myStack operators(len) ;
	operators.push("#") ;

	Memo8->Clear() ;
	for (int i = 1; i <= len; i++) {
		String c = infix[i] ;
        if (isOperand(c)) {   // this is an operand
            postfix += c ;
        }

        // this is an operator
        else if (c == ")") {
			while (operators.peek() != "(") {
				postfix += operators.pop() ;
            }
			operators.pop() ;  // pop "("
        }

        else {
			while (inPriority(c) <= outPriority(operators.peek())) {
                postfix += operators.pop() ;
            }
			operators.push(c) ;  // push to stack
		}
		Memo8->Lines->Add("Read character: " + c) ;
		Memo8->Lines->Add("Operator stack: " + operators.print()) ;
		Memo8->Lines->Add("current postfix: " + postfix) ;
		Memo8->Lines->Add("") ;  // an empty line
    }

	// output the remaining operand to postfix
	while (operators.peek() != "#") {
        postfix += operators.pop() ;
	}
	Form1->Memo4->Clear() ;
	Form1->Memo4->Lines->Add(postfix) ;
}
//---------------------------------------------------------------------------
// get prefix (used in infix to prefix, postfix to prefix)
String getPrefix(myStack& operands, String opr) {
	String s2 = operands.pop(), s1 = operands.pop() ;
	return (opr + s1 + s2) ;
}
// infix to prefix
void __fastcall TForm1::Button3Click(TObject *Sender) {
	String infix = Edit2->Text ;
	int len = evaluateExpression(infix) ;

	if (len == -1) {
		return ;  // this is an invalid expression
	}

	myStack operators(len) ;
	operators.push("#") ;
	myStack operands(len) ;

	Memo8->Clear() ;
	for (int i = 1; i <= len; i++) {
		String c = infix[i] ;
		if (isOperand(c)) {   // this is an operand
			operands.push(c) ;
		}

        // this is an operator
		else if (c == ")") {
			while (operators.peek() != "(") {
				operands.push(getPrefix(operands, operators.pop())) ;
			}
			operators.pop() ;  // pop "("
        }

		else {
			while (inPriority(c) <= outPriority(operators.peek())) {
				operands.push(getPrefix(operands, operators.pop())) ;
			}
			operators.push(c) ;  // push to stack
		}
		Memo8->Lines->Add("Read character: " + c) ;
		Memo8->Lines->Add("Operator stack: " + operators.print()) ;
		Memo8->Lines->Add("Operand stack: " + operands.print()) ;
        Memo8->Lines->Add("") ;  // an empty line
	}

	// output the remaining operand to prefix
	while (operators.peek() != "#") {
		operands.push(getPrefix(operands, operators.pop())) ;
	}
	Form1->Memo3->Clear() ;
	Form1->Memo3->Lines->Add(operands.peek()) ;
}
//---------------------------------------------------------------------------
// post to prefix
void __fastcall TForm1::Button5Click(TObject *Sender) {
	String postfix = Edit3->Text ;
	int len = evaluateExpression(postfix) ;

	if (len == -1) {
		return ;  // this is an invalid expression
	}

	myStack operands(len) ;
	Memo7->Clear() ;

	for (int i = 1; i <= len; i++) {
		String c = postfix[i] ;
		if (isOperand(c)) {   // this is an operand
			operands.push(c) ;
		}
		else {  // this is an operator
			operands.push(getPrefix(operands, c)) ;
		}
		Memo7->Lines->Add("Read character: " + c) ;
		Memo7->Lines->Add("operand stack: " + operands.print()) ;
		Memo7->Lines->Add("") ;  // an empty line
	}

	Form1->Memo6->Clear() ;
	Form1->Memo6->Lines->Add(operands.peek()) ;
}
//---------------------------------------------------------------------------
// get postfix (used in prefix to postfix)
String getPostfix(myStack& operators, String s2) {
	String s1 = operators.pop(), opr = operators.pop() ;
	return (s1 + s2 + opr) ;
}
//---------------------------------------------------------------------------
// prefix to postfix
void __fastcall TForm1::Button2Click(TObject *Sender) {
	String prefix = Edit1->Text ;
	int len = evaluateExpression(prefix) ;

	if (len == -1) {
		return ;  // this is an invalid expression
	}

	myStack operators(len) ;
	operators.push("#") ;  // the end of the stack

	Memo9->Clear() ;
	for (int i = 1; i <= len; i++) {
		String c = prefix[i] ;
        Memo9->Lines->Add("Read character: " + c) ;
		if (!isOperand(c)) {   // this is an operator
			operators.push(c) ;
		}

		// this is an operand
		else {
			while (isOperand(operators.peek())) {   // top is operand
				c = (getPostfix(operators, c)) ;  // get the combined operand
			}
			operators.push(c) ;
		}
		Memo9->Lines->Add("operator stack: " + operators.print()) ;
		Memo9->Lines->Add("") ;  // an empty line
	}

	// output the remaining operand to postfix
	Form1->Memo2->Clear() ;
	Form1->Memo2->Lines->Add(operators.peek()) ;
}
//---------------------------------------------------------------------------
void swap(String& s1, String& s2) {
	String temp = s1 ;
	s1 = s2 ;
	s2 = temp ;
}


// used in the for loop of prefix / postfix to infix
void toInfix(myStack& operands, myStack& operators, String c, bool givenPre) {
	if (isOperand(c)) {   // this is an operand
		operands.push(c) ;
		operators.push("x") ;
		return ;
	}

	// this is an operator
	String s2 = operands.pop(), s1 = operands.pop() ;
	String opr2 = operators.pop(), opr1 = operators.pop() ;
	if (givenPre) {   // given postfix
		swap(s1, s2) ;
        swap(opr1, opr2) ;
	}

	// determine whether to add () to the two operator
	if (opr2 != "x" && inPriority(c) > outPriority(opr2)) {
		s2 = "(" + s2 + ")" ;   // when opr2's priority is lower
	}
	if (opr1 != "x" && inPriority(c) > outPriority(opr1)) {
		s1 = "(" + s1 + ")" ;  // when opr1's priority is lower
	}
	operands.push(s1 + c + s2) ;
	operators.push(c) ;  // choose the lowest among s1, c, s2
}


// postfix to infix
void __fastcall TForm1::Button6Click(TObject *Sender) {
	String postfix = Edit3->Text ;
	int len = evaluateExpression(postfix) ;

	if (len == -1) {
		return ;  // this is an invalid expression
	}

	myStack operands(len) ;
	myStack operators(len) ;
	Memo7->Clear() ;
	for (int i = 1; i <= len; i++) {  // from left to right
		String c = postfix[i] ;
		toInfix(operands, operators, c, false) ;
		Memo7->Lines->Add("Read character: " + c) ;
		Memo7->Lines->Add("operator stack: " + operators.print()) ;
		Memo7->Lines->Add("operand stack: " + operands.print()) ;
		Memo7->Lines->Add("") ;  // an empty line
	}
	Form1->Memo5->Clear() ;
	Form1->Memo5->Lines->Add(operands.peek()) ;
}
//---------------------------------------------------------------------------
// prefix to infix
// like postfix to infix, but traverse from right to left
void __fastcall TForm1::Button1Click(TObject *Sender) {
	String prefix = Edit1->Text ;
	int len = evaluateExpression(prefix) ;

	if (len == -1) {
		return ;  // this is an invalid expression
	}

	myStack operands(len) ;
	myStack operators(len) ;

	Memo9->Clear() ;
	Memo9->Lines->Add("we would traverse from right to left.") ;
	for (int i = len; i > 0; i--) {  // from right to left
		String c = prefix[i] ;
		toInfix(operands, operators, c, true) ;
		Memo9->Lines->Add("Read character: " + c) ;
		Memo9->Lines->Add("operator stack: " + operators.print()) ;
		Memo9->Lines->Add("operand stack: " + operands.print()) ;
		Memo9->Lines->Add("") ;  // an empty line
	}
	Form1->Memo1->Clear() ;
	Form1->Memo1->Lines->Add(operands.peek()) ;
}
//---------------------------------------------------------------------------
