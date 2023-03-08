// Zeynep Yildiz 00029325

//just a heads up (fyi):
//there are many debug checks if it's run in debug mode
//two different debug modes: "_DEBUG" and "DEBUGG"
//DEBUGG was to check if functions in other cpp files are working well 
//_DEBUG is to check if functions here works well

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DynStrStack.h"
#include "DynStrQueue.h"
#include "linkedlist.h"
#include "Services.h"
#include "StrQueue.h"

using namespace std;

Service services;

DynStrQueue StudentQueue;

DynStrStack Stack;

StrQueue InstructorQueue(5);


void processARequest();

void processARequest(string functionName);

void addStudentRequest();

void addInstructorRequest();

void GetServices();                  //function to ask the user for more input files. Actively uses "ExtractData(string)"

bool isNumber(const string& str);    //felt cute might delete later

bool inputcheck(string &choice);     /*function to check if the entered choice has length 1. Otherwise asks for input 
                                     again. Idk, I accidentally click two letters everytime. Might as weel add it. */
void ExtractData(string input_str);  //function to extract the data from every txt file that has been entered


//#define DEBUGG

int main()
{
#ifdef _DEBUG
	cout << "Welcome to the --- world that you and I are living in" << endl << endl;
#endif

	GetServices();


	while (true)
	{ 
		cout << endl;
		cout << "*********************************************************************" << endl 
			 << "**************** 0 - EXIT PROGRAM                       *************" << endl 
			 << "**************** 1 - ADD AN INSTRUCTOR SERVICE REQUEST  *************" << endl 
			 << "**************** 2 - ADD A STUDENT SERVICE REQUEST      *************" << endl 
			 << "**************** 3 - SERVE (PROCESS) A REQUEST          *************" << endl 
			 << "*********************************************************************" << endl; 
		cout << endl; 
		int option; 
		cout << "Pick an option from above (int number from 0 to 3): "; 
		cin>>option; 
		switch (option) 
		{ 
		case 0: 
			cout<<"PROGRAM EXITING ... " << endl;
			system("pause"); 
			exit(0); 
		case 1: 
			addInstructorRequest(); 
			break; 
		case 2: 
			addStudentRequest(); 
			break; 
		case 3: 
			processARequest();
			break; 
		default: 
			cout<<"INVALID OPTION!!! Try again"<<endl; 
		}//switch 
	}//while (true)

	return 0;
}

//**********************************************************************//
//*                      Function definitions                          *//
//**********************************************************************//

void GetServices()
{
	cout << "If you want to open a service (function) defining file, then press (Y/y) for 'yes', otherwise press any single key" << endl;
	string choice;
	getline(cin, choice);
	if (inputcheck(choice))
	{
		if (choice == "Y" || choice == "y")
		{
			bool ee = true;
			while(ee)
			{
				string input_str;
				cout << "Enter the input file name: ";
				cin >> input_str;

				ExtractData(input_str);

				cout << "Do you want to open another service defining file?" << endl;
				cout << "Press (Y/y) for 'yes', otherwise press anykey" << endl;
				cin >> choice;
				inputcheck(choice);
				if (choice != "Y" && choice != "y")
				{
					ee = false;  //break the loop
					cout << "-------------------------------------------------------------------------" << endl;
					cout << "   PRINTING AVAILABLE SERVICES (FUNCTIONS) TO BE CHOSEN FROM THE USERS   " << endl;
					cout << "-------------------------------------------------------------------------" << endl;
					services.printList();
					cout << endl;
					system("pause");
				} //otherwise, loop again
			}
		}
	}
}

void ExtractData(string input_str)
{
	ifstream input_fs;
	string line;

	input_fs.open(input_str.c_str());
	if (input_fs.fail())
	{
		cout << "[ERROR]: File cannot be opened. (File name wrong?)" << endl;
		input_fs.clear();
		cout << "PROGRAM EXITING ... " << endl; 
		system("pause"); 
		exit(0); 
	}
	else
	{
		getline(input_fs, line);
		line.pop_back();
		serv_node* ptr = services.addToEnd(line);
		while(getline(input_fs, line)) // add every line after first line as a command in service
		{
			line.pop_back(); // to get rid of ";" at the end;
			ptr->commands.addToEnd(line);
		}

#ifdef _DEBUG
		cout << "---------[DEBUG start]---------";
		services.printList();
		cout << "---------[DEBUG end]---------";
#endif

	}
}

bool inputcheck(string &choice)
{
	if (choice.length() == 1)
	{
		return true;
	}
	while (choice.length() > 1)
	{
		cout << "[WARNING]: Typo? Please re-enter your choice" << endl;
		getline(cin, choice);
	}
	return true;
}

