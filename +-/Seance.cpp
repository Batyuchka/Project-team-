#include "Seance.h"
#include <sstream>

Seance::Seance(string t, string c, double d, string da, string st)
	: Film(t,c,d), day(da) , start_seance(st)
{}

string Seance::getEndTime()
{
	int hours, minutes;
	char delimiter;

	stringstream ss(start_seance);
	ss >> hours >> delimiter >> minutes;
	hours += (minutes + f_duration) / 60;
	minutes = (minutes + f_duration) % 60;
	string endTime = to_string(hours) + ":" + to_string(minutes);
	
	return endTime;                            
}

void Seance::moveToNextDay()
{
	string days[] = { "Monday","Tuesday" ,"Wednesday","Thursday" ,"Friday" ,"Saturday" ,"Sunday"};
	for (int i = 0; i < 7; i++)
	{
		if (days[i] == day)
		{
			day = days[(i + 1) % 7];
			break;
		}
	}
}

void Seance::printOn() const
{

}

//bool Seance::operator<(const Seance& S) const
//{
//	return false;
//}
