//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from DynIntStack.cpp from CS204 //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#include <iostream>
#include <string>
#include "DynStrStack.h"
using namespace std;

//************************************************
// Constructor to generate an empty stack.       *
//************************************************
DynStrStack::DynStrStack()
{
	top = NULL; 
}

//****************************************************
// Destructor for the stack. Pops all elements until *
// Stack is empty.                                   *
//****************************************************
DynStrStack::~DynStrStack()
{
	string a, b;
	while(!isEmpty())
	{
		pop(a, b);
	}
#ifdef DEBUGG
	cout << "[[Destructor for Stack is called]]" << endl;

#endif
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************
void DynStrStack::push(string str, string func)
{
	StackNode *newNode;

	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->value = str;
	newNode->function = func;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************
void DynStrStack::pop(string &str, string &func)
{
	StackNode *temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else	// pop value off top of stack
	{
		str = top->value;
		func = top->function;
		temp = top->next;
		delete top;
		top = temp;
	}
}

void DynStrStack::con_clear(string func)
{
	string a, b;
	while(!isEmpty())
	{
		if (top->function == func)
			pop(a, b);
		else 
			break;
	}
#ifdef _DEBUG
	cout << "[DEBUG]" << "[[Stack partially cleared]]" << endl;

#endif
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
bool DynStrStack::isEmpty(void)
{
	bool status;

	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}

//****************************************************
// Clear function for the stack. Pops all elements   *
// until Stack is empty. Works like destructor.      *
//****************************************************
void DynStrStack::clear()
{
	string a, b;
	while(!isEmpty())
	{
		pop(a, b);
	}
#ifdef _DEBUG
	cout << "[DEBUG]" << "[[Stack cleared]]" << endl;

#endif
}

//****************************************************
// Printing function for stack. Prints from bottom   *
// to top                                            *
//****************************************************
void DynStrStack::PrintStack()
{
	if(isEmpty())
	{
		cout << "The stack is empty." << endl;
		return;
	}
    DynStrStack temp;
	string x, y;
    while (!isEmpty())
	{
		pop(x, y);
		temp.push(x, y);
	}

#ifdef DEBUGG
	cout << "[DEBUG]" << "printing stack..." << endl << endl;
#endif

	while (!temp.isEmpty())
	{
		temp.pop(x, y);
		push(x, y);  //entering the values again
		cout << y << ": " << x << endl;
	}

}