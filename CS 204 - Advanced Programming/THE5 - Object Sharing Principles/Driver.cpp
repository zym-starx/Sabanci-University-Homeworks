// Zeynep Yildiz 
// 00029325
// submitted: 16/12/2021

#include "Driver.h"

using namespace std;
 
Driver::Driver(Car& sc, double budg)
	: sharedCar(sc), budget(budg)
{}

void Driver::display()
{
	cout << endl << "Driver budget: " << budget << endl;
}

void Driver::repairCar(string accident)
{
	double fee;
	if (accident == "SMALL")
	{
		budget -= 50;
		fee = sharedCar.changefee(5);
		cout << "50$ is reduced from the driver's budget because of the SMALL accident" << endl;
		cout << "Yearly insurance fee is increased to " << fee << " because of the SMALL accident" << endl;
	}
	else if (accident == "MEDIUM")
	{
		budget -= 150;
		fee = sharedCar.changefee(10);
		cout << "150$ is reduced from the driver's budget because of the MEDIUM accident" << endl;
		cout << "Yearly insurance fee is increased to " << fee << " because of the MEDIUM accident" << endl;
	}
	else if (accident == "LARGE")
	{
		budget -= 300;
		fee = sharedCar.changefee(20);
		cout << "300$ is reduced from the driver's budget because of the LARGE accident" << endl;
		cout << "Yearly insurance fee is increased to " << fee << " because of the LARGE accident" << endl;
	}
}

void Driver::fullFuel()
{
	double price = sharedCar.fullfuel();   //price is equal to how much fuel has been used.
	budget -= price;
}

void Driver::drive(int km)
{
	sharedCar.changedist(km);
	sharedCar.changefuel(km);
}