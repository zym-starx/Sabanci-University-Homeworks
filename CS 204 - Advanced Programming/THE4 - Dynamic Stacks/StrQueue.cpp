//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from IntQueue.cpp from CS204    //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#include <iostream>
#include "StrQueue.h"
using namespace std;

//*****************************************
// Constructor - creates an empty queue   *
// with given number of elements          *
//*****************************************
StrQueue::StrQueue(int s)
{
	queueArray = new staticQueueNode[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;
	#ifdef DEBUGG
		cout << "A queue with " << s << " elements created\n";
	#endif
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void StrQueue::enqueue(string str, int id, string comm)
{
	if (isFull())
    { 
         cout << "The queue is full. Request is not enqueued\n";
    }
	else
	{
		// Calculate the new rear position circularly.
		rear = (rear + 1) % queueSize;
		// Insert new item.
		queueArray[rear].name = str;
		queueArray[rear].ID = id;
		queueArray[rear].command = comm;
		// Update item count.
		numItems++;
		#ifdef DEBUGG
			cout << name << "'s request is enqueued\n";
		#endif
	}
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void StrQueue::dequeue(staticQueueNode &num)
{
	if (isEmpty())
	{
       cout << "Attempting to dequeue on empty queue, exiting program...\n";
       exit(1);
    }
	else
	{
		// Move front.
		front = (front + 1) % queueSize;
		// Retrieve the front item.
		num = queueArray[front];
		// Update item count.
		numItems--;
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool StrQueue::isEmpty() const
{
	if (numItems > 0)
		return false;
	else
		return true;	
}

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise.             *
//********************************************
bool StrQueue::isFull() const
{
	if (numItems < queueSize)
		return false;
	else
		return true;
}

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0.         *
//*******************************************
void StrQueue::clear()
{
	front =  - 1;
	rear =  - 1;
	numItems = 0;
	#ifdef _DEBUG
		cout << "queue cleared\n";
	#endif
}

void StrQueue::PrintQueue()
{
	StrQueue temp(numItems);
	staticQueueNode ptr;

	cout << "Printing queue: " << endl;
	while (!isEmpty())
	{
		dequeue(ptr);
		cout << ptr.name << " :: " << ptr.ID << " :: " << ptr.command << endl;
		temp.enqueue(ptr.name, ptr.ID, ptr.command);
	}
	cout << endl;

	while (!temp.isEmpty())
	{
		temp.dequeue(ptr);
		enqueue(ptr.name, ptr.ID, ptr.command);
	}
}

//****************************************************
// Destructor for the queue. Pops all elements until *
// Queue is empty.                                   *
//****************************************************
StrQueue::~StrQueue()
{
	delete[] queueArray;
#ifdef DEBUGG
	cout << "[[Destructor for Queue is called]]" << endl;
#endif
}