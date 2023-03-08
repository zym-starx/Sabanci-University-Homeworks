#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

#define DEBUG

// Zeynep Yildiz 00029325

/* Just a heads up:  I tried to explain as simply as I can but since I didnt use classes this might me a little complicated*/

struct busStop 
{
	string busStopName;
	busStop *left;
	busStop *right;

	busStop() // constructor
	{
		busStopName = "";
		left = NULL;
		right = NULL;
	}
	busStop::busStop(string stopname)  // constructor with variables
		:busStopName(stopname),
		left(NULL),
		right(NULL)
	{
	}
};

struct busLine 
{
	string busLineName;
	busLine *next;
	busStop *busStops;

	busLine()  //constructor
	{
		busLineName = "";
		next = NULL;
		busStops = NULL;
	}

	busLine::busLine(string linename)  //constructor with variables
		:busLineName(linename),
		next(NULL),
		busStops(NULL)
	{
	}
};

busLine* head = nullptr;

bool strCheck(string str);   //returns true if str does not have any space characters. Else returns false

bool Scan2D(string str);    //scans the entire table for str. Returns false if not found

bool DLcheck(busStop *ptr, busStop * wba);  //returns true if pointer wba is found in ptr

bool DLstringcheck(busStop *ptr, string str);  //returns true if str is found in ptr

bool LLcheck(string str, busLine *&temp);  //changes temp to where str is. Returns true/false depending on case if str is found or not. if not found temp is NULL

bool LLcheck_prev(string str, busLine *&temp);   //changes temp to previous node of the node that has str in it

void printSingleBusline(busLine *ptr);  //print out the contents of ptr (a bus line)

void AddtoSLfront(busLine *&ptr);  //adds ptr to at the beginning of head

void AddtoSLback(busLine * &wba);  //adds ptr to at the end of head

void AddtoDLfront(busStop * &ptr, busStop * &bs);  //adds bs at the beginning of ptr

void AddtoDLback(busStop * &ptr, busStop * &bs);  //adds bs at the end of ptr

void DeleteList();  //deletes the entire 2d data

void ExtractData(ifstream &busline_fs);  //extracts data from txt file and adds it to head

busStop *Findptr(busStop *&ptr, string str);  //returns pointer that points to where str is found



busStop* SearchPath(busLine* line, string start, string end, char &ch);  // was gonna use this for the bonus but couldn't make it work in time 
// (*ehem* midterms *ehem* [not that I did any good]) so I'm just gonna let 
// it stay here. I dont use it in this version of the program anyway 



bool consistencyCheck();  //\\
                          // \\-
void printMainMenu();     //  \\
                          //   \\-
void printBusLines();     //    \\
                          //     \\-
void processMainMenu();   //      \\
                          //       \\-
void addBusLine();        //          >>>>>>>>>  Functions from hw pdf file
                          //       //
void addBusStop();        //      //
                          //     //
void deleteBusLine();     //    //
                          //   //
void deleteBusStop();     //  //
                          // //
void pathfinder();        ////



int main()
{
	ifstream busline_fs;
	string busline_str = "busLines.txt";
	busline_fs.open(busline_str.c_str());

	//open file control
	if (busline_fs.fail())
	{
#ifdef DEBUG
		cout << "Cannot open the files. Exiting..." << endl;
#endif
		busline_fs.clear();
		return 0;
	}
	else
	{
#ifdef DEBUG
		cout << "Succesfully opened file " << busline_str << endl;
#endif
		ExtractData(busline_fs);

#ifdef DEBUG
		printBusLines();
#endif

		processMainMenu();
	}
	busline_fs.close();
	DeleteList();
	system("pause");

	return 0;
}


//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * /
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void printMainMenu() 
{
	cout << endl;
	cout <<"I***********************************************I"<<endl
	<<"I 0 - EXIT PROGRAM I"<<endl
	<<"I 1 - PRINT LINES I"<<endl
	<<"I 2 - ADD BUS LINE I"<<endl
	<<"I 3 - ADD BUS STOP I"<<endl
	<<"I 4 - DELETE BUS LINE I"<<endl
	<<"I 5 - DELETE BUS STOP I"<<endl
	<<"I 6 - PATH FINDER I"<<endl
	<<"I***********************************************I"<<endl
	<<">>";
	cout << endl;
}

