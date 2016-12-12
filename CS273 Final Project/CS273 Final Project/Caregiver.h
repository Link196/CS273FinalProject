#ifndef CARGIVER_H_
#define CARGIVER_H_

#include "Patients.h"

class Caregiver {

private:

	int minTreat; //the minimum treatment time
	int maxTreat;	// the maximum treatment time
	int Complete; // time until treatment is complete
	Patients *p; // pointer to patients object
	int priority; // max prioirty between patients

public:
	// contructor to set the treatment times for the simulation
	Caregiver(int minTreatment, int maxTreatment, int maxpriority)
	{
		minTreat = minTreatment;
		maxTreat = maxTreatment;
		p=NULL; 
		priority = maxpriority;
	}
	Caregiver() {}
	
	// the random treatment time for the employee
	void setTreatTime(int clock) {
		Complete = (rand() % (maxTreat - minTreat)+clock);
	}
	int getComplete()
	{
		return Complete; //returns the time it took to complete treatment
	}
	void setComplete(int complete)
	{
		Complete = complete;
	}
	int getMinTreat() 
	{ 
		return  minTreat;
	}
	void setMinTreat(int min)
	{
		minTreat = min;
	}
	int getPriority() 
	{ 
		return priority;
	}
	void setPrioirty(int p)
	{
		priority = p;
	}
	int getMaxTreat() 
	{
		return maxTreat; 
	}
	void setmaxTreat(int max)
	{
		maxTreat = max;
	}

	// looks to see if the cargiver is treating the patients or not.
	bool withPatient()
	{
		if (p == NULL)
			return false;
		else
			return true;
	}
	// sets the doctor to start attending to the patient
	virtual void attendPatient() = 0;
};
#endif 