#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "randgen.h"
#include "strutils.h"

// #define DEBUG

//	Zeynep Yildiz  00029325
//	14/10/2021

using namespace std;

void PrintBoard_debug(vector <vector <pair <char, bool>>> &board);                   //printing function that prints the board without redactation (for debug purposes + showing all board at the end of game)

void PrintBoard(vector <vector <pair <char, bool>>> &board);                         //printing function that prints the board with redactation 

void Placing_bombs(vector <vector <pair <char, bool>>> &board, int bomb_num);        //function for placing bombs into the board

void EditBoard(vector <vector <pair <char, bool>>> &board);                          //editing the board according to where the bombs are

void CreatingBoard(vector <vector <pair <char, bool>>> &board, int bomb_num);        //function for editing the board for further usage

int DisplaySurrounding(vector <vector <pair <char, bool>>> &board);                  //function for the first option in the menu where a single point open temporarily 

int Menu(vector <vector <pair <char, bool>>> &board, int bomb_num);                  //function for choosing game mechanics. If the game will continue it will return 0, otherwise 1 (see main())

bool isValid(int row, int col, int row_num, int column_num);                         //function for checking validation subscript of vectors (used for counting the bombs around a cell)

bool OpenCell(vector <vector <pair <char, bool>>> &board);                           //function for opening a cell. returns false if the opened cell contains a bomb

bool WinningCheck(vector <vector <pair <char, bool>>> &board, int bomb_num);         //function for checking if all non mined cells are opened




int main()   // main function
{
	int row_num = 0, column_num = 0, bomb_num = 0;
	
	cout << "Give the dimensions of the matrix: ";
	while (!(cin >> row_num >> column_num))					// In case of user enters non-integer values
	{												// which is not exactly necessary according to hw pdf but added anyway
		cout << "Please enter numbers only." << endl;
		cin.clear();
		cin.ignore(10000,'\n');
	}

	while (row_num == 0 || column_num == 0)
	{
		cout << "[ERROR]: " << "Unexeptable integers for matrix. Please enter again";
		cin >> row_num >> column_num;
	}

	pair <char, bool> point;																				 // every cell contains a pair
	point.first = '0';                                                                                       // shows how many bombs are around that cell or if cell is a mine
	point.second = false;                                                                                    // determines if the cell is allowed to open
	vector <vector <pair <char, bool>>> board (row_num, vector <pair <char, bool>> ((column_num), point));   // initiliazing the board

	cout << "How many bombs: ";
	cin >> bomb_num;

	while (bomb_num < 1 || bomb_num > row_num*column_num)
	{
		cout << "The number of bombs can not be greater than the whole number of cells minus one. Please give the number of bombs again: ";
		cin >> bomb_num;
	}

	CreatingBoard(board, bomb_num);						 // Placing the mines, editing other cells' first values according to number of bombs around...

	cout << "\n\n";
	PrintBoard(board);
	cout << "\n\n";

	while (Menu(board, bomb_num) == 0)                   // unless Menu returns 1 (meaning the game should be over) menu will be printed again and again
	{
		if (Menu(board, bomb_num) == 1)
		{
			break;
		}
	}

	system("pause");
	return 0;
}


/************************************************************************************************/
                                 //Function declarations//
/************************************************************************************************/

bool isValid(int row, int col, int row_num, int column_num)
{
	return ((row >= 0) && (row < row_num) && (col >= 0) && (col < column_num));
}

void CreatingBoard(vector <vector <pair <char, bool>>> &board, int bomb_num)
{

#ifdef DEBUG
	PrintBoard_debug(board);
	cout << endl << endl;
	PrintBoard(board);
	cout << endl << endl << endl;
#endif // DEBUG

	Placing_bombs(board, bomb_num);        //bombs are placed in random points on the board

#ifdef DEBUG
	PrintBoard_debug(board);
	cout << endl << endl;
#endif // DEBUG

	EditBoard(board);                      //editing the board according to places of the bombs

#ifdef DEBUG
	PrintBoard_debug(board);
	cout << endl << endl;
#endif // DEBUG
}

