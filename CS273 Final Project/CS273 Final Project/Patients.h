#ifndef PATIENTS_H_
#define PATIENTS_H_
#include <string>
#include <ctime>

class Patients
{
private:
	int arrivalTime = 0;
	int depatureTime = 0;
	int timetreated = 0;
	int totalWait = 0;
	std::string name;
public:
	Patients() {}
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
		depatureTime = newDepature;
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
	std::string getName()
	{
		return name;
	}
	void setName(int newname)
	{
		name = newname;
	}
	int injury()
	{
		// picks a number between 1 and 10
		int x = rand() % 10;
		int injury;
		// there is a seventy percent chance the number is between 1 and 10
		if (x <= 6)
			injury = rand() % 10+1;
		// 20 percent chance the number is between 11 and 15
		else if (x == 7 || x == 8)
			injury = rand()%4+11;
		// 10 percent change the number is between 16 and 20
		else
			injury = rand()%4+16;
		return injury;
	}
	void update()
	{}
};


#endif