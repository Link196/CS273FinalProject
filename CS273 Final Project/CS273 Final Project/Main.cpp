/////////////////////////////////////////////////////////
// Program Name: Emergency Room Simulator
// Authors: Andrew Hutson and McKenna Galle
// Copyright © 2016 All rights reserved.
/////////////////////////////////////////////////////////

#include "Simulator.h"

Simulator Emergency;

int main()
{
	Emergency.Data();
	Emergency.runSimulator();
	Emergency.showStats();
	Emergency.enterData();
	return 0;
}