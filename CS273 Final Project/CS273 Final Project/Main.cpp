/////////////////////////////////////////////////////////
// Program Name: Emergency Room Simulator
// Authors: Andrew Hutson and McKenna Galle
// Copyright © 2016 All rights reserved.
/////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "Caregiver.h"
#include "Citizens.h"
#include "Doctor.h"
// #include "EmergencyRoom.h" - probably going to get deleted
// #include "EntranceQueue.h"
#include "Nurse.h"
#include "Patients.h"
#include "Simulator.h"
#include "TreatmentQueue.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Simulator EmergencyRoom;

int main()
{
	
	EmergencyRoom.enterData();

	return 0;
}