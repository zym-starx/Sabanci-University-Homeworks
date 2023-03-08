// Zeynep Yildiz 
// 00029325
// submitted: 16/12/2021

#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(double benzin = 300, double fee = 1000, int distance = 5000)
{
	fuel = benzin;
	ins_fee = fee;
	dist_total = distance;
}

void Car::display()
{
	cout << "Fuel Level: " << fuel << endl;
	cout << "Insurance Fee: " << ins_fee << endl;
	cout << "Total distance that car has travelled: " << dist_total << endl;
}

void Car::changedist(int km)
{
	dist_total += km;
}

void Car::changefuel(int a)
{
	fuel = fuel - a * (0.25);
}

double Car::changefee(int percent)
{
	ins_fee += ins_fee * percent / 100;
	return ins_fee;
}

double Car::fullfuel()
{
	double returnvalue = 300 - fuel;
	fuel = 300;
	cout << endl << "Fuel is full" << endl;
	return returnvalue;
}