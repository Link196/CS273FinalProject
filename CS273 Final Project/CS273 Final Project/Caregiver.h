#ifndef CARGIVER_H_
#define CARGIVER_H_
#include "Patients.h"
class Cargiver
{
	virtual void treatPatient(Patient *p) = 0;
	virtual void update()  = 0;
};
#endif // !CARGIVER_H_
