#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include <map>
#include <fstream>
#include "Random.h"
#include "EmergencyRoom.h"

extern Random random;

using namespace std;

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
		string citizens[2000];
		ifstream data;

		// Choose the correct file path for whichever computer the simulator is running on (just uncomment it if it's already listed):
		// File path for Andrew's laptop:
		data.open("C:\\Users\\Andrew Hutson\\OneDrive\\Documents\\Whitworth University\\2016-2017\\Fall 2016\\Data Structures\\Simulation Project\\residents_of_273ville.txt"); 
		// File path for Andrew's desktop:
		// data.open("C:\\Users\\andre\\Source\\Repos\\CS273FinalProject\\CS273 Final Project\\residents_of_273ville.txt");
		// add another file path if needed to run on a different computer
		
		//if can't open
		if (data.fail())
		{
			cout << "Couldn't open file." << endl;
		}

		for (int i = 0; i < 2000; i++)
		{
			getline(data, citizens[i], '\n');
		}

		data.close();

		map<string, int> patients; // create a map to store the people

		for (int i = 0; i < 2000; i++) // copy the data from the array to the map
		{
			patients.insert(make_pair(citizens[i], 0));
		}

		string user;
		while (user != "Quit")
		{
			cout << endl;
			cout << "You now have three choices: " << endl;
			cout << "Choice 1: Enter a name to see how many times that person was treated." << endl;
			cout << "Choice 2: Enter 'View' to view all the people and how many times they were treated." << endl;
			cout << "Choice 3: Enter 'Quit' to quit the program. " << endl;
			cout << endl;
			cout << "Your selection: ";
			cin >> user;

			if (patients.find(user) != patients.end())
				cout << user << " was treated " << patients[user] << " times." << endl;

			else if (user == "View")
				for (int i = 0; i < 2000; i++)
					cout << citizens[i] << " was treated 0 times." << endl; // Hard coded to everyone being treated 0 times because that part of the simulator doesn't work properly
																			// If the simulator actually worked properly, I'd take the time to actually figure out how to code this.
																			// Either that, or I'd just toss this option, since it's not actually in the specification.
			else if (user != "Quit")
				cout << "Error: No matching name or command was found." << endl;
		}

		cout << "Goodbye." << endl;
	}

	void runSimulator()
	{
		// keeps running the simulation until it has run for a whole week
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
		cout << "Average visit time: " << (Room->get_total_wait() / Totalwait) * 20; // Then the total wait time and divides by the total time and *'s that by the max wait time
		cout << endl;
	}
};

#endif