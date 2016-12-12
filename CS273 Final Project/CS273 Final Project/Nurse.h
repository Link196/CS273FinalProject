#ifndef NURSE_H_
#define NURSE_H_


#include "Caregiver.h"
#include"Patients.h"

class Nurse:public Caregiver 
{
public:
	Nurse()
	{
		setMinTreat(1); // sets the minimum treatment for the nurse
		setMinTreat(10); // sets the maximum treatment time fot he nurse
		setPrioirty(10); // sets the prioirty the nurse is allowed to treat
	}
	void attendPatient() {}
}; 

#endif