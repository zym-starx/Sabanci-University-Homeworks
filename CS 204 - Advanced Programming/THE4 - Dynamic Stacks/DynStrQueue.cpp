//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from DynIntQueue.cpp from CS204 //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#include <iostream>
#include <string>
#include "DynStrQueue.h"
using namespace std;

//************************************************
// Constructor. Generates an empty queue         *
//************************************************
DynStrQueue::DynStrQueue()
{
	front = NULL;
	rear = NULL;   
	#ifdef _DEBUG
		cout << "[DEBUG]" << "An empty queue has been created\n";
	#endif
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void DynStrQueue::enqueue(string str, int id, string comm)
{       
	if (isEmpty())   //if the queue is empty
	{	//make it the first element
		front = new QueueNode(str, id, comm);
		rear = front;
	}
	else  //if the queue is not empty
	{	//add it after rear
		rear->next = new QueueNode(str, id, comm);
		rear = rear->next;
	} 
	#ifdef _DEBUG
		cout << str << " enqueued\n";
	#endif
}

//**********************************************
// Function dequeue removes the node at the    *
// front of the queue, and copies it into node. *
//**********************************************
void DynStrQueue::dequeue(QueueNode &node)
{
	QueueNode *temp;
	if (isEmpty())
	{
		cout << "Attempting to dequeue on empty queue, exiting program...\n";
		exit(1);
	}
	else //if the queue is not empty
	{	//return front's value, advance front and delete old front
		node = *front;
		temp = front;
		front = front->next;
		delete temp;      
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynStrQueue::isEmpty() const
{
	if (front == NULL)
		return true;
	else 
		return false;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue. (destructor??)              *
//********************************************
void DynStrQueue::clear()
{
	QueueNode value;   // Dummy variable for dequeue

	while(!isEmpty())
		dequeue(value); //delete all elements
	#ifdef _DEBUG
		cout << "[DEBUG]" << "queue cleared\n";
	#endif
}

//****************************************************
// Destructor for the queue. Pops all elements until *
// Queue is empty.                                   *
//****************************************************
DynStrQueue::~DynStrQueue()
{
	QueueNode a;
	while(!isEmpty())
	{
		dequeue(a);
	}
#ifdef DEBUGG
	cout << "[[Destructor for Queue is called]]" << endl;
#endif
}


//****************************************************
// Printing function for queue. Mostly used for      *
// debug purposes.                                   *
//****************************************************
void DynStrQueue::PrintQueue()
{
	DynStrQueue temp;
	QueueNode ptr;

	cout << "Printing queue: " << endl; 
	while(!isEmpty())
	{
		dequeue(ptr);
		cout << ptr.name << " :: " << ptr.ID << " :: " << ptr.command << endl;
		temp.enqueue(ptr.name, ptr.ID, ptr.command);
	}
	cout << endl;

	while(!temp.isEmpty())
	{
		temp.dequeue(ptr);
		enqueue(ptr.name, ptr.ID, ptr.command);
	}
}