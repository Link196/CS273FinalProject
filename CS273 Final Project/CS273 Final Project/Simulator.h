#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include "Random.h"
#include "EmergencyRoom.h"

extern Random random;

using namespace std;

// We will use a map to store how many time each person was treated

class Simulator
{
private:
	int clock; // Keeps track of total time 
	int totalTime =10080; // Time the whole simulation takes
	EmergencyRoom* Room = new EmergencyRoom(); // pointer to emergencyRoom
	

	int read_int(const string &prompt, int low, int high) // takes in a prompt string to display to the user, and takes in integer upper and lower limits, then returns the inputted integer
	{
		if (low >= high) // invalid range
			throw invalid_argument("invalid range specified");

		cin.exceptions(ios_base::failbit);
		int num = 0;
		while (true) 
		{
			try 
			{
				while (true) 
				{
					cout << prompt;
					cin >> num;
					if (num >= low && num <= high) 
					{ // within the specified range
						cout << endl;
						return num;
					}
				}
			}
			catch (ios_base::failure) 
			{
				cout << "Bad numeric string -- try again\n";
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
			}
		}
	}

public:
	void Data() {
		
		int doctors = read_int("How many Doctors? ", 1, 5);
		int nurses = read_int("How many Nurses? ", 1, 5);
		Room->numWorkers(doctors, nurses);
		int Rate = read_int("What is the arrival rate of Patients? ", 1, 59);
		double arrival_rate = Rate/60.0;
		Room->set_arrival_rate(arrival_rate);

	}
	Simulator() {}

	void enterData()
	{
	//	string citizens[2000];
	//	ifstream data;

	//	//////IF NOT RUNNING THIS ON ANDREW'S LAPTOP, YOU NEED TO CHANGE THIS FILE PATH TO THE CORRECT FILEPATH FOR YOU//////
	//	data.open("C:\\Users\\Andrew Hutson\\OneDrive\\Documents\\Whitworth University\\2016-2017\\Fall 2016\\Data Structures\\Simulation Project\\residents_of_273ville.txt");
	//	
	//	//if can't open
	//	if (data.fail())
	//	{
	//		cout << "Couldn't open file." << endl;
	//	}

	//	for (int i = 0; i < 2000; i++)
	//	{
	//		getline(data, citizens[i], '\n');
	//	}

	//	data.close();

		// next, create citizen objects and all the other crap we need
		/*int rate = read_int("Please enter the patients arrival rate: ", 1, 59);
		double arrival_rate = rate / 60;
		totalTime *= 60;*/

		
		

	}

	void runSimulator()
	{
		// keeps running the simulation until it has been a whole week
		while (clock < totalTime) 
		{
			Room->update(clock);
			clock++;
		}
		cout << "DONE!!!!\n";
	}

	void showStats()
	{
		
		// Returns the amount of Patients that were created and treated in the simulation
		int numPatients = Room->getNumPatients();
		cout << "Number of Patients Treated: ";
		cout << numPatients << endl;
		// Finds the average Wait time for each patient
		int Totalwait = numPatients + Room->Wating() * 10080; // takes the total patients and adds the waiting time *'s  the total time
		cout << "Average vist time: " << (Room->get_total_wait() / Totalwait) * 20; // Then the total wait time and divides by the total time and *'s that by the max wait time
		cout << endl;
	}
};

#endif