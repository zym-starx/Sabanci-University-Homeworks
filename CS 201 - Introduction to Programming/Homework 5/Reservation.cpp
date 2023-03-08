#include "Reservation.h"
#include <sstream>
#include <fstream>


Boat::Boat(vector<Boat> &boatvector)
{
	//getting every line in boats.txt, applying them to a struct then gathering all that struct to a vector
	string boatstr; string boatfilename = "Boats.txt";
	ifstream boatfs;
	boatfs.open(boatfilename.c_str());
	//open file control 1
	if (boatfs.fail())
	{
		cout << "Cannot open the files. Exiting..." << endl;
		boatfs.clear();
		return;
	}
	boatfs.clear();
	boatfs.seekg(0);
	getline(boatfs, boatstr);
	while (getline(boatfs, boatstr))
	{	
		istringstream input(boatstr);
		Boat dumdum;
		input >> dumdum.id >> dumdum.name >> dumdum.color;
		boatvector.push_back(dumdum);
	}
}

Sailor::Sailor(vector<Sailor> &sailorvector)
{
	//getting every line in sailor.txt, applying them to a struct then gathering all that struct to a vector
	string sailorstr; string sailorfilename = "Sailors.txt";
	string sailorstr; ifstream sailorfs;
	sailorfs.open(sailorfilename.c_str());
	//open file control 1
	if (sailorfs.fail())
	{
		cout << "Cannot open the files. Exiting..." << endl;
		sailorfs.clear();
		return;
	}
	getline(sailorfs, sailorstr);
	while (getline(sailorfs, sailorstr))
	{
		istringstream input(sailorstr);
		Sailor dumdum;
	    input >> dumdum.id >> dumdum.name >> dumdum.rank >> dumdum.age;
		sailorvector.push_back(dumdum);
	}
}

Reservation::Reservation(vector<Reservation> & resvector)
{

}

void Reservation::Reservationprint(const vector<Reservation> & resvector)
{
	for (int a = 0; a < resvector.size(); a++)
	{
		
	}
}

/*
Boat::Boat(vector<boat> &boatvector)
{
	//getting every line in boats.txt, applying them to a struct then gathering all that struct to a vector
	string boatstr; string boatfilename = "Boats.txt";
	ifstream boatfs;
	boatfs.open(boatfilename.c_str());
	//open file control 1
	if (boatfs.fail())
	{
		cout << "Cannot open the files. Exiting..." << endl;
		boatfs.clear();
		return;
	}
	vector<boat> boatvector;
	boatfs.clear();
	boatfs.seekg(0);
	getline(boatfs, boatstr);
	while (getline(boatfs, boatstr))
	{	
		istringstream input(boatstr);
		boat dumdum;
		input >> dumdum.boatid >> dumdum.boatname >> dumdum.boatcolor;
		boatvector.push_back(dumdum);
	}
}
*/

/*
Sailor::Sailor(vector<sailor> &sailorvector)
{
	//getting every line in sailor.txt, applying them to a struct then gathering all that struct to a vector
	string sailorstr; string sailorfilename = "Sailors.txt";
	string sailorstr; ifstream sailorfs;
	sailorfs.open(sailorfilename.c_str());
	//open file control 1
	if (sailorfs.fail())
	{
		cout << "Cannot open the files. Exiting..." << endl;
		sailorfs.clear();
		return;
	}
	vector<sailor> sailorvector;
	getline(sailorfs, sailorstr);
	while (getline(sailorfs, sailorstr))
	{
		istringstream input(sailorstr);
		sailor dumdum;
	    input >> dumdum.sailorid >> dumdum.sailorname >> dumdum.rank >> dumdum.age;
		sailorvector.push_back(dumdum);
	}
	return;
}
*/

/*
struct boat
{ 
	//struct for boats.txt lines
	int boatid;
	string boatname;
	string boatcolor;
};
struct sailor
	{
		//struct for sailor.txt lines
		int sailorid;
		string sailorname;
		double rank;
		double age;
	};
*/