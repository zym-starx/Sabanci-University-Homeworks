// Zeynep Yildiz 
// 00029325
// submitted: 16/12/2021

#pragma once

#include <string>
#include <iostream>
#include "Car.h"

using namespace std;

class Driver
{
private:
	double budget;
	Car &sharedCar;
public:
	Driver(Car &sharedcar, double budg);
	void drive(int km);
	void repairCar(string accident);
	void display();
	void fullFuel();
};