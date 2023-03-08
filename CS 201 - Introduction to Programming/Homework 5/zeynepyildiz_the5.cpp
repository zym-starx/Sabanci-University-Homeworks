#include <sstream>
#include <fstream>
#include "strutils.h"
#include "Reservation.h"
//Zeynep Yildiz
using namespace std;

int main()
{
	string sailorfilename = "Sailors.txt";
	string reserves;
	ifstream sailorfs, reservefs;
	string boatstr, sailorstr, reservestr;

	vector<Sailor> sailorvector;
	vector<Boat> boatvector;
	Sailor(sailorvector);
	Boat(boatvector);

	cout << "Enter filename for reservation database: ";
	cin >> reserves;
	reservefs.open(reserves.c_str());

	//open file control 2
	if (reservefs.fail())
	{
		cout << "Cannot open the files. Exiting..." << endl;
		reservefs.clear();
		return 0;
	}


	return 0;
}