//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//
// this file is copied from IntQueue.h from CS204      //
// class resources and edited for this homework        //
//-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-:-//

#ifndef STRQUEUE_H
#define STRQUEUE_H

#include <string>
using namespace std;

struct staticQueueNode
{
	string name;
	string command;
	int ID;
	staticQueueNode* next;

	staticQueueNode()
	{
		ID = 0;
		next = NULL;
	}

	staticQueueNode(string str, int id, string comm)
	{
		name = str;
		ID = id;
		command = comm;
		next = NULL;
	}
};

class StrQueue
{
private:
	staticQueueNode *queueArray;
	int queueSize;  //capacity of queue
	int front;
	int rear;
	int numItems;  //# of elements currently in the queue
public:
	StrQueue(int);  //constructor, parameter is capacity

	~StrQueue();    //destructor

  	void enqueue(string str, int id, string comm);
  	void dequeue(staticQueueNode &);
  	bool isEmpty() const; 
  	bool isFull() const;
	void PrintQueue();
  	void clear();  //removes all elements
};
#endif