bool consistencyCheck() {
	busLine* currBL = head; //a global variable
	while(currBL) 
	{
		busStop* currBS = currBL->busStops;
		while(currBS) 
		{
			busStop* rightBS = currBS->right;
			if(rightBS && rightBS->left != currBS) 
			{
				cout << "Inconsistency for " << currBL->busLineName
				<< " " << currBS->busStopName << endl;
				return false;
			}
			currBS = currBS->right;
		}
	currBL = currBL->next;
	}
	return true;
}

void processMainMenu() 
{
	char input;
	do
	{
		if(!consistencyCheck()) 
		{
			cout << "There are inconsistencies. Exit." << endl;
			return;
		}

		printMainMenu();
		cout << "Please enter your option " << endl;
		cin >> input;
		switch (input) 
		{
		case '0':
			cout << "Thanks for using our program" << endl;
			return;
		case '1':
			printBusLines();
			break;
		case '2':
			addBusLine();
			break;
		case '3':
			addBusStop();
			break;
		case '4':
			deleteBusLine();
			break;
		case '5':
			deleteBusStop();
			break;
		case '6':
			pathfinder();
			break;
		default:
			cout << "Invalid option: please enter again" << endl;
		} //switch
	} while(true);
}//processMainMenu

void printBusLines()
{
	busLine *temp = new busLine;
	temp = head;
	while (temp != NULL)
	{
		printSingleBusline(temp);
		cout << endl;
		temp = temp->next;
	}
	delete(temp);
}

void addBusLine()
{
	cout << "Enter the name of the new bus line (0 for exit to main menu)." << endl;
	string bline; 
	cin.ignore();
	getline(cin, bline);

	if(bline == "0")
	{
		return;
	}
	else
	{
		string sure = "N";
			while (!strCheck(bline))
			{
				getline(cin, bline);
			}
			busLine *willbeadded = new busLine(bline);

			string bstop = "420";
			while(bstop != "0")
			{
				while (!strCheck(bstop))
				{
					cin >> bstop;
				}
				cout << "Enter the name of the next bus stop (enter 0 to complete)" << endl;
				cin >> bstop;
				if (bstop != "0")
				{
					busStop *temp = new busStop(bstop);
					if (DLcheck(willbeadded->busStops, temp) == false)
					{	
						AddtoDLback(willbeadded->busStops, temp);
					}
					else
					{
						delete(temp);
					}
				}
			}

			cout << "The bus line information is shown below:" << endl;
			printSingleBusline(willbeadded);

			cout << endl << "Are you sure? Enter (y/Y) for yes (n/N) for no?";
			cin >> sure;
			if (!(sure == "N" || sure == "n" || sure == "y" || sure == "Y"))
			{
				while (!(sure == "N" || sure == "n" || sure == "y" || sure == "Y"))
				{
					cout << endl << "[WARNING] Typo? Please enter your choice again:";
					cin >> sure;
				}
				if (sure == "y" || sure == "Y")
				{
					AddtoSLfront(willbeadded);
					return;
				}
				else
				{
					delete(willbeadded);
					return;
				}
			}
			if (sure == "y" || sure == "Y")
			{
				AddtoSLfront(willbeadded);
				return;
			}
			else if (sure == "n" || sure == "N")
			{
				delete(willbeadded);
				return;
			}
	}
}

void addBusStop()
{
	cout << "Enter the name of the new bus line (0 for exit to main menu)." << endl;
	string bline; 
	cin.ignore();
	getline(cin, bline);
	busLine *ptr;

	if(bline == "0")
	{
		return;
	}
	else if(!LLcheck(bline, ptr))
	{
		cout << "Bus line cannot be found. Going back to previous menu." << endl;
		return;
	}
	else
	{
		cout << "The bus line information is shown below: " << endl;
		printSingleBusline(ptr); cout << endl;
		string bstop;
		cout << "Enter the name of the new bus stop: ";
		cin >> bstop;

		while (!strCheck(bstop))
		{
			cin >> bstop;
		}
		if(DLstringcheck(ptr->busStops, bstop))
		{
			cout << "Bus stop already exists. Going back to previous menu." << endl;
			return;
		}
		else
		{
			cout << "Enter the name of the previous bus stop to put the new one after it (0 to put the new one as the first bus stop): " << endl;
			string prev_bstop;
			cin >> prev_bstop;

			busStop *temp = new busStop(bstop);
			if (prev_bstop != "0")
			{
				if(!DLstringcheck(ptr->busStops, prev_bstop))
				{
					while(!DLstringcheck(ptr->busStops, prev_bstop))
					{
						cout << "Bus stop does not exist. Typo? Enter again (0 for main menu)" << endl;
						cin >> prev_bstop;
						if (prev_bstop == "0")
						{
							return;
						}
					}
				}
				if (DLstringcheck(ptr->busStops, prev_bstop))
				{
					busStop *prev = Findptr(ptr->busStops, prev_bstop);
					temp->right = prev->right;
					temp->left = prev;
					prev->right = temp;
					prev->right->right->left = temp;

#ifdef DEBUG
					cout << "prev->right->right    prev->right    temp->right    temp->right->left" << endl << endl;
					cout << endl << endl <<prev->right->right->busStopName << " <-> ";
					cout << prev->right->busStopName << " <-> ";
					cout << temp->right->busStopName << " <-> ";
					cout << temp->right->left->busStopName << " <-> " << endl << endl;
#endif
				}
			}
			else
			{
				AddtoDLfront(ptr->busStops, temp);
			}
			printBusLines();
		}
	}
}

