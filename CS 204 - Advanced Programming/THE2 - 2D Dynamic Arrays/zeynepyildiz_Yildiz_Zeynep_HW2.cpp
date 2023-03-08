#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include "strutils.h"

using namespace std;

//Zeynep Yildiz 00029325
//last edited: 30.10.2021


struct courseNode
{
	string courseCode, courseName;
	vector<int> studentsAttendingIDs;
	courseNode * next;
};

int menu(courseNode *&head);  // menu function that gatheres up pretty much everything

int Search(courseNode* head, string code, courseNode *&ptr);  // checks if searched class is in linkedlist //taken from online resources and edited for further usage

int AdvancedSearch(courseNode* head, string code, int a, courseNode *&ptr); // Pretty much same as the Search function but this one also searches for int a inside linkedlist

int GiveIndexFromVector(vector <int> v, int num); //searches the int num in vector v and returns its index 

void printList(courseNode *head); //printing function for this specific type of linked list

void ExtractData(ifstream &courses_fs, courseNode * &head);  // extracts the data from txt file and makes it editable (with linkedlist)

void EmptyNode(courseNode &node);  // function for emptying a node

void AddToList(courseNode *&head); // option 1 function

void DropFromList(courseNode *&head);  // option 2 function

void Display(courseNode *head); // option 3 function

void FinishAddDrop(courseNode *head);  // option 4 function

void DeleteList(courseNode *&head);  // function for returning the linkedlist memory to heap

bool FindinVector(vector <int> vec, int num);   //returns true if num is found in vector. Taken from my code for the first homework for CS204

void SelectSort(vector<int> & a); // This function is taken from CS201 slides in 2020-2021 spring

void insert(vector<int> & a, int newnum); // adding to sorted vector func. This function is taken from CS201 slides in 2020-2021 spring

courseNode* AddInOrder(courseNode * &head, courseNode &willbeadded); //node adding to linkedlist function. Taken from CS204 lecture slides and edited for usage


/***************************************************************************************************/
/***************************************************************************************************/

int main()
{
	ifstream courses_fs;
	string courses_str;
	courseNode *head = NULL;
	cout << "Please enter file name: ";
	cin >> courses_str;
	courses_fs.open(courses_str.c_str());

	//open file control
	if (courses_fs.fail())
	{
		cout << "Cannot open the files. Exiting..." << endl;
		courses_fs.clear();
		return 0;
	}
	else
	{
		cout << "Succesfully opened file " << courses_str << endl;
		ExtractData(courses_fs, head);

		while (menu(head) == 0)
		{
			if (menu(head) == 1)
				break;
		}
	}
	courses_fs.close();
	DeleteList(head);
	system("pause");

	return 0;
}

bool FindinVector(vector <int> vec, int num)   //returns true if num is found in vector
{
	for (unsigned int a = 0; a < vec.size(); a++)
	{
		if (vec[a] == num)
			return true;
	}
	return false;
}

int menu(courseNode *&head)
{
	int choice;
	cout << "\n\nPlease select one of the choices: \n1. Add to List \n2. Drop from List \n3. Display List \n4. Finish Add/Drop and Exit\n\n";
	while (!(cin >> choice))
	{
		cout << "[ERROR] Please enter a valid input between 1-4" << endl;
		cin.clear();
		cin.ignore(10000,'\n');
	}
	
	if (choice == 1)
	{
		//Add to List
		AddToList(head);
	}
	else if (choice == 2)
	{
		//Drop from List
		DropFromList(head);
	}
	else if (choice == 3)
	{
		//Display List
		Display(head);
	}
	else if (choice == 4)
	{
		//Finish Add/Drop and Exit
		FinishAddDrop(head);
		return 1;
	}
	else
	{
		cout << "[INVALID INPUT] Please enter a valid input between 1-4" << endl;
	}

	return 0;
}

int GiveIndexFromVector(vector <int> v, int num)
{
	for (int a = 0; a < v.size(); a++)
	{
		if (v[a] == num)
		{
			return a;  //return index
		}
	}
	return -1;  //if num does not exist in v return -1;
}

int Search(courseNode* head, string code, courseNode *&ptr)
{
    courseNode* current = head;
    while (current != NULL)
    {
		if (current->courseCode == code)
		{
			ptr = current;  //change ptr to point at where courseCode is
            return 0;  //course found in linkedlist
		}
        current = current->next;
    }
    return 1;  //course not found in linkedlist
}

