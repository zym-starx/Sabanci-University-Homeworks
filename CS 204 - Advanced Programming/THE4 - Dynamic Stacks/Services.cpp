//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#include <iostream>
#include <string>
#include "linkedlist.h"
#include "Services.h"

using namespace std;


//************************************************
// Constructor. Generates an empty list          *
//************************************************
Service::Service()
{
	head = NULL;
}

//************************************************
// Destructor.                                   *
//************************************************
Service::~Service()
{
	serv_node* current = head;
	while( current != 0 ) 
	{
		serv_node* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}

//********************************************
// Function addToEnd inserts string str at   *
// at the end of the list. And returns the   *
// the pointer to the newly added node       *
//********************************************
serv_node* Service::addToEnd (string str)
{
	serv_node * lastnode = head;
	serv_node *ptr = new serv_node(str);
	if(head == NULL)
	{
		head = ptr;
		return ptr;
	}

	while(lastnode->next != NULL)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = ptr;
	return ptr;
}

//********************************************
// Function check, checks if string func     *
// exists in the list(if found:returns true) *
//********************************************
bool Service::check(string func)
{
	serv_node * ptr = head;

	while (ptr != NULL)
	{
		if (ptr->info == func)
			return true; 
		else
			ptr = ptr->next;
	}
	return false;
}

//********************************************
// Function printList prints the entire list *
// with all of it's content.                 *
//********************************************
void Service::printList()
{
	serv_node* temp = head;

	while(temp != NULL)
	{
		cout << endl << temp->info << ":" << endl;
		temp->commands.printList();
		temp = temp->next;
	}
}

void Service::addToBeginning(string n)
{
	serv_node* temp = new serv_node(n);
	temp->next = head;
	head = temp;
}

//********************************************
// Function printList prints the entire list *
// with all of it's content.                 *
//********************************************
serv_node* Service::findptr(string str)
{
	serv_node * ptr = head;

	while (ptr != NULL)
	{
		if (ptr->info == str)
			return ptr; 
		else
			ptr = ptr->next;
	}
	return NULL;
}