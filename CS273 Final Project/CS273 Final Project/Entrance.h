#ifndef ENTRANCE_H_
#define ENTRANCE_H_

#include <queue>
#include <string>
#include "Patients.h"
#include "Random.h"

extern Random random;
class EntranceQueue

{
private:
	double arrivalRate;
	std::queue<Patients *> the_queue;
	int totalWait = 0;
	int numServed = 0;
public:
	EntranceQueue() : totalWait(0), numServed(0) {}

	void setArrivalRate(double arrival_rate) {
		this->arrivalRate = arrival_rate;
	}
	int getTotalWait() {
		return totalWait;
	}

	int getNumServed() {
		return numServed;
	}
	void update(int clock) {
		if (random.nextDouble() < arrivalRate) {
			the_queue.push(new Patients(clock));
		}
	}
	friend class TreatmentQueue;
};





#endif