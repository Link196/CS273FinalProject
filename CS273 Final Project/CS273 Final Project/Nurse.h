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
	// the function for treating to a patient
	void attendPatient(HighInjuryQueue& h, LowQueue& l, int clock) {
		// checks to see if the HighInjuryQueue is empty
		if (h.empty())
		{
			// checkt to see if LowInjuryQueue is not empty
			if (!l.empty())
			{
				// Creates a temporary patient and moves them to the top of the queue
				Patients *NewPatient = new Patients(l.top());
				Patient = NewPatient;
				// Starts the treat time
				this->setTreatTime(clock);
				// removes the temporary patient
				l.removePatient();
			}
		}
		else
		{
			// creates a temporary patient
			Patients *NewPatient = new Patients(h.top());
			Patient = NewPatient;
			// start the Treat time
			this->setTreatTime(clock);
			// removes the teporary patient 
			h.removePatient();
		}

	}
}; 

#endif