#ifndef ENTRERQUEUE_H_
#define ENTERQUEUE_H_

#include <iostream>
#include <string>
#include <queue>
#include "Patients.h"
#include "Random.h"

extern Random random;  // Enables us to access the global variable declared in Simulator.h

class EnterQueue
{
private:
	
	double arrival_rate;            // plane arrival rate per minute
	std::queue<Patients *> the_queue;  // queue of planes in the landing queue
	int total_wait;  // total accumulated wait time in the landing queue
	int num_served;  // number of planes served through the landing queue
public:
	EnterQueue() : total_wait(0), num_served(0) {}

	void set_arrival_rate(double arrival_rate) {
		this->arrival_rate = arrival_rate;
	}

	int get_total_wait() {
		return total_wait;
	}

	int get_num_served() {
		return num_served;
	}

	void update(int clock)
	{
		Patients *p;

		if (random.nextDouble() < arrival_rate) {
			the_queue.push(p);
		}

	}

	friend class Injury;

};
#endif
