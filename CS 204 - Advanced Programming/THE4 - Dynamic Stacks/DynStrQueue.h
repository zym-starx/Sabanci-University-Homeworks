//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from DynIntQueue.h from CS204   //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#ifndef DYNSTRQUEUE_H
#define DYNSTRQUEUE_H

#include <string>
using namespace std;

struct QueueNode
{
	string name;
	string command;
	int ID;
	QueueNode *next;

	QueueNode()
	{
		ID = 0;
		next = NULL;
	}

	QueueNode(string str, int id, string comm)
	{
		name = str;
		ID = id;
		command  = comm;
		next = NULL;
	}
};

class DynStrQueue
{
private:
	// These track the front and rear of the queue.
	QueueNode *front;
	QueueNode *rear;	
public:
	// Constructor.
	DynStrQueue();

	 // Destructor
	~DynStrQueue();
	
	// Member functions.
	void enqueue(string, int, string);
	void dequeue(QueueNode &node);
	bool isEmpty() const;
	void PrintQueue();
	void clear();
};
#endif