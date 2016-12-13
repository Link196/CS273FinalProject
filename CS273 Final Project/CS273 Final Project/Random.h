#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <ctime>


class Random 
{

public:

	Random() 
	{
		srand((unsigned int)std::time(0)); // initializes the random number generator
	}

	Random(int seed) 
	{
		srand(seed); // generates a random number based on a value passed to the function
	}


	int nextInt(int n) 
	{
		return int(nextDouble() * n); // returns an integer multiple of a randomly generated double
	}

	double nextDouble() 
	{
		return double(rand()) / RAND_MAX; // retuns a random double value
	}

};

#endif