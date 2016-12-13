#ifndef EMERGENCYROOM_H_
#define EMERGERNCYROOM_H_
#include<iostream>
#include <queue>
#include "Caregiver.h"
#include "Doctor.h"
#include "EnterQueue.h"
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
	EnterQueue *enter;
	HighInjuryQueue Highinjury;
	LowQueue Lowinjury;
	vector<Caregiver*> workers;
	int numPatients=0;
	int arrival = 0;
	double arrivalRate=0.0;            // plane arrival rate per minute
	std::queue<Patients *> the_queue;  // queue of planes in the landing queue
	double total_wait = 0;  // total accumulated wait time in the landing queue
	int num_served=0;  // number of planes served through the landing queue

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
	int getNumPatiants()
	{
		return numPatients;
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
		numPatients++;
		Patients patient(clock);
		patient.injury();
		if (patient.getInjury() <= 10)
			Lowinjury.setLow(patient);
		else if (patient.getInjury() > 10)
			Highinjury.setHigh(patient);
		
	}
	void Treat(int clock, Caregiver *worker)
	{
		if (worker->getComplete() <= clock)
		{
			num_served++;	
		}
	}

	void update(int& clock)
	{
		if (clock == 0) {
			newPatient(clock);
			total_wait = (total_wait + clock);
		}
		 if (clock-arrival >= arrivalRate)
		{
			newPatient(clock);
			arrival = clock;
			total_wait = (total_wait + clock);
		}
		for (int i =0; i < workers.size(); i++)
		{
			if (workers[i]->withPatient())
				Treat(clock, workers[i]);
			if (!workers[i]->withPatient())
			{
				workers[i]->attendPatient(Highinjury,Lowinjury,clock);
			}		
		}
	}
	int Wating()
	{
		return Highinjury.size()+Lowinjury.size();
	}
	
};

#endif