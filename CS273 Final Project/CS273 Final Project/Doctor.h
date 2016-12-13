#ifndef DOCTOR_H_
#define DOCTOR_H_


#include "Caregiver.h"
#include "Patients.h"
#include "HighInjuryQueue.h"
#include "LowQueue.h"


class Doctor : public Caregiver
{
private:
	Patients *Patient;
public:
	
	Doctor()
	{
		setMinTreat(1); //sets the minimum treatment time for a doctor
		setMinTreat(20); // sets the maximum treatment time for a doctor
		setPrioirty(20); // sets the number the doctor is allowed to treat
		
	}
	// the function for treating to a patient
	void attendPatient(HighInjuryQueue& h,LowQueue& l,int clock) {
		// checks to see if the HighInjuryQueue is empty
		if (!h.empty())
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
