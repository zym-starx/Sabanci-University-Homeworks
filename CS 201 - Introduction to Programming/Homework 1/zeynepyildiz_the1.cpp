#include <cmath>
#include <string>
#include <iostream>

using namespace std;

//zeynep yildiz 00029325

int inputCheck(int, double, double, double);

void getInput(string exer, double & x, int & y, double & z)
{
	if (exer == "Weight Lifting") // weight lifting needs a third parameter 
	{
		cout << exer << ": ";
	    cin >> x >> y >> z;
	}
	else
	{
		cout << exer << ": "; // others do not
	    cin >> x >> y;
	}
}

void calculateMET(int reps, string exercise, double & MET)
{ // deciding on MET which changes according to changes of reps and the type of exercise
	if (exercise == "Lunges")
	{
		if (reps < 15)
		{
			MET = 3;
		}
		else if (reps >= 15 && reps < 30)
		{
			MET = 6.5;
		}
		else if (reps >= 30)
		{
			MET = 10.5;
		}
	}
	else if (exercise == "Push Ups")
	{
		if (reps < 15)
		{
			MET = 4;
		}
		else if (reps >= 15)
		{
			MET = 7.5;
		}
	}
	else if (exercise == "Pull Ups")
	{
		if (reps < 25)
		{
			MET = 5;
		}
		else if (reps >= 25)
		{
			MET = 9;
		}
	}
}

void calculateWeightLiftMET(int reps, double weight, double & Met)
{
	//same thing but depends on weight and rep
	if (weight < 5)
	{
		if (reps < 20)
		{
			Met = 3;
		}
		else if (reps >= 20 && reps < 40)
		{
			Met = 5.5;
		}
		else if (reps >= 40)
		{
			Met = 10;
		}
	}
	else if (weight >= 5 && weight < 15)
	{
		if (reps < 20)
		{
			Met = 4;
		}
		else if (reps >= 20 && reps < 40)
		{
			Met = 7.5;
		}
		else if (reps >= 40)
		{
			Met = 12;
		}
	}
	else if (weight >= 15)
	{
		if (reps < 20)
		{
			Met = 5;
		}
		else if (reps >= 20 && reps < 40)
		{
			Met = 9;
		}
		else if (reps >= 40)
		{
			Met = 13.5;
		}
	}
}

void displayResults(double difference, double total, double weight, double lungemet, double pushupmet, double pullupmet, double weightliftmet, double lungeCal, double pushCal, double pullCal, double wlCal)
{
	cout << "From lunges, you burned " << lungeCal << " calories." <<  endl;
	cout << "From push ups, you burned " << pushCal << " calories." << endl;
	cout << "From pull ups, you burned " << pullCal << " calories." << endl;
	cout << "From weight lifting, you burned " << wlCal << " calories." << endl;
	cout << "You burned " << total << " calories." << endl << endl;

	if (difference == 0) //goal = totalcal
	{
		cout << "Congratulations! You have reached your goal!" << endl;
	}
	else if (difference < 0) //totalcal > goal
	{
		cout << "You have surpassed your goal! You can eat something worth " << abs(difference) << " calories :)" << endl;
	}
	else if (difference > 0) //total cal < goal
	{
		double morelunge, morepush, morepull, morewl;

		//minute calculations
		morelunge = (difference * 200) / (lungemet * 3.5 * weight);
		morepush = (difference * 200) / (pushupmet * 3.5 * weight);
		morepull = (difference * 200) / (pullupmet * 3.5 * weight);
		morewl = (difference * 200) / (weightliftmet * 3.5 * weight);

		cout << "You did not reach your goal by " << difference << " calories." << endl;
		cout << "You need to do lunges " << morelunge << " minutes more to reach your goal or," << endl;
		cout << "You need to do push ups " << morepush << " minutes more to reach your goal or," << endl;
		cout << "You need to do pull ups " << morepull << " minutes more to reach your goal or," << endl;
		cout << "You need to do weight lifting " << morewl << " minutes more to reach your goal." << endl;
	}
}

