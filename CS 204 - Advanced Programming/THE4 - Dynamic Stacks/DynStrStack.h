//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from DynIntStack.h from CS204   //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#ifndef DYNSTRSTACK_H
#define DYNSTRSTACK_H

#include <string>
using namespace std;

struct StackNode
{
	string value;
	string function;
	StackNode *next;
};

class DynStrStack
{
private:
	StackNode *top;

public:
	// Constructor.
	DynStrStack(void);

	//Destructor
	~DynStrStack();

	// Member functions.
	void push(string value, string func);
	void pop(string &, string &);
	void con_clear(string func);
	bool isEmpty(void);
	void PrintStack();
	void clear();
};
#endif