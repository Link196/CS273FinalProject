#ifndef INJURYQUEUE_H_
#define INJURYQUEUE_H_
#include <queue>
#include "Patients.h"
#include<iostream>
using namespace std;
class HighInjuryQueue
{
private:
	queue<Patients> Highqueue;
public:
	HighInjuryQueue() {}
	void setHigh(Patients p)
	{
		Highqueue.push(p);
	}
	void removePatient()
	{
		Highqueue.pop();
	}
	bool empty()
	{
		return Highqueue.empty();
	}
	
	int size()
	{
		return Highqueue.size();
	}
	Patients top()
	{
		return Highqueue.front();
	}
};


#endif