void computeResults(double weight, double goal, int repsLunge, int repsPushUp, int repsPullUp, int repsWeightLift, double minLunge, double minPushUp, double minPullUp, double minWeightLift, double liftedWeight)
{
	double metlung, metshups, metllups, metwl;
	double callung, calpush, calpull, calwl, caltotal, diff;

	//exercise names to check in calculateMET function's if elses
	string lunges = "Lunges";
	string pushups = "Push Ups";
	string pullups = "Pull Ups";
	string liftweight = "Weight Lifting";

	calculateMET(repsLunge, lunges, metlung);
	calculateMET(repsPushUp, pushups, metshups);
	calculateMET(repsPullUp, pullups, metllups);
	calculateWeightLiftMET(repsWeightLift, liftedWeight, metwl);

	//burned calorie calculations
	callung = minLunge * (metlung * 3.5 * weight) / 200;
	calpush = minPushUp * (metshups * 3.5 * weight) / 200;
	calpull = minPullUp * (metllups * 3.5 * weight) / 200;
	calwl = minWeightLift * (metwl * 3.5 * weight) / 200;

	caltotal = callung + calpush + calpull + calwl;
	diff = goal - caltotal;

	displayResults(diff, caltotal, weight, metlung, metshups, metllups, metwl, callung, calpush, calpull, calwl);
}

int main()
{
	double minlung,  minshups,  minllups,  minwl, wewl;
	double goal;
	int replung, repshups, repllups, repwl;
	//exercise names to check in getInput() function's if elses
	string lunges = "Lunges";
	string pushups = "Push Ups";
	string pullups = "Pull Ups";
	string liftweight = "Weight Lifting";

	cout << "Please enter your name: ";
	string name;
	cin >> name;
	cout << "Welcome " << name << ", please enter your weight(kg): ";
	double wght;
	cin >> wght;
	cout << name << ", please enter minutes and repetitions in a week for the activities below." << endl;
	
	getInput(lunges, minlung, replung, wewl);
	getInput(pushups, minshups, repshups, wewl);
	getInput(pullups, minllups, repllups, wewl);

	cout << name << ", please enter minutes, repetitions and lifted weight in a week for the activities below." << endl;

	getInput(liftweight, minwl, repwl, wewl);

	cout << name << ", please enter your weekly calorie burn goal: ";
	cin >> goal;
	

	if (inputCheck(replung, wght, minlung, wewl) == 1)
	{
		
		return 0;
	}
	else
	{
		if (inputCheck(repshups, wght, minshups, wewl) == 1)
		{
			
			return 0;
		}
		else
		{
			if (inputCheck(repllups, wght, minllups, wewl) == 1)
			{
				
				return 0;
			}
			else
			{
				if (inputCheck(repwl, wght, minwl, wewl) == 1)
				{ 
					
					return 0;
				}
				else 
				{
					computeResults(wght, goal, replung, repshups, repllups, repwl, minlung, minshups, minllups, minwl, wewl);


				}
			}
		}
	}

	return 0;
}

int inputCheck(int reps, double weight, double minute, double liftedweight)
{
	if (weight < 30)
	{
		cout << "Weight out of range!" << endl;
		return 1;
	}
	else if ((liftedweight < 0) || (liftedweight > 35))
	{
		cout << "Lifted weight out of range!" << endl;
		return 1;
	}
	else if ((reps < 0) || (reps > 50))
	{
		cout << "Reps out of range!" << endl;
		return 1;
	}
	else if ((minute < 0) || (minute > 2000))
	{
		cout << "Minute out of range!" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

//end

//The following commented out function is the first version of the function inputCheck()
//This indeed works but at the time I was dealing with a problem and I thought maybe something about bool was causing the problem (which was not)
//FYI the function was working just fine the problem was about the if else's in main (later learned that but I had changed a lot of things already
//and I was afraid I would mess things up so I didn't wanted go back)
//so I changed bool with int and true/false with 0/1 
//In case of anything I just wanted to show you that I wrote this too
//Best regards have a nice day

/*
bool inputCheck(int reps, double weight, double minute, double liftedweight)
{
	if (weight < 30)
	{
		cout << "Weight out of range!" << endl;
		return false;
	}
	else if ((liftedweight < 0) || (liftedweight > 35))
	{
		cout << "Lifted weight out of range!" << endl;
		return false;
	}
	else if ((reps < 0) || (reps > 50))
	{
		cout << "Reps out of range!" << endl;
		return false;
	}
	else if ((minute < 0) || (minute > 2000))
	{
		cout << "Minute out of range!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
*/

