#include "Film.h"

Film::Film():f_title(" "), f_country(" "), f_duration(0.0)
{

}

Film::Film(string title, string country, int duration):f_title(title), f_country(country), f_duration(duration)
{
}

Film::Film(const Film& F):f_title(F.f_title), f_country(F.f_country), f_duration(F.f_duration)
{
}

Film::~Film()
{
}

string Film::getDurationInHours() const
{
	return string();
}

Film Film::operator-(int minutes) const
{
	return Film();
}

void Film::print() const
{
}

string Film::getTitle()
{
	return string();
}

string Film::getCountry()
{
	return string();
}

int Film::getDuration()
{
	return 0;
}
