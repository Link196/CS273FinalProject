#ifndef PATIENTS_H_
#define PATIENTS_H_
#include <string>

class Patients
{
private:
	int arrivalTime = 0;
	int depatureTime = 0;
	int timetreated = 0;
	int totalWait = 0;
	std::string name;
public:
	Patients(std::string Newname)
	{
		name = Newname;
		totalWait = 0;
	}
	int getarrivalTime()
	{
		return arrivalTime;
	}
	void setarrivalTime(int newarrival)
	{
		arrivalTime = newarrival;
	}
	int getdepatureTime()
	{
		return depatureTime;
	}
	void setDepatureTime(int newDepature)
	{
		deaptureTime = newDeapture;
	}
	int getTimetreated()
	{
		return timetreated;
	}
	void setTimetreated(int time)
	{
		timetreated = time;
	}
	int getTotalWait()
	{
		return totalWait;
	}
	void setTotalWait(int wait)
	{
		totalWait = wait;
	}
	string getName()
	{
		return name;
	}
	void setName(int newname)
	{
		name = newname;
	}
};


#endif
