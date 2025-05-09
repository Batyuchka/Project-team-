#include "Seance.h"
#include <sstream>
#include <string>


Seance::Seance(string t, string c, double d, string da, string st)
	: Film(t,c,d), day(da) , start_seance(st)
{}

string Seance::getDay() const
{
	return day;
}

string Seance::getStartSeance() const
{
	return start_seance;
}

string Seance::getEndTime()
{
	int hours = (start_seance[0] - '0') * 10 + (start_seance[1] - '0');
	int minutes = (start_seance[3] - '0') * 10 + (start_seance[4] - '0');

	minutes += static_cast<int>(f_duration);
	hours += minutes / 60;
	minutes %= 60;
	return (hours < 10 ? "0" : "") + to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
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
	cout << "\"" << f_title << "\" (" << f_country << ") - " << f_duration
		<< " min, " << day << ", Start: " << start_seance << "\n";
}

bool Seance::operator<(const Seance& S) const
{
	Duration thisDuration = getDurationAsNumber();
	Duration otherDuration = S.getDurationAsNumber();

	int thisTotalMinutes = thisDuration.hours * 60 + thisDuration.minutes;
	int otherTotalMinutes = otherDuration.hours * 60 + otherDuration.minutes;

	return thisTotalMinutes < otherTotalMinutes;
}