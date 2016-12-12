#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include<ios>
#include "TreatmentQueue.h"
#include "Entrance.h"
#include "Random.h"

Random random;

using namespace std;

// We will use a map to store how many time each person was treated

class Simulator
{
private:
	int clock;
	int totalTime;
	
	TreatmentQueue *treatment_queue;
	EntranceQueue *entrance_queue;

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
	Simulator()
	{
		treatment_queue = new TreatmentQueue();
		entrance_queue = new EntranceQueue();
	}

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
		int rate = read_int("Please enter the patients arrival rate: ", 1, 59);
		double arrival_rate = rate / 60;
		totalTime *= 60;

		entrance_queue->setArrivalRate(arrival_rate);
		treatment_queue->setMaxSize(60);
		treatment_queue->setEntranceQueue(entrance_queue);

	}

	void runSimulator()
	{
		for (clock = 10080; clock > 0; clock--)
		{
			entrance_queue->update(clock);
			treatment_queue->update(clock);
		}
		
	}

	void showStats()
	{
		cout << entrance_queue->getNumServed << endl;
	}
};

#endif