int Surroundingcount(vector <vector <pair <char, bool>>> &board, int row, int column)
{
	// there was a much more longer version of this function but since this idea I found on the internet is much more simple I used this
	int count = 0;
	for (int dx = -1; dx <= 1; dx++)
			{
				for (int dy = -1; dy <= 1; dy++)
				{
		           if (dx != 0 || dy != 0)
				   {
			           if (isValid(row + dx, column +dy, board.size(), board[0].size()))
				            if (board[row+dx][column+dy].first == 'B')
							count++;
				   }
				}
			}
	return count;
}

void EditBoard(vector <vector <pair <char, bool>>> &board)
{
	// for loops taken from both CS204 lab materials and internet
	// counting the bombs around every cell and if the cell does not contain a mine the first value of pair will be this count
	int count = 0;
	for (unsigned int j = 0; j < board.size(); j++)
	{
		for (unsigned int k = 0; k < board[0].size(); k++)
		{
			if (board[j][k].first != 'B')
			{
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 1; dy++)
						{
							if (dx != 0 || dy != 0)
							{
								if (isValid(j+dx, k+dy, board.size(), board[0].size()))
								{
									if (board[j+dx][k+dy].first == 'B')
									count++;
								}
							}
						}
				}
				string strcount = itoa(count);    //turning int to char
				board[j][k].first = strcount[0];
				count = 0;
			}
		}
	}
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

void Placing_bombs(vector <vector <pair <char, bool>>> &board, int bomb_num)
{
	RandGen rnd;
	vector <int> randompoints;
	int introw = board.size();
	int intcolumn = board[0].size();
	for (int a = 0; a < bomb_num;)
	{
		int num = rnd.RandInt(0, introw*intcolumn -1);
		if (!FindinVector(randompoints, num))
		{
			randompoints.push_back(num);
			a++;
		}
	}

	for (int a = 0; a < bomb_num; a++)
	{
		int row_t, column_t;                              //temporarily will be used in this for loop 
		                                                  //to determine the point in (x,y) type
		row_t = (randompoints[a] / intcolumn);
		column_t = (randompoints[a] % intcolumn);
		board[row_t][column_t].first = 'B';               //meaning it is a bomb
	}
}

void PrintBoard_debug(vector <vector <pair <char, bool>>> &board)
{
	// this printing function is taken from CS204 lab materials
	for (unsigned int j = 0; j < board.size(); j++)
	{
		for (unsigned int k = 0; k < board[0].size(); k++)
		{
			if (board[j][k].first != 'B')
				cout << setw(4) << board[j][k].first;
			else
				cout << setw(4) << "B";
		}
		cout << endl;
	}
}

void PrintBoard(vector <vector <pair <char, bool>>> &board)
{
	// this printing function is taken from CS204 lab materials and edited for usage
	// prints the board according to the second value of pairs (if true then it is not redacted, if false it is redacted)

	for (unsigned int j = 0; j < board.size(); j++)
	{
		for (unsigned int k = 0; k < board[0].size(); k++)
		{
			if (board[j][k].second)
				cout << setw(4) << board[j][k].first;
			else
				cout << setw(4) << "X";
		}
		cout << endl;
	}
}

