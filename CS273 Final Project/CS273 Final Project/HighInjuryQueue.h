#ifndef HIGHINJURYQUEUE_H_
#define HIGHINJURYQUEUE_H_
#include <queue>
#include "Patients.h"
#include<iostream>
using namespace std;
class Highinjury
{
private:
	priority_queue<Patients> the_queue;
public:
	Highinjury(Highinjury &high) {
		the_queue = high.the_queue;
	}

	void inputPatients(Patients p1)
	{
		the_queue.push(p1);
	}
	void finishedPatients(Patients p1)
	{
		the_queue.pop();
	}
};


#endif