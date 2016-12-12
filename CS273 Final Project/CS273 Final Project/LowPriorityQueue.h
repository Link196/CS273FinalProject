#ifndef LOWINJURYQUEUE_H_
#define LOWINJURYQUEUE_H_
#include <queue>
#include "Patients.h"
#include<iostream>
using namespace std;
class Lowinjury
{
private:
	priority_queue<Patients> the_queue;
public:
	Lowinjury(Lowinjury &low) {
		the_queue = low.the_queue;
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
