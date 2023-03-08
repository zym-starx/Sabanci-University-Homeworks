#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;

// Zeynep Yildiz 00029325

bool inputcheck1(string &nana)
{
	// function that checks if the word is alpha
	// this is not in a loop
	int len = nana.length();
	for (int i = 0; i <= (len - 1); i++)
	{
		string abcs = "qwertyuopasdfghjklizxcvbnm";
		if (abcs.find(nana[i]) == string::npos)
		{
			return false;
		}
		else
		{
		}
	}
	return true;
}

string inputcheck2(string &nana)
{
	// this function puts inputcheck1 into a loop and gives necessary outputs if its false 
	if (inputcheck1(nana) == false)
	{
		while (inputcheck1(nana) == false)
	    {
		std::cout << "Invalid entry! Try again." << endl;
		cin >> nana;
		ToLower(nana);
	    }
		return nana;
	}
	
	else
	{
		return nana;
	}
}

string wordtake_control(string p1, string p2, string &nana)
{
	// control function to take and check the word
	cout << p1 << ", please input the word you want " << p2 << " to guess: ";
	cin >> nana;
	ToLower(nana);

	if (inputcheck1(nana) == false)
	{
		while (inputcheck1(nana) == false)
	    {
			std::cout << "Invalid word! Try again." << endl;
			cout << p1 << ", please input the word you want " << p2 << " to guess: ";
			cin >> nana;
			ToLower(nana);
	    }
		return nana;
	}
	
	else
	{
		return nana;
	}
}

string redactedword(string word, string tries)
{
	// function that returns the redacted version of the word
    string aa = "";

	if (tries == "")
	{
		int len = word.length();

	    for (int i = 0; i < len; i++)
	    {
		   aa += "-";
	    }
	}
	else if (tries != "")
	{
		int len = word.length();

		for (int baa = 0; baa < len; baa++)
		{
			if (tries.find(word[baa]) == string::npos)
			{
				aa += "-";
			}
			else if (tries.find(word[baa]) != string::npos)
			{
				aa += word[baa];
			}
		}
	}
	return aa;
}

void optioncontrol(string p1, string p2, string &choice, string redacted)
{
	// function that takes and check the option version (1 || 2)
	cout << "The word is: " << redacted << endl;
	cout << p2 << ", do you want to guess the word(1) or guess a letter(2)? ";
    cin >> choice;
	while (((choice == "1") || (choice == "2")) == false)
	{
		cout << "Invalid option!" << endl;
		cout << "The word is: " << redacted << endl;
		cout << p2 << ", do you want to guess the word(1) or guess a letter(2)? ";
		cin >> choice;
	}
}

void takingguess(string &guess)
{
	// This just takes the guess and makes it all lowercase
	cout << "Your guess: ";
	cin >> guess;
    ToLower(guess);
}

void guesscontrol(string &guess, string p1, string p2, string choice, string dumdum, string tries)
{
	// After taking the guess this function is called. This checks if everything is okay with it.
	string abcs = "qwertyuopasdfghjklizxcvbnm";
	string toothless = redactedword(dumdum, tries);
	while (inputcheck1(guess) == false)
	{
		cout << "Invalid entry! Try again." << endl;
		optioncontrol(p1, p2, choice, toothless);
		takingguess(guess);
	}
}

int option1(string word, int &lives, string guess)
{
	/*
	Basically the option 1. Returns 0 if the guessed word equals to the word.
	Returns 1 if it's not
	Returns 2 if neither (C++ made me create a else part of this. It was giving an error.)
	*/
	if (inputcheck1(guess) == true)
	{
		if (guess == word)
		{
			return 0;
		}
		else
		{
			lives = lives - 1;
			return 1;
		}
	}
	else
	{
		return 2;
	}
}

int option2(string word, int &lives, string &guess, string &tries, string p1, string p2)
{
	/*
	Basically option1 but a little more complicated.
	this also checks if the guess is only 1 char and alphabetical.
	*/
	string cchoice = "2";
	string redacted = redactedword(word, tries);
	while (guess.length() != 1)
	{
		cout << "Invalid entry! Try again." << endl;
		break;
	}
	while (tries.find(guess) != string::npos)
	{
		cout << "Guess entered before! Try again." << endl;
		break;
	}
	if (((guess.length() != 1) || (tries.find(guess) != string::npos)) == false)
       // if guess is only one char and is not entered before ==> execute the following
	{
		if (word.find(guess) != string::npos)
		{
			tries += guess;
		    return 0;
		}
		else
		{
			tries += guess;
			lives = lives - 1;
			return 1;
		}
	}
	else // else do nothing (then this will take it back to the top of while loop in main)
	{
		return 2;
	} // If guess is not 1 char or entered before this function will return 2. which is something
	  // I dont use but I do check if it gives 0 or 1. 
}

