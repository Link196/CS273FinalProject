#ifndef NURSE_H_
#define NURSE_H_


#include "Caregiver.h"
#include"Patients.h"

class Nurse:public Caregiver 
{
private:
	Patients *Patient;
public:
	Nurse()
	{
		setMinTreat(1); // sets the minimum treatment for the nurse
		setMinTreat(10); // sets the maximum treatment time fot he nurse
		setPrioirty(10); // sets the prioirty the nurse is allowed to treat
	}
	void attendPatient(HighInjuryQueue& h, LowQueue& l, int clock) {
		if (h.empty())
		{
			if (!l.empty())
			{
				Patients *NewPatient = new Patients(l.top());
				Patient = NewPatient;
				this->setTreatTime(clock);
				l.removePatient();
			}
		}
		else
		{
			Patients *NewPatient = new Patients(h.top());
			Patient = NewPatient;
			this->setTreatTime(clock);
			h.removePatient();
		}

	}
}; 

#endif