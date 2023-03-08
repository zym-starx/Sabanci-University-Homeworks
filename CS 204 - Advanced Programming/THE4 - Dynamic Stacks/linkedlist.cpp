//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from linkedlist.cpp from CS204  //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;


//************************************************
// Constructor. Generates an empty list          *
//************************************************
linkedlist::linkedlist ()
{
	head = NULL;
}

//************************************************
// Destructor.                                   *
//************************************************
linkedlist:: ~linkedlist()
{
	node* current = head;
	while( current != 0 ) 
	{
		node* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}

//********************************************
// Function addToEnd inserts string n at     *
// at the beginning of the list.             *
//********************************************
void linkedlist::addToBeginning (string n)
{
	node *ptr = new node(n);
    head = ptr;		
}	

//********************************************
// Function addToEnd inserts string str at   *
// at the end of the list.                   *
//********************************************
void linkedlist::addToEnd (string str)
{
	node * lastnode = head;
	node *ptr = new node(str);
	if(head == NULL)
	{
		head = ptr;
		return;
	}
	
	while(lastnode->next != NULL)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = ptr;
}

//********************************************
// Printing function for the list. Prints    *
// every element with it's content           *
//********************************************
void linkedlist::printList ()
{
	node * ptr = head;
	while (ptr->next != NULL) 
	{
		cout << ptr->info << ", ";
		ptr = ptr->next;
	}
	cout << ptr->info << ". " << endl;
}