int main()
{
	//Thank you for nothing, you useless reptile. -Hiccup

	string p1; string p2; string dumdum; string tries;
	int lives = 6;
	cout << "Welcome to the HANGMAN GAME" << "\n" << "---------------------------" << endl;

	cout << "Player one, please enter your name: ";
	cin >> p1;
	cout << "Player two, please enter your name: ";
	cin >> p2;
	cout << "OK " << p1 <<" and " << p2 << ". Let's start the game!" << endl;

	wordtake_control(p1, p2, dumdum);

	cout << p2 <<", you have 1 free guess, after that you will lose limbs!" << endl;

	while (lives > 0) // To comeback everytime number of lives change
	{
		// Welcome to the party, pal
		string toothless = redactedword(dumdum, tries);
		string choice;
		optioncontrol(p1, p2, choice, toothless);
	    string guess;
		takingguess(guess);
		guesscontrol(guess, p1, p2, choice, dumdum, tries);

		// I'm using if elses for "lives" here because depending on the lives the output changes
		if (lives == 6)
		{
			if (choice == "1")
			{
				int aa = option1(dumdum, lives, guess);
				if (aa == 0)
				{
					cout << "The word is: " << dumdum << endl;
					cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!";
					return 0; //Finish the program
				}
				else if (aa == 1)
				{
					cout << "You have no free guess left." << endl;
				}
			}
			else if (choice == "2")
			{
				int bb = option2(dumdum, lives, guess, tries, p1, p2);
				if (bb == 0)
				{
					toothless = redactedword(dumdum, tries);
					if (toothless == dumdum)
                    {
						cout << "The word is: " << toothless << endl;
						cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!";
						return 0;
                    }
					else
					{
					}
				}
				else if (bb == 1)
				{
					cout << "You have no free guess left." << endl;
				}

			}
		}
		else if ((3 < lives) && (6 > lives))
		{
			if (choice == "1")
			{
				int aa = option1(dumdum, lives, guess);
				if (aa == 0)
				{
					cout << "The word is: " << dumdum << endl;
					cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!";
					return 0; //Finish the program
				}
				else if (aa == 1)
				{
					cout << "You have lost a leg!" << endl;
				}
			}
			else if (choice == "2")
			{
				int bb = option2(dumdum, lives, guess, tries, p1, p2);
				if (bb == 0)
				{
					toothless = redactedword(dumdum, tries);
					if (toothless == dumdum)
                    {
						cout << "The word is: " << toothless << endl;
						cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!";
						return 0; //Finish the program
                    }
					else
					{
					}
				}
				else if (bb == 1)
				{
					cout << "You have lost a leg!" << endl;
				}
			}
		}
		else if ((lives > 1) && (lives < 4)) 
		{
			if (choice == "1")
			{
				int aa = option1(dumdum, lives, guess);
				if (aa == 0)
				{
					cout << "The word is: " << dumdum << endl;
					cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!";
					return 0; //Finish the program
				}
				else if (aa == 1)
				{
					cout << "You have lost an arm!" << endl;
				}
			}
			else if (choice == "2")
			{
				int bb = option2(dumdum, lives, guess, tries, p1, p2);
				if (bb == 0)
				{
					toothless = redactedword(dumdum, tries);
					if (toothless == dumdum)
                    {
						cout << "The word is: " << toothless << endl;
						cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!";
						return 0; //Finish the program
                    }
					else
					{
					}
				}
				else if (bb == 1)
				{
					cout << "You have lost an arm!" << endl;
				}
			}
		}
		else if (lives == 1) 
		{
			if (choice == "1")
			{
				int aa = option1(dumdum, lives, guess);
				if (aa == 0)
				{
					cout << "The word is: " << dumdum << endl;
					cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!" ;
					return 0; //Finish the program
				}
				else if (aa == 1)
				{
					cout << "You have lost a head! GAME OVER!" << endl << p2 << " lost the game :(";
					return 0; //Finish the program
				}
			}
			else if (choice == "2")
			{
				int bb = option2(dumdum, lives, guess, tries, p1, p2);
				if (bb == 0)
				{
					toothless = redactedword(dumdum, tries);
					if (toothless == dumdum)
                    {
						cout << "The word is: " << toothless << endl;
						cout << "Congratulations " << p2 << ", you won!\n" << p2 << " won the game!";
						return 0; //Finish the program
                    }
				}
				else if (bb == 1)
				{
					cout << "You have lost a head! GAME OVER!" << endl << p2 << " lost the game :(";
					return 0; //Finish the program
				}
			}
		}
	}
// Tie a yellow ribbon around the old oak tree 'cause this boy's comin' home
}