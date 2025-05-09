#include "Seance.h"
#include <sstream>
#include <string>


Seance::Seance(string t, string c, int d, Days da, Duration st)
	: Film(t,c,d), day(da) , start_seance(st)
{}

Days Seance::getDay() const  
{
	return day;
}

Duration Seance::getStartSeance() const
{
	return start_seance;
}

Duration Seance::getEndTime() const
{
	int hours = start_seance.hours + getDurationAsNumber().hours;
	int minutes = start_seance.minutes + getDurationAsNumber().minutes;
	hours += minutes / 60;
	minutes %= 60;
	return Duration(hours , minutes);
}

void Seance::moveToNextDay()
{
	if (day == Days::Sunday)
	{
		day = Days::Monday;
	}
	else
	{
		day = static_cast <Days> ( static_cast< int> (day) + 1); 
	}
}

void Seance::printOn() const
{
	cout << "\"" << f_title << "\" (" << f_country << ") - " << f_duration
		<< " min, " << to_string(day) << ", Start: " << start_seance.hours <<  ": " << start_seance.minutes << "\n";
}

bool Seance::operator<(const Seance& S) const
{
	Duration thisEndTime = getEndTime(); 
	Duration otherEndTime = S.getEndTime();
	if (thisEndTime.hours == otherEndTime.hours)
	return thisEndTime.minutes < otherEndTime.minutes;
	return thisEndTime.hours < otherEndTime.hours;
}

string to_string(Days day)
{
	string res = "";

	switch (day)
	{
	case Monday: res = "Monday";
		break;
	case Tuesday: res = "Tuesday";
		break;
	case Wednesday: res = "Wednesday";
		break;
	case Thursday: res = "Thursday";
		break;
	case Fridey: res = "Fridey";
		break;
	case Saturday: res = "Saturday";
		break;
	case Sunday: res = "Sunday";
		break;
	default:
		break;
	}
	return res;
}
