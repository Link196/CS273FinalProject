#ifndef INJURYQUEUE_H_
#define INJURYQUEUE_H_
#include <queue>
#include "Patients.h"
#include<iostream>
using namespace std;
class InjuryQueue
{
private:
	queue<Patients> Highqueue;
	queue<Patients> LowQueue;
public:
	InjuryQueue() {}
	InjuryQueue(int injury, Patients p) {
		if (injury <= 10)
			LowQueue.push(p);
		else
			Highqueue.push(p);
	}
	void setLow(Patients p)
	{
		LowQueue.push(p);
	}
	queue<Patients> getlow()
	{
		return LowQueue;
	}
	void setHigh(Patients p)
	{
		Highqueue.push(p);
	}
	queue<Patients> getHigh()
	{
		return Highqueue;
	}
};


#endif
