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
	void attendPatient(HighInjuryQueue& h,LowQueue& l,int clock) {
		if (!h.empty())
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
