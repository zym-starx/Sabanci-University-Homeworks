// Zeynep Yildiz 
// 00029325
// submitted: 16/12/2021

#pragma once

class Car
{
private:
	double fuel;
	double ins_fee;
	int dist_total;
public:
	Car(double fuel, double fee, int distance);
	void display();
	void changefuel(int a);
	void changedist(int km);
	double fullfuel();
	double changefee(int percent);
};