#ifndef DOCTOR_H_
#define DOCTOR_H_


#include "Caregiver.h"
#include "Patients.h"


class Doctor : public Caregiver
{
public:
	
	Doctor()
	{
		setMinTreat(1); //sets the minimum treatment time for a doctor
		setMinTreat(20); // sets the maximum treatment time for a doctor
		setPrioirty(20); // sets the number the doctor is allowed to treat
		
	}
	void attendPatient() {
	
	}
};
#endif 
