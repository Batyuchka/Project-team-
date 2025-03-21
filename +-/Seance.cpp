#include "Seance.h"

Seance::Seance(string t, string c, double d, string da, double st)
	: Film(t,c,d), day(da) , start_seance(st)
{}

int Seance::getEndTime() const
{
	return start_seance + f_duration;
}

void Seance::moveToNextDay()
{
	static string days[] = { "Monday","Tuesday" ,"Wednesday","Thursday" ,"Friday" ,"Saturday" };
	for (int i = 0; i < 7; i++)
	{
		if (days[i] == day)
		{
			day = days[(i + 1) % 7];
			break;
		}
	}
}

//void Seance::printOn() const
//{
//}

//bool Seance::operator<(const Seance& S) const
//{
//	return false;
//}
