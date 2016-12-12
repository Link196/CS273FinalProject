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

public:
	EmergencyRoom() {}
	void numWorkers(int doctor, int nurse)
	{
		for (int i = 0; i < nurse; i++)
			workers.push_back(new(Nurse));
		for (int x = 0; x < doctor; x++) {
			workers.push_back(new(Doctor));
		}

	}
	void newPatiant(int clock)
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
};






#endif