int AdvancedSearch(courseNode* head, string code, int a, courseNode *&ptr)
{
    courseNode* current = head;
    while (current != NULL)
    {
		if (current->courseCode == code)
		{
			ptr = current;
			if (FindinVector(current-> studentsAttendingIDs, a))
			{
				return 0; //student found in class
			}
			else 
			{
				return 1; //student not found in class
			}
		}
		current = current->next;
    }
    return 2; //class not found
}

void Display(courseNode *head)
{
	cout << "The current list of course and the students attending them:\n";
	printList(head);
}

void printList(courseNode *head) 
//this function is taken from CS204 materials linkedlist.cpp and edited for this homework
{
    if (head != NULL)
    {
		cout << head-> courseCode << "	" << head-> courseName << ": ";
		for (unsigned int a = 0; a < head -> studentsAttendingIDs.size(); a++)
		{
			cout << head-> studentsAttendingIDs[a] << "  ";
		}
		cout << endl;
        courseNode * ptr = head-> next;
        while(ptr != NULL)
        {
            cout << ptr->courseCode << "	" << ptr->courseName << ": ";
			for (unsigned int a = 0; a < ptr-> studentsAttendingIDs.size(); a++)
			{
				cout << ptr-> studentsAttendingIDs[a] << "  ";
			}
			cout << endl;
            ptr = ptr-> next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

void SelectSort(vector<int> & a)
// This function is taken from CS201 slides in 2020-2021 spring
{
	int j, k, temp, minIndex, numElts = a.size();
	for(k=0; k < numElts - 1; k++)
	{ 
		minIndex = k; // min element index
		for(j=k+1; j < numElts; j++)
		{ 
			if (a[j] < a[minIndex])
			{ 
				minIndex = j; // new min index
			}
		}
		temp = a[k]; // swap min and k-th
		a[k] = a[minIndex];
		a[minIndex] = temp;
	}
}

void EmptyNode(courseNode &node)
{
	vector <int> emptyvector;
	node.courseCode = "";
	node.courseName = "";
	node.studentsAttendingIDs = emptyvector;
	node.next = NULL;
}

void DeleteList(courseNode *&head)
//deleting the list 
{
   courseNode *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       delete(tmp);
    }
   head = NULL;
}

void AddToList(courseNode *&head)
{
	string word, addline, classcode, classname;
	cout << "Give the student ID and the course names and course codes that he/she wants to add: \n";
	cin.ignore();
	getline(cin, addline);
	courseNode *temp = new 	courseNode;
	EmptyNode(*temp);  //just a precaution
	istringstream addinput(addline);

	while (addinput >> word)
	{
		if(!('0' <= word[0] && word[0] <= '9'))
		{
			classcode = word;
			addinput >> word;
			classname = word;
		}
		else
		{
			int check = AdvancedSearch(head, classcode, atoi(word), temp);
			if (check == 0) //student found in class
			{
				cout << "Student with id " << atoi(word) << " already is enrolled to " << classcode << ". No action taken." << endl;
			}
			else if (check == 1) //student not found in class
			{
				insert(temp-> studentsAttendingIDs, atoi(word));
				cout << "Student with id " << word << " is enrolled to " << classcode << "." << endl;
			}
			else if (check == 2) //class not found in linkedlist
			{
				//creating a new class and adding it to linked list
				courseNode neww;
				EmptyNode(neww);  
				neww.courseCode = classcode;
				neww.courseName = classname;
				head = AddInOrder(head, neww);
				int check2 = AdvancedSearch(head, classcode, atoi(word), temp);
				insert(temp-> studentsAttendingIDs, atoi(word));

				cout << classcode << " does not exist in the list of Courses. It is added up." << endl;
				cout << "Student with id " << word << " is enrolled to " << classcode << "." << endl;
			}
			
		}
	}
}

void FinishAddDrop(courseNode *head)
{
	cout << "The add/drop period is finished. Printing the final list of courses and students attending them." << endl; 
	cout << "NOTE: Courses with less than 3 students will be closed this semester." << endl << endl;

	courseNode * ptr = head;

	while (ptr != NULL)
	{
		if (ptr->studentsAttendingIDs.size() < 3)
		{
			cout << ptr-> courseCode << "	" << ptr-> courseName << "  "; 
			for (unsigned int a = 0; a < ptr-> studentsAttendingIDs.size(); a++)
			{
				cout << ptr -> studentsAttendingIDs[a] << "  ";
			}
			cout << "  -> This course will be closed.";

		}
		else
		{
			cout << ptr-> courseCode << "	" << ptr-> courseName << ": ";
			for (unsigned int a = 0; a < ptr-> studentsAttendingIDs.size(); a++)
			{
				cout << ptr -> studentsAttendingIDs[a] << "  ";
			}
		}
		cout << endl;
		ptr = ptr->next;
	}
}

void DropFromList(courseNode *&head)
{
	string word, addline, classcode, classname;
	cout << "Give the student ID and the course names and course codes that he/she wants to drop: \n";
	cin.ignore();
	getline(cin, addline);
	courseNode *temp = new courseNode;
	istringstream addinput(addline);

	while (addinput >> word)
	{
		if(!('0' <= word[0] && word[0] <= '9'))
		{
			classcode = word;
			addinput >> word;
			classname = word;
		}
		else
		{
			int check = AdvancedSearch(head, classcode, atoi(word), temp);
			if (check == 2) //class not found in linkedlist
			{
				cout << "The " << classcode << " course is not in the list, thus student with id " << word << " can't be dropped." << endl;
			}
			else if (check == 1) //student not found in class
			{
				cout << "Student with id " << word << " is not enrolled to " << classcode << ", thus he can't drop that course." << endl;
			}
			else if (check == 0) //student found in class
			{
				int baa = GiveIndexFromVector(temp-> studentsAttendingIDs, atoi(word));
				temp-> studentsAttendingIDs.erase(temp->studentsAttendingIDs.begin() + baa);
				cout << "Student with id " << word << " has dropped " << classcode <<"." << endl;
			}
		}
	}
}

void insert(vector<int> & a, int newnum)  // This function is taken from CS201 slides from 2020-2021 spring lecture slides
{  		
// pre: a[0] <= … <= a[a.size()-1], a is sorted
// post: newnum inserted into a, a still sorted
    int count = a.size();  // size before insertion
    a.push_back(newnum);   // increase size –newnum is inserted at the
                   	// end but inserted value is not important
    int loc = count;      // start searching insertion loc from end
   
    while (loc > 0 && a[loc-1] > newnum){    
		a[loc] = a[loc-1]; 
		loc--;        // shift right until the proper insertion cell
    }
    a[loc] = newnum;  //actual insertion 
}

void ExtractData(ifstream &courses_fs, courseNode * &head)
{
	string line;
	while (getline(courses_fs, line))
	{
		string coursecode, coursename;
		int studentID;
		courseNode p;
		courseNode *ptr = new courseNode;
		istringstream input(line);
		input >> coursecode >> coursename >> studentID;
		int check = Search(head, coursecode, ptr);  //search if the course has added to linkedlist before
		
		if (check == 1) //if it doesn't exists in linked list
		{
			p.courseCode = coursecode;
			p.courseName = coursename;
			insert(p.studentsAttendingIDs, studentID);
			head = AddInOrder(head, p);
		}
		else if (check == 0) //if it exists in linked list
		{
			insert(ptr-> studentsAttendingIDs, studentID);
		}
	}
	cout << "The linked list is created." << endl;
	cout << "The initial list is: " << endl;
	printList(head);
}

courseNode* AddInOrder(courseNode * &head, courseNode &willbeadded)
//this function is taken from CS204 materials linkedlist.cpp and edited for this homework
{
	// pre: list is sorted
	// post: add newkey to list, keep list sorted, return head of new list
	courseNode *  ptr = head;   // loop variable

	// if new node should be first, handle this case and return  
	// in this case, we return address of new node since it is new head  
	if (head == NULL || willbeadded.courseName <= head->courseName)        
	{   
		courseNode * temp = new courseNode;  //node to be inserted 
		temp->courseCode = willbeadded.courseCode;
		temp->courseName = willbeadded.courseName;
		temp->studentsAttendingIDs = willbeadded.studentsAttendingIDs;
		temp->next = head; //connect the rest
		return temp;
	}

    // check node one ahead so we don't pass!
	while (ptr -> next != NULL && ptr -> next -> courseName < willbeadded.courseName)
    {    
		ptr = ptr->next;
    } // postcondition: new node to be inserted just after the node ptr points

    //now insert new node with newkey after where ptr points to
	courseNode * temp = new courseNode;  //node to be inserted
	temp->courseName = willbeadded.courseName;
	temp->courseCode = willbeadded.courseCode;
	temp->next = ptr->next; //connect the rest
	ptr->next = temp;
	return head;
}