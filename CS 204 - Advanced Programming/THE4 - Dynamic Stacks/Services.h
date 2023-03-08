//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// I made this one myself hehehe                       //
// Class for keeping all services                      //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#ifndef _SERVICES_H
#define _SERVICES_H

#include <string>
#include "linkedlist.h"
#include <iostream>

using namespace std;

struct serv_node
{
	string info;
	linkedlist commands;
	serv_node* next;

	serv_node()
	{
		next = NULL;
	}

	serv_node(string n)
		: info(n), next(NULL)
	{}
};

class Service
{
	public:
		//head of the list
		serv_node * head;
		
		//Constructor
		Service();

		//Destructor
		~Service();

		// Member functions
		void printList(); // print function. Prints every node with all of it's contents
		void addToBeginning(string n);  //adds string n into a node and adds that node to list
		serv_node* addToEnd (string str); //adds string n into a node and adds that node to list (+returns a pointer pointing to node)
		bool check(string func); //checks if string func is in list. return true if found, else false 
		serv_node* findptr(string str); //returns a pointer pointing at the node where string str is included
};

#endif