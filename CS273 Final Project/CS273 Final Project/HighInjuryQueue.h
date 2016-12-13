#ifndef INJURYQUEUE_H_
#define INJURYQUEUE_H_
#include <queue>
#include "Patients.h"
#include<iostream>
using namespace std;
class HighInjuryQueue
{
private:
	queue<Patients> Highqueue; // queue for the high priority injuries
public:
	HighInjuryQueue() {}

	// Moves object into the queue
	void setHigh(Patients p)
	{
		Highqueue.push(p);
	}
	// removes the first item in the queue
	void removePatient()
	{
		Highqueue.pop();
	}
	// returns true if the queue is empty
	bool empty()
	{
		return Highqueue.empty();
	}
	// returns the size of the queue
	int size()
	{
		return Highqueue.size();
	}
	// returns the object in the front the queue
	Patients top()
	{
		return Highqueue.front();
	}
};


#endif
