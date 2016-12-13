#ifndef LowQueue_H_
#define LowQueue_H_
#include <queue>
#include "Patients.h"
#include<iostream>
using namespace std;
class LowQueue
{
private:
	queue<Patients> Lowqueue; // Queue to store the low priority injuries
public:
	LowQueue() {}
	// to move things into the queue
	void setLow(Patients p)
	{
		Lowqueue.push(p);
	}
	// removes the first item from the queue
	void removePatient()
	{
		Lowqueue.pop();
	}
	// finds the size of the queue
	int size()
	{
		return Lowqueue.size();
	}
	// returns true if the queue is empty
	bool empty()
	{
		return Lowqueue.empty();
	}
	// Returns the first thing the queue
	Patients top() {
		return Lowqueue.front();
	}
};


#endif