void deleteBusLine()
{
	string bline;
	cout << "Enter the name of the bus line to delete: ";
	cin >> bline;
	busLine *ptr;

	if (LLcheck(bline, ptr) == false)
	{
		cout << "Bus line cannot be found. Going back to the previous (main) menu." << endl;
		return;
	}
	else
	{
		if (ptr == head)
		{
			head = ptr->next;
			delete(ptr);
		}
		else
		{
			busLine *prev;
			LLcheck_prev(bline, prev);
			prev->next = ptr->next;
			delete(ptr);
		}
		cout << endl << endl; printBusLines();
	}
}

void deleteBusStop()
{
	cout << "Enter the name of the bus line to delete a new bus stop (0 for main menu): " << endl;
	string bline;
	cin >> bline;
	busLine *ptr;

	if (LLcheck(bline, ptr) == false)
	{
		cout << "Bus line cannot be found. Going back to the previous (main) menu." << endl;
		return;
	}
	else
	{
		cout << "The bus line information is shown below: " << endl;
		printSingleBusline(ptr);
		cout << endl <<"Enter the name of the bus stop to delete (0 for main menu)" << endl;
		string bstop;
		cin >> bstop;

		if (bstop == "0")
		{
			return;
		}
		while (!DLstringcheck(ptr->busStops, bstop))
		{
			cout << "Bus stop cannot be found. \nEnter the name of the bus stop to delete (0 for main menu)" << endl;
			cin >> bstop;
			if (bstop == "0")
				return;
		}

		busStop *stop_ptr = Findptr(ptr->busStops, bstop);
		if (stop_ptr != NULL) //this "if" should always executed since we checked above, but why not two checks 
		{
			if (stop_ptr == ptr->busStops)
			{
				ptr->busStops = stop_ptr->right;
				delete(stop_ptr);
			}
			else
			{
				if(stop_ptr->right != NULL)
				{
					stop_ptr->left->right = stop_ptr->right;
					stop_ptr->right->left = stop_ptr->left;
					delete(stop_ptr);
				}
				else
				{
					stop_ptr->left->right = NULL;
					delete(stop_ptr);
				}
			}
		}

		if (ptr->busStops == NULL)
		{
			if (ptr == head)
			{
				head = ptr->next;
				delete(ptr);
			}
			else
			{
				busLine *prev;
				LLcheck_prev(bline, prev);
				prev->next = ptr->next;
				delete(ptr);
			}
		}
		cout << endl;
		printBusLines();
	}
}

