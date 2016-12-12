#ifndef PATIENTS_H_
#define PATIENTS_H_
#include <string>
#include <ctime>

class Patients
{
private:
	
	int arrivalTime = 0;
	int depatureTime = 0;
	std::string name;
	int TotalWait = 0;
	int Injury = 0;
public:
	Patients(int clock)
	{
		arrivalTime=clock;
		depatureTime=-1;
		
	}
	int getInjury()
	{
		return Injury;
	}
	void setInjury(int i)
	{
		Injury = i;
	}
	int getTotalWait()
	{
		return TotalWait;
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
		
		// there is a seventy percent chance the number is between 1 and 10
		if (x <= 6)
			Injury = rand() % 10+1;
		// 20 percent chance the number is between 11 and 15
		else if (x == 7 || x == 8)
			Injury = rand()%4+11;
		// 10 percent change the number is between 16 and 20
		else
			Injury = rand()%4+16;
	}
	struct patients {
		bool operator()( Patients p1, Patients p2)const
		{
			if (p1.getInjury() < p2.getInjury())
				return false;
			else
				return true;
		}
	};
	void update()
	{}
};


#endif