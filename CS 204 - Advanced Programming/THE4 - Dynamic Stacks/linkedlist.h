//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from linkedlist.h from CS204    //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#include <string>
using namespace std;

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct node {
	string info;
	node *next; 

	node ()
	{}

	node(const string & s)
		: info(s), next (NULL)
	{}
};

class linkedlist 
{
	public:
		// Constructor.
		linkedlist ();
		node * head;

		// Destructor
		~linkedlist();
		
		// Member functions.
		void printList();
		void addToBeginning(string n);
		void addToEnd (string str);

};

#endif