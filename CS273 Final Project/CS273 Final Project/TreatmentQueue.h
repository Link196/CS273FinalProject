#ifndef TREATMENTQUEUE_H_
#define TREATMENTQUEUE_H_

#include <queue> 
#include "Patients.h"
#include "Entrance.h"
#include "Random"

extern Random random;

class TreatmentQueue {
private:
	EntranceQueue *entranceQueue;
	std::queue < Patients *> the_queue;
	int max;
public:
	void setEntranceQueue(EntranceQueue*entrancequeue)
	{
		this->entranceQueue = entrancequeue;
	}
	void setTimes(int maxSize)
	{
		this->max = maxSize;
	}
	void setMaxSize(int Max)
	{
		max = Max;
	}
	void update(int clock)
	{
		if (!the_queue.empty())
		{
			Patients *paitent = the_queue.front();
		}
		if (the_queue.size() < max)
		{
			if (!entranceQueue->the_queue.empty())
			{
				Patients *patient = entranceQueue->the_queue.front();
				entranceQueue->the_queue.pop();
				entranceQueue->numServed++;
				entranceQueue->totalWait += clock - patient->arrivalTime;
				the_queue.push(patient);

			}
		}
	}
};
#endif