void pathfinder()
{
	busLine* ptr = head;
	string start, end;
	cout << "Where are you now?" << endl;
	cin >> start;
	if (!Scan2D(start))
	{
		cout << "Bus stop does not exist in the table. Going back to previous menu." << endl;
		return;
	}

	cout << "Where do you want to go?" << endl;
	cin >> end;
	if (!Scan2D(end))
	{
		cout << "Bus stop does not exist in the table. Going back to previous menu." << endl;
		return;
	}

	/*********************************************/

	int count = 0;
	busStop* pstart = NULL;
	char c = 'N';
	while (ptr != NULL)
	{
		pstart = SearchPath(ptr, start, end, c);
		if (pstart != NULL)  // if both of the busstops are found in a single bus line
		{
			count++;
			cout << endl << "You can go there by " << ptr->busLineName << ": ";
			if (c == 'R')
			{
				busStop* ee = pstart; 
				while (ee->busStopName != end)
				{
					cout << ee->busStopName << " <-> ";
					ee = ee->right;
				}
				cout << ee->busStopName;
			}
			else if (c == 'L')
			{
				busStop* ee = pstart; 
				while (ee->busStopName != end)
				{
					cout << ee->busStopName << " <-> ";
					ee = ee->left;
				}
				cout << ee->busStopName;
			}
		}
		ptr = ptr->next;
	}

	if (count != 0)  
		return;
	else  // if no buslines are printed before now is the time for interchanges
	{
		cout << "Sorry no path from " << start << " to " << end << " could be found." << endl;

		/* // cout << "There is no direct transportation avaible but " << endl;
		count = 0;

		ptr = head;
		while (ptr != NULL)  // if start point is found in line
		{
			if (Findptr(ptr->busStops, start) != NULL)
			{
			busStop* midpoint1 = ptr->busStops;  // find a transaction point
			while (midpoint1 != NULL)
			{
				if (midpoint1->busStopName != start)
				{
					ptr = head;
					while (ptr != NULL)
					{
						pstart = SearchPath(ptr, midpoint1->busStopName, end, c);
						if (pstart == NULL)
						{
							char nw;
							cout << endl << "You can go there by " << ptr->busLineName << ": ";
							busStop* bs = SearchPath(ptr, start, midpoint1->busStopName, nw);
							if (nw == 'R')
							{
								busStop* ee = bs;
								while (ee->busStopName != end)
								{
									cout << ee->busStopName << " <-> ";
									ee = ee->right;
								}
								cout << ee->busStopName;
							}
							else if (nw == 'L')
							{
								busStop* ee = pstart;
								while (ee->busStopName != end)
								{
									cout << ee->busStopName << " <-> ";
									ee = ee->left;
								}
								cout << ee->busStopName;
							}


							cout << endl << ptr->busLineName << ": ";
							if (c == 'R')
							{
								busStop* ee = pstart;
								while (ee->busStopName != end)
								{
									cout << ee->busStopName << " <-> ";
									ee = ee->right;
								}
								cout << ee->busStopName;
							}
							else if (c == 'L')
							{
								busStop* ee = pstart;
								while (ee->busStopName != end)
								{
									cout << ee->busStopName << " <-> ";
									ee = ee->left;
								}
								cout << ee->busStopName;
							}
						}
					}
				}
				midpoint1 = midpoint1->right;
			}

			ptr = ptr->next;
		}
		}
	}  */
	}
}

void printSingleBusline(busLine *ptr)
{
	busStop *temp = new busStop;
	temp = ptr->busStops;
	cout << ptr->busLineName << ": ";
	while (temp != NULL)
	{
		cout << temp->busStopName << " ";
		if (temp->right != NULL)
			cout << "<-> ";
		temp = temp->right;
	}
	delete(temp);
}

void DeleteList()
//deleting the list 
{
	busLine *tmp;
	while (head != NULL)
    {
       tmp = head;
	   busStop *tmp2 = tmp->busStops;
	   busStop *tmp20;
       head = head->next;
	   while (tmp != NULL)
	   {
		   tmp20 = tmp2;
		   tmp2 = tmp2->right;
		   delete(tmp20);
	   }

       delete(tmp);
    }
	head = NULL;
}

void ExtractData(ifstream &busline_fs)
{
	string line;

	while(getline(busline_fs, line))  // get every line and turn it to a bus line
	{
		string busline_name, busstop_name;
		istringstream input(line);
		input >> busline_name;
		busline_name.pop_back();

		busLine *ptr = new busLine(busline_name);  // create new busline

		if (head == NULL)
		{
			while(input >> busstop_name)
			{
				busStop *willbeadded = new busStop(busstop_name);  // add bus stop to bus line

				AddtoDLback(ptr->busStops, willbeadded);  // every other word after bus line name is bus stop and added to double linked list
			}
			head = ptr;  // head was null. so now ptr is head
		}
		else
		{
			while(input >> busstop_name)
			{
				busStop *willbeadded = new busStop(busstop_name);

				AddtoDLback(ptr->busStops, willbeadded);
			}
			AddtoSLback(ptr);  // add to end of single linkedlist
		}
	}
}

