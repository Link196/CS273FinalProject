#ifndef EMERGENCYROOM_H_
#define EMERGERNCYROOM_H_
#include<iostream>
#include <queue>
#include "Caregiver.h"
#include "Doctor.h"
#include "HighInjuryQueue.h"
#include "LowQueue.h"
#include "Nurse.h"
#include "Patients.h"
#include "Random.h"
#include <vector>

using namespace std;
Random random;

class EmergencyRoom
{
private:
	
	HighInjuryQueue Highinjury; // creates a highinjury queue
	LowQueue Lowinjury;			// creates a lowinjury queue
	vector<Caregiver*> workers; // creates a vector of doctors and nurses
	int numPatients=0;			// total number of patients treated
	int arrival = 0;			// the last patient to arrive 
	double arrivalRate=0.0;            // patient arrival rate per minute
	double total_wait = 0;  // total accumulated wait time while being treated
	int num_served=0;  // number of patients served 

public:
	EmergencyRoom() {}

	int getNumServed()
	{
		return num_served;
	}
	void set_arrival_rate(double arrival_rate) {
		arrivalRate = arrival_rate;
	}

	double get_total_wait() {
		return total_wait;
	}
	double getArrivalRate()
	{
		return arrivalRate;
	}
	int getNumPatients()
	{
		return numPatients;
	}
	
	// creates the correct number of doctors and nurses
	void numWorkers(int doctor, int nurse)
	{
		for (int i = 0; i < nurse; i++)
		{
		// Pushes the number of nurses wanted into the workers vector
		workers.push_back(new(Nurse));
		}
		// pushes the of doctors wanted into the workers vector
		for (int x = 0; x < doctor; x++) 
		{
			workers.push_back(new(Doctor));
		}

	}
	// creates a Patient and assigns them an injury and puts them into correct injury queue
	void newPatient(int clock)
	{
		numPatients++;
		Patients patient(clock);
		patient.injury();
		if (patient.getInjury() <= 10)
			Lowinjury.setLow(patient);
		else if (patient.getInjury() > 10)
			Highinjury.setHigh(patient);	
	}

	void update(int& clock)
	{
		// checks to see if the simulation has started and then add a patient
		if (clock == 0) {
			newPatient(clock);
			total_wait = (total_wait + clock);
		}
		// outputs if the another patient if the random number is less then the arrivalRate 
		 if (random.nextDouble() <= arrivalRate)
		{
			newPatient(clock);
			arrival = clock;
			total_wait = (total_wait + clock);
		}
		
		for (int i =0; i < workers.size(); i++)
		{
			// checks to see if the workers are working if not then it puts them to work
			if (!workers[i]->withPatient())
			{
				workers[i]->attendPatient(Highinjury,Lowinjury,clock);
			}		
		}
	}
	int Wating()
	{
		// returns the total amount of patients
		return Highinjury.size()+Lowinjury.size();
	}
	
};

#endif