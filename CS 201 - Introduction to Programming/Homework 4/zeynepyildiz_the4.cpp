#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "strutils.h"
//Zeynep Yildiz
using namespace std;

struct boat
{ 
	//struct for boats.txt lines
	int boatid;
	string boatname;
	string boatcolor;
};

vector<boat> BoatVectorAssign(ifstream &boatfs)
{
	//getting every line in boats.txt, applying them to a struct then gathering all that struct to a vector
	string boatstr;
	int id; string name, color;
	vector<boat> boatvector;
	boatfs.clear();
	boatfs.seekg(0);
	getline(boatfs, boatstr);
	while (getline(boatfs, boatstr))
	{	
		istringstream input(boatstr);
	    input >> id >> name >> color;
		boat dumdum;
		dumdum.boatid = id;
		dumdum.boatname = name;
		dumdum.boatcolor = color;
		boatvector.push_back(dumdum);
	}
	return boatvector;
}
 
struct sailor
	{
		//struct for sailor.txt lines
		int sailorid;
		string sailorname;
		double rank;
		double age;
	};

vector<sailor> SailorVectorAssign(ifstream &sailorfs)
{
	//getting every line in sailor.txt, applying them to a struct then gathering all that struct to a vector
	string sailorstr;
	int id; string name; double rank, age;
	vector<sailor> sailorvector;
	sailorfs.clear();
	sailorfs.seekg(0);
	getline(sailorfs, sailorstr);
	while (getline(sailorfs, sailorstr))
	{
		istringstream input(sailorstr);
	    input >> id >> name >> rank >> age;
		sailor dumdum;
		dumdum.sailorid = id;
		dumdum.sailorname = name;
		dumdum.rank = rank;
		dumdum.age = age;
		sailorvector.push_back(dumdum);
	}
	return sailorvector;
}

struct reservation
{
	//struct for reserves.txt s lines
	int sailorid;
	int boatid;
	string reservdate;
	string boatname, sailorname, boatcolor;
	double srank, sage;
};

vector<reservation> ReserveVectorAssign(ifstream &reservefs)
{
	//getting every line in reserves.txt, applying them to a struct then gathering all that struct to a vector
	string reservestr;
	int sailorid, boatid; string date;
	vector<reservation> resvector;
	getline(reservefs, reservestr);
	while (getline(reservefs, reservestr))
	{
		istringstream input(reservestr);
	    input >> sailorid >> boatid >> date;
		reservation dumdum;
		dumdum.sailorid = sailorid;
		dumdum.boatid = boatid;
		dumdum.reservdate = date;
		resvector.push_back(dumdum);
	}
	
	return resvector;
}

void findfind(vector<reservation> &resvector, vector<boat> &boatvector, vector<sailor> &sailorvector)
{
	// for every struct in reserves vector, finding them in sailor and boat vector then finding the corresponding other infos.
	// then applying them to that struct
	int sid, bid; string date;
	for (int a = 0; a < resvector.size(); a++)
	{
		string bname, sname;
		sid = resvector[a].sailorid;
		bid = resvector[a].boatid;
		date = resvector[a].reservdate;
		int imp1, imp2;
		for (int b = 0; b < boatvector.size(); b++)
		{
			if (boatvector[b].boatid == bid)
			{
				imp1 = b;
			}
			else {}
		}
		for (int b = 0; b < sailorvector.size(); b++)
		{
			if (sailorvector[b].sailorid == sid)
			{
				imp2 = b;
			}
			else {}
		}

		resvector[a].boatname = boatvector[imp1].boatname;
		resvector[a].boatcolor = boatvector[imp1].boatcolor;
		resvector[a].sailorname = sailorvector[imp2].sailorname;
		resvector[a].srank = sailorvector[imp2].rank;
		resvector[a].sage = sailorvector[imp2].age;
	}
}

void SelectSort(vector<reservation> & a){
// pre: a contains a.size() elements
// post: elements of a are sorted in non-decreasing order
	reservation temp;
    int j, k, minIndex, numElts = a.size();
    for(k=0; k < numElts - 1; k++){
        minIndex = k;             // minimal element index
		int y, m, d;
		string sy, sm, sd;
		string temp1 = a[minIndex].reservdate;
		sy = temp1.substr(0,4);
		sm = temp1.substr(5,2);
		sd = temp1.substr(8,2);
		y = atoi(sy);
		m = atoi(sm);
		d = atoi(sd);
        for(j=k+1; j < numElts; j++){
			int year, month, day;
		    string syear, smonth, sday;
			string temp2 = a[j].reservdate;
			syear = temp2.substr(0,4);
			smonth = temp2.substr(5,2);
			sday = temp2.substr(8,2);
			year = atoi(syear);
			month = atoi(smonth);
			day = atoi(sday);
            if (year < y)
			{
               minIndex = j;     // new min, store index
			}
			else if  (year == y) {
				if (month < m)
				{
					minIndex = j;     // new min, store index
				}
				else if (month == m)
				{
					if (day < d)
					{
						minIndex = j;     // new min, store index
					}
					else if (day == d)
					{
						if (a[j].sailorname[0] < a[minIndex].sailorname[0])
						{
							minIndex = j;     // new min, store index
						}
					}
				}
			}
		}
        temp = a[k];         // swap min and k-th elements
        a[k] = a[minIndex];
        a[minIndex] = temp;
    }
}

void printout(vector<reservation> &resvector)
{
	// just a printing function
	for (int a = 0; a < resvector.size(); a++)
	{
		cout << resvector[a].reservdate << " -> " << resvector[a].sailorname << "(" << resvector[a].sage << "," << resvector[a].srank << ") has reserved " 
			<< resvector[a].boatname << "(" << resvector[a].boatcolor << ")" << endl;
	}
}

int main()
{
	string boatfilename = "Boats.txt";
	string sailorfilename = "Sailors.txt";
	string reserves;
	ifstream boatfs, sailorfs, reservefs;
	string boatstr, sailorstr, reservestr;

	boatfs.open(boatfilename.c_str());
	sailorfs.open(sailorfilename.c_str());

	//open file control 1
	if (boatfs.fail() || sailorfs.fail())
	{
		cout << "Cannot open the files. Exiting..." << endl;
		boatfs.clear(); sailorfs.clear();
		return 0;
	}

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

	//boom goes the dynamite
	vector<boat> boatvector = BoatVectorAssign(boatfs);
	vector<sailor> sailorvector = SailorVectorAssign(sailorfs);
	vector<reservation> resvector = ReserveVectorAssign(reservefs);

	findfind(resvector, boatvector, sailorvector);
	SelectSort(resvector);
	printout(resvector);

	boatfs.close(); sailorfs.close(); reservefs.close();

	// tie a yellow ribbon 'round the old oak tree 'cause this boy's comin' home
	return 0;
}