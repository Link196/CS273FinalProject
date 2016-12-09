#ifndef NURSE_H_
#define NURSE_H_

#include <queue>
#include "Caregiver.h"
#include"Patients.h"

class Nurse 
{
private:
	int numTreated=0;
	int timeTreated=0;
	int treatmentTime=0;
public:
	Nurse() {}
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
		treatmentTime = rand() % 1 + 10;
	}
}; 

#endif