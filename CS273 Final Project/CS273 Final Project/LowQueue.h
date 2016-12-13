#ifndef LowQueue_H_
#define LowQueue_H_
#include <queue>
#include "Patients.h"
#include<iostream>
using namespace std;
class LowQueue
{
private:
	queue<Patients> Lowqueue;
public:
	LowQueue() {}
	void setLow(Patients p)
	{
		Lowqueue.push(p);
	}
	void removePatient()
	{
		Lowqueue.pop();
	}

	int size()
	{
		return Lowqueue.size();
	}
	bool empty()
	{
		return Lowqueue.empty();
	}
	Patients top() {
		return Lowqueue.front();
	}
};


#endif