void AddtoDLfront(busStop * &ptr, busStop * &bs)
	//this function adds bs to the head of doublylinked list ptr
{
	if(ptr == NULL)
	{
		ptr = bs;

	}
    else
    {
        bs->right = ptr;
		ptr->left = bs;
    }
	
}

void AddtoDLback(busStop * &ptr, busStop * &bs)  
	//ptr is head of doubly linkedlist, bs is the node will be added
	//this function adds bs to end of doublylinked list ptr
{
	if(ptr == NULL)
	{
		ptr = bs;

	}
    //Otherwise, find the last node and add the newNode
    else
    {
        busStop *lastNode = ptr;
        
        //last node's next address will be NULL.
        while(lastNode->right != NULL)
        {
            lastNode = lastNode->right;
        }


        //add the newNode at the end of the linked list
        lastNode->right = bs;
		bs->left = lastNode;
    }
}

void AddtoSLfront(busLine *&ptr)
{
	ptr->next = head;
	head = ptr;
}

void AddtoSLback(busLine * &wba)  
	//add to linkedlist // wba stands for will be added
{
	busLine *lastNode = head;
	while(lastNode->next != NULL)
    {
		lastNode = lastNode->next;
	}

	lastNode->next = wba;
}

bool DLcheck(busStop *ptr, busStop * wba)
{
	//ptr is the head of list
	busStop * temp = ptr;
	if (ptr == NULL)
	{
		return false;  //wba doesnt exist in ptr
	}

	while(temp != NULL)
	{
		if (temp->busStopName == wba->busStopName)
		{
			cout << "Bus stop already exists in the line" << endl;
			return true;  //wba exists in ptr
		}
		temp = temp->right;
	}
	return false;  //wba doesnt exist in ptr
}

bool DLstringcheck(busStop *ptr, string str)
{
	//ptr is the head of list
	busStop * temp = ptr;
	if (ptr == NULL)
	{
		return false;
	}

	while(temp != NULL)
	{
		if (temp->busStopName == str)
		{
			return true;
		}
		temp = temp->right;
	}
	return false;
}

bool LLcheck(string str, busLine *&temp)
	//changes temp to where str is
	//returns true/false depending on case if str is found or not
	//if not found temp is NULL
{
	temp = head;

	if (head == NULL)
	{
		return false;
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->busLineName == str)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
}

bool LLcheck_prev(string str, busLine *&temp)
	//changes temp to previous node of the node that has str in it
{
	temp = head;

	if (head == NULL)
	{
		return false;
	}
	else
	{
		while(temp->next != NULL)
		{
			if(temp->next->busLineName == str)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
}

bool strCheck(string str)
{
	for(int a = 0; a < str.length(); a++)
	{
		if (str[a] == ' ')
		{
			cout << "[ERROR]: Name should not include any space character. Please enter again." << endl;
			return false;	
		}
	}
	return true;
}

bool Scan2D(string str)
{
	busLine* ptr = head;
	while(ptr != NULL)
	{
		if(DLstringcheck(ptr->busStops, str))
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

busStop* SearchPath(busLine* line, string start, string end, char &ch)
{
	ch = 'N';
	busStop * ptr = line->busStops;
	if (line->busStops == NULL)  
	{
		return NULL;
	}

	ptr = Findptr(line->busStops, start);
	if(ptr == NULL)
	{
		return NULL;
	}

	if (Findptr(line->busStops, end) == NULL)
	{
		return NULL;
	}

	busStop* ptr2 = ptr;

	/* check right hand side */
	ptr2 = ptr2->right;
	while(ptr2 != NULL)
	{
		if (ptr2->busStopName == end)
		{
			ch = 'R';
			return ptr;  //end point is on the right side of the start point
		}
		ptr2 = ptr2->right;
	}

	/* check left hand side */
	ptr2 = ptr;
	ptr2 = ptr2->left;
	while(ptr2 != NULL)
	{
		if (ptr2->busStopName == end)
		{
			ch = 'L';
			return ptr;  //end point is on the left side of the start point
		}
		ptr2 = ptr2->left;
	}

	return NULL;
	// if return is NULL then that means bus stop start is not found in 
}

busStop *Findptr(busStop *&ptr, string str)
{
	busStop * temp = ptr;
	if (ptr == NULL)
	{
		return NULL;
	}

	while(temp != NULL)
	{
		if (temp->busStopName == str)
		{
			return temp;
		}
		temp = temp->right;
	}

	return NULL;
}