int DisplaySurrounding(vector <vector <pair <char, bool>>> &board)
{
	cout << "Give the coordinate: ";
	int row, column;
	while (!(cin >> row >> column))					// In case of user enters non-integer values
	{												// which is not exactly necessary according to hw pdf but added anyway
		cout << "Please enter numbers only." << endl;
		cin.clear();
		cin.ignore(10000,'\n');
	}

	while(row >= board.size() || row < 0 || column < 0 || column >= board[0].size())
	{
		cout << "It is out of range. Please give a valid coordinates: ";
		cin >> row >> column;
	}

	if (board[row][column].first != 'B')		// non-mine cells already contain the number of mines around them
	{
		cout << "\n\n" << "Displaying the surrounding of (" << row << "," << column << "):" << "\n\n";
		board[row][column].second = true;       // to display that point in the board we are opening it
		PrintBoard(board);
		cout << "\n\n" <<"Around (" << row << "," << column << ") you have " << board[row][column].first << " bomb(s)" << "\n\n";
		board[row][column].second = false;      // since it is opened temmporarily we are closing it again
	}
	else if (board[row][column].first == 'B')
	{
		string a = itoa(Surroundingcount(board, row, column));
		cout << "\n\n" << "Displaying the surrounding of (" << row << "," << column << "):" << "\n\n";
		board[row][column].first = a[0];        //change the char to number of bombs around the point temporarily
		board[row][column].second = true;       // to display that point in the board we are opening it
		PrintBoard(board);
		cout << "\n\n" <<"Around (" << row << "," << column << ") you have " << board[row][column].first << " bomb(s)" << "\n\n";
		board[row][column].first = 'B';         //changing it back to char 'B'
		board[row][column].second = false;      // since it is opened temmporarily we are closing it again
	}

	return 0;
}

bool OpenCell(vector <vector <pair <char, bool>>> &board)
{
	int open_row, open_column;
	cout << "Give the coordinates: ";
	while (!(cin >> open_row >> open_column))				// In case of user enters non-integer values
	{														// which is not exactly necessary according to hw pdf but added anyway
		cout << "Please enter numbers only." << endl;
		cin.clear();
		cin.ignore(10000,'\n');
	}

	while(open_row > board.size() || open_row < 0 || open_column < 0 || open_column > board[0].size())
	{
		cout << "It is out of range. Please give a valid coordinates: ";
		cin >> open_row >> open_column;
	}

	board[open_row][open_column].second = true;				// open the cell permanently
	cout << "Opening cell (" << open_row <<  "," << open_column << "): " << "\n\n";
	PrintBoard(board); cout << "\n\n";

	if (board[open_row][open_column].first == 'B')
	{
		cout <<"Unfortunately, you stepped on a mine." << "\n\n";
		cout << "Arrangement of mines: " << "\n\n";
		PrintBoard_debug(board);
		cout << "\n\n" <<  "		>>>>> Game Over! <<<<<" << endl;
		return false;
	}
	return true;
}

bool WinningCheck(vector <vector <pair <char, bool>>> &board, int bomb_num)
{
	int count = 0;
	for (unsigned int j = 0; j < board.size(); j++)
	{
		for (unsigned int k = 0; k < board[0].size(); k++)
		{
			if (board[j][k].second == true)
			{
				count++;
			}	
		}
	}
	if (count == (board.size() * board[0].size()) - bomb_num)
		return true;
	else
		return false;
}

int Menu(vector <vector <pair <char, bool>>> &board, int bomb_num)
{
	string choice;
	cout << "Press: \n1. If you want to find out the surrounding of a cell" << endl;
	cout << "2. If you want to open the cell" << endl;
	cout << "3. If you want to exit." << endl;
	cin >> choice;
	cout << "\n\n";

	while (choice != "1" && choice != "2" && choice != "3")
	{
		cout << "Your input is wrong. Please select one of the options: 1, 2 or 3.";
		cin >> choice;
	}

	if (choice == "1")
	{
		DisplaySurrounding(board);
		return 0;      //Menu will be printed again
	}

	else if (choice == "2")
	{
		bool smthng = OpenCell(board);
		if (smthng == true)
		{
			if (WinningCheck(board, bomb_num))
			{
				cout << "\n\n" << "Congratulations! All the non-mined cells opened successfully. \nYou won!" << endl;
				cout <<           "		>>>>> Game Over! <<<<<" << endl;
				return 1;
			}
			else
			{
				return 0;   //Menu will be executed again
			}
		}
		else
		{
			return 1;   //Menu will not be executed again (OpenCell() has necessary outputs for ending the game)
		}
	}

	else if (choice == "3")
	{
		cout << "Program exiting ..." << endl;
		return 1;
	}

	return 0;
}