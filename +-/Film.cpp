#include "Film.h"

Film::Film() : f_title(" "), f_country(" "), f_duration(0)
{
}

Film::Film(string title, string country, int duration)
    : f_title(title), f_country(country), f_duration(duration)
{
    if (duration < 0) f_duration = 0;
}

Film::Film(const Film& F)
    : f_title(F.f_title), f_country(F.f_country), f_duration(F.f_duration)
{
}

Film::~Film()
{
}

Duration Film::getDurationAsNumber() const
{
    int hours = f_duration / 60;
    int minutes = f_duration % 60;
    return Duration(hours, minutes);
}

Film Film::operator-(int minutes)
{
    int newDuration = f_duration - minutes;
    if (newDuration < 0)
        newDuration = 0;
    return Film(f_title, f_country, newDuration);
}

void Film::print() const
{
    cout << '\n' << f_title << " | " << f_country << " | " << f_duration << " min";
}

string Film::getTitle() const
{
    return f_title;
}

string Film::getCountry() const
{
    return f_country;
}

int Film::getDuration() const
{
    return f_duration;
}
