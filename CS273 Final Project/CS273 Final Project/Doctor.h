#ifndef DOCTOR_H_
#define DOCTOR_H_

#include <queue>
#include "Caregiver.h"
#include "Patients.h"

class Doctor 
{
private:
	int numTreated = 0;
	int timeTreated = 0;
	int treatmentTime = 0;
public:
	Doctor() {}
	int getNumtreated()
	{
		return numTreated;
	}
	void setNumTreated(int treated)
	{
		numTreated = treated;
	}
	int getTimeTreated()
	{
		return timeTreated;
	}
	void setTimeTreated(int time)
	{
		timeTreated = time;
	}
	int getTreatmentTime()
	{
		return treatmentTime;
	}
	int setTreatmentTime()
	{
		treatmentTime = rand() % 1 + 20;
	}
};
#endif 