bool isNumber(const string& str)
{
	for(unsigned int a = 0; a < str.length(); a++)
	{
		if (!(str[a] <= '9' && str[a] >= '0'))
		{
			return false;
		}
	}
	return true;
}

void addInstructorRequest()
{
	cout << "Add a service <function> that the instructor wants to use:" << endl;
	string function;
	cin >> function;
	if (!services.check(function))
	{
		cout << "The requested service <function> does not exist." << endl;
		cout << "GOING BACK TO MAIN MENU" << endl;
		return;
	}
	else
	{
		string name, str_id;
		int id = 0;
		cout << "Give instructor's name: ";
		cin >> name;
		cout << "Give instructor's ID (an int): ";
		cin >> str_id;

		while (!isNumber(str_id))
		{
			cout << "ID must be an integer. Please enter again: ";
			cin >> str_id;
		}

		stringstream processid(str_id);		
		processid >> id;

		if (InstructorQueue.isFull())
		{
			cout << "Queue for instructor is full. Please process some requests first." << endl;
			return;
		}

		InstructorQueue.enqueue(name, id, function);
		cout << "Prof. " << name << "'s service request of " << function
			<<  " has been put in the instructor's queue." << endl;
		cout << "Waiting to be served..." << endl;

#ifdef _DEBUG
	cout << "---------[DEBUG start]---------";
	InstructorQueue.PrintQueue();
	cout << "---------[DEBUG end]---------";
#endif
	}
}

void addStudentRequest()
{
	cout << "Add a service <function> that the student wants to use:" << endl;
	string function;
	cin >> function;
	if (!services.check(function))
	{
		cout << "The requested service <function> does not exist." << endl;
		cout << "GOING BACK TO MAIN MENU" << endl;
		return;
	}
	else
	{
		string name;
		int id;
		cout << "Give student's name: ";
		cin >> name;
		cout << "Give student's ID (an int): ";
		while(!(cin >> id)) 
		{
			string garbage;
			cin.clear();
			cin.ignore();
			getline(cin,garbage);
			cout << "ID must be an integer. Please enter again: ";
		}

		StudentQueue.enqueue(name, id, function);

		cout << "Prof. " << name << " service request of " << function
			<<  " has been put in the student's queue." << endl;
		cout << "Waiting to be served..." << endl;
	}

#ifdef _DEBUG
	cout << "---------[DEBUG start]---------";
	StudentQueue.PrintQueue();
	cout << "---------[DEBUG end]---------";
#endif
}

void processARequest(string functionName) 
{ 
	serv_node* ptr = services.findptr(functionName);
	node* temp = ptr->commands.head;
	while (temp != NULL) 
	{
		string command, garbage;
		istringstream commandtool(temp->info);
		commandtool >> command >> garbage;
		if(command == "define") 
		{ 
			string wba;
			wba = command + " " + garbage;
			Stack.push(wba, functionName);
		}
		else if (command == "call") 
		{ 
			// the recursion goes here
			cout << "Calling " << garbage << " from " << functionName << endl;
			processARequest(garbage); 
		}
		else 
		{
			cout << "PRINTING THE STACK TRACE: " << endl;
			Stack.PrintStack();
		}
		temp = temp->next;
		
	} // while 
	//… 
	// delete this function’s data from the top of the stack
	Stack.con_clear(functionName);
	cout << functionName << " is finished. Clearing the stack from it's data... " << endl; 
	system("pause");
}

void processARequest() 
{ 
	if (!InstructorQueue.isEmpty()) 
	{ 
		//if instructors queue is not empty, process the next request
		string functionName;
		staticQueueNode temp;
		InstructorQueue.dequeue(temp);
		cout << "Processing Prof. " << temp.name << "'s request (with ID " << temp.ID 
			 << ") of service (function) :" << endl << temp.command << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		functionName = temp.command;
		processARequest(functionName);
		Stack.clear();
		Stack.PrintStack();
		cout << "GOING BACK TO MAIN MENU" << endl;
	}
	else if (!StudentQueue.isEmpty()) 
	{ 
		//if instructors queue is empty and student’s not, 
		//then process the next student request 
		cout << "Instructors queue is empty. Proceeding with students queue..." << endl;
		string functionName;
		QueueNode temp;
		StudentQueue.dequeue(temp);
		cout << "Processing " << temp.name << "'s request (with ID " << temp.ID 
			<< ") of service (function) :" << endl << temp.command << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		functionName = temp.command;
		processARequest(functionName);
		Stack.clear();
		Stack.PrintStack();
		cout << "GOING BACK TO MAIN MENU" << endl;
	}
	else 
	{ 
		// otherwise… 
		cout << "Both instructor's and student's queue is empty.\nNo request is processed." 
			<< endl << "GOING BACK TO MAIN MENU"<<endl; 
	}
} 