#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Zeynep Yildiz 00029325

void greetings()
{
	cout << "Hello and welcome to the Hogwarts house sorting hat program!\n";
	cout << "When I call your name, you'll come forth, I shall place the sorting hat on your head, and you will be sorted into your houses.\n";
}

void assignanswers(string &answ_str, string &q1, string &q2, string &q3, string &q4, string &q5, string &q6, string &name, string &surname)
{
	// assigns participants' info and answers to the corresponding strings
	istringstream input(answ_str);
	input >> name >> surname >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;
}

void assignasnwersheet(const string &filename, ifstream &input, string &asq1, string &asq2, string &asq3, string &asq4, string &asq5, string &asq6)
{
	// assignes every question's key answers to the corresponding string
	// I am sure there is a little less complicated way of doing this but if it works it works

	string s;
	string q1, q2, q3, q4, q5, q6;
	int counter = 1;
	while (getline(input, s))
	{
		if (s != "")
		{
		if (counter == 1)
		{
			q1 = s;
			counter++;
			istringstream dumdum;
			dumdum.str(q1); string ouma;
			while (dumdum >> ouma)
			{
				asq1.append(ouma);
				asq1.append(" ");
			}
		}
		else if (counter == 2)
		{
			q2 = s;
			counter++;
			istringstream dumdum;
			dumdum.str(q2); string ouma;
			while (dumdum >> ouma)
			{
				asq2.append(ouma);
				asq2.append(" ");
			}
		}
		else if (counter == 3)
		{
			q3 = s;
			counter++;
			istringstream dumdum;
			dumdum.str(q3); string ouma;
			while (dumdum >> ouma)
			{
				asq3.append(ouma);
				asq3.append(" ");
			}
		}
		else if (counter == 4)
		{
			q4 = s;
			counter++;
			istringstream dumdum;
			dumdum.str(q4); string ouma;
			while (dumdum >> ouma)
			{
				asq4.append(ouma);
				asq4.append(" ");
			}
		}
		else if (counter == 5)
		{
			q5 = s;
			counter++;
			istringstream dumdum;
			dumdum.str(q5); string ouma;
			while (dumdum >> ouma)
			{
				asq5.append(ouma);
				asq5.append(" ");
			}
		}
		else if (counter == 6)
		{
			q6 = s;
			counter++;
			istringstream dumdum;
			dumdum.str(q6); string ouma;
			while (dumdum >> ouma)
			{
				asq6.append(ouma);
				asq6.append(" ");
			}
		}
		}
		else {}
	}
}

int pointss(string dumdum, string baa)
{
	// function name is with two "s" because apparently there is another function called points() (? idek) 
	// dumdum is the answer sheet with only one blank spaces between words. This function finds and counts the blank spaces until the finding of "baa" then 
	// returns count+1 because that is the number of the points you should get falan filan idk saat 1 and my last 3 braincells are considering quiting their jobs

	if (dumdum.find(baa) != string::npos)
	{
		int saeran = dumdum.find(baa);
		int count = 0;
		for (int saeyoung = 0; saeyoung <= saeran; saeyoung++)
		{
			if (dumdum[saeyoung] == ' ')
			{
				count++;
			}
			else {}
		}
		int point = count + 1;
		return point;
	}
	else {
		return 0;  // Idk why but if the answer is the first one in the key sheet the if statement above will not return 1 so I made the else statement to return 1
	}
}

void compareans(string &asq1, string &asq2, string &asq3, string &asq4, string &asq5, string &asq6, string &q1, string &q2, string &q3, string &q4, string &q5, string &q6, int &points)
{
	//compare answer to the keysheet and return the points

	int point1 , point2, point3, point4 ,point5, point6;
	point1 = pointss(asq1, q1);  // points from question 1
	point2 = pointss(asq2, q2);  // points from question 2
	point3 = pointss(asq3, q3);  // points from question 3
	point4 = pointss(asq4, q4);  // points from question 4
	point5 = pointss(asq5, q5);  // points from question 5
	point6 = pointss(asq6, q6);  // points from question 6

	points = point1 + point2 + point3 + point4 + point5 + point6;  // total points
}

void hatdecides(string name, string surname, int points)
{
	string house;
	if (points < 10)
	{
		house = "Hufflepuff";
	}
	else if ((10 <= points) && (points < 15))
	{
		house = "Ravenclaw";
	}
	else if ((15 <= points) && (points < 21))
	{
		house = "Gryffindor";
	}
	else if (21 <= points)
	{
		house = "Slytherin";
	}
	cout << "Oh! we have " << name << " " << surname << " under the sorting hat. " << name << ", you scored " << points << " points, you are a " << house << "!";
}

int main()
{
	// Welcome to the party, pal

	string filename, answerfile; 
	string name, surname;
	string asq1, asq2, asq3, asq4, asq5, asq6;
	string q1, q2, q3, q4, q5, q6;
	int points;
	greetings();

	//not even gonna lie I adopted lecture codes for the input fail/check part

	ifstream input, input2;

	cout << "Enter the name of the key file: ";
	cin >> filename;

	input.open(filename.c_str());
	
	while (input.fail())   // if filename is invalid
	{
		input.clear();
		cout << "Error: Cannot open file " << filename << endl;
		cout << "Enter the name of the key file: ";
	    cin >> filename;
		input.open(filename.c_str());
	}

	cout << "Enter the name of the answer file: ";
	cin >> answerfile;

	input2.open(answerfile.c_str());

	while (input2.fail())   // if answerfilename is invalid
	{
		input2.clear();
		cout << "Error: Cannot open file " << answerfile << endl;
		cout << "Enter the name of the answer file: ";
	    cin >> answerfile;
		input2.open(answerfile.c_str());
	}

	assignasnwersheet(filename, input, asq1, asq2, asq3, asq4, asq5, asq6);
	string answ_str;

	// this is where the boom goes the dynamite
	while (getline(input2, answ_str))
	{
		if (answ_str != "")
		{
			if (answ_str != "\r")
			{
				assignanswers(answ_str, q1, q2, q3, q4, q5, q6, name, surname);
				compareans(asq1, asq2, asq3, asq4, asq5, asq6, q1, q2, q3, q4, q5, q6, points);
				hatdecides(name, surname, points); cout << endl;
			}
		}
		else {}
	}

	input.close();
	input2.close();

	return 0;
}