#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <ctime>


class Random {

public:

	Random() {
		srand((unsigned int)std::time(0));
	}

	Random(int seed) {
		srand(seed);
	}


	int nextInt(int n) {
		return int(nextDouble() * n);
	}

	double nextDouble() {
		return double(rand()) / RAND_MAX;
	}

};

#endif