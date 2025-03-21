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

	int hours = f_duration / 60;
	int minutes = f_duration % 60;
	string asString = to_string(hours) + ' ' + to_string(minutes);
	return asString;
}

Film Film::operator-(int minutes)
{
	return Film(f_title, f_country, f_duration - minutes);
}

void Film::print() const
{
	cout <<'\n' << f_title << ' ' << f_country << ' ' << f_duration;
}

string Film::getTitle()
{
	return f_title;
}

string Film::getCountry()
{
	return f_country;
}

int Film::getDuration()
{
	return f_duration;
}
