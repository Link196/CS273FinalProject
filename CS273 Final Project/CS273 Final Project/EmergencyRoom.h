#ifndef EMERGENCYROOM_H_
#define EMERGERNCYROOM_H_
#include<iostream>
#include <queue>
#include "Caregiver.h"
#include "Doctor.h"
#include "EnterQueue.h"
#include "InjuryQueue.h"
#include "Nurse.h"
#include "Patients.h"
#include "Random.h"
#include <vector>

using namespace std;

class EmergencyRoom
{
private:
	EnterQueue *enter;
	InjuryQueue injury;
	vector<Caregiver*> workers;
	int numPatients;
	int arrival = 0;;
	double arrival_rate;            // plane arrival rate per minute
	std::queue<Patients *> the_queue;  // queue of planes in the landing queue
	int total_wait;  // total accumulated wait time in the landing queue
	int num_served=0;  // number of planes served through the landing queue

public:
	EmergencyRoom() {}
	int getNumServed()
	{
		return num_served;
	}
	void set_arrival_rate(double arrival_rate) {
		this->arrival_rate = arrival_rate;
	}

	int get_total_wait() {
		return total_wait;
	}


	/*void update(int clock)
	{
		Patients *p;

		if (random.nextDouble() < arrival_rate) {
			the_queue.push(p);
		}

	}*/

	void numWorkers(int doctor, int nurse)
	{
		for (int i = 0; i < nurse; i++)
		{
		workers.push_back(new(Nurse));
		}
		for (int x = 0; x < doctor; x++) 
		{
			workers.push_back(new(Doctor));
		}

	}
	void newPatient(int clock)
	{
		Patients patient(clock);
		int x = 0;
		patient.injury();
		x = patient.getInjury();
		if (x <= 10)
			injury.setLow(patient);
		else
			injury.setHigh(patient);
		numPatients++;
	}
	void Treat(int &clock, Caregiver *worker)
	{
		if (worker->getComplete() <= clock)
		{
			num_served++;
		}
	}

	void update(int clock)
	{
		if (clock == 0)
			newPatient(clock);
		else if (clock - arrival >= arrival_rate)
		{
			newPatient(clock);
			arrival = clock;
		}
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i]->withPatient())
				Treat(clock, workers[i]);
			else if (!workers[i]->withPatient())
			{
				workers[i]->attendPatient();
			}		
		}
	}
};






#endif