#include "CinemabyHULN.h"
#include <iostream>
#include <fstream>


//This was written by Anastasia Hul
using namespace std;

Days Fromstring(string S)
{ 
    string Dayss[] = { "Monday","Tuesday","Wednesday", "Thursday","Friday","Saturday","Sunday" };
    for (int i = 0; i < 7; ++i)
    {
        if (S == Dayss[i])
        {
            return static_cast <Days> (i);
        }
    }
    return Days::Fridey;
}

void Cinema::ReadFromFile(string fileName)
{
    ifstream file(fileName);
    if (!file) {
        cerr << "Error opening folder : " << fileName << endl;
        return;
    }

   string film, country, day;
    int startHour, startMinute, duration;
    while (file >> film >> country >> duration >> day >> startHour >> startMinute)
    {
        Seance S(film, country, duration, Fromstring(day), Duration(startHour, startMinute));
        addSeance(S);
    }
}

Cinema::Cinema()
{}

void Cinema::addSeance(const Seance& S)
{
    schedule.push_back(S);
}

Seance Cinema::getLastSeance(Days day)
{
    list<Seance> Film_day;
    for (const Seance& S : schedule)
    {
        if (S.getDay() == day)
        {
            Film_day.push_back(S);
        }
    }
    if (Film_day.empty())
    {
        throw "No Seance per specified day ";
    }
    Film_day.sort();
    return Film_day.back();
}

void Cinema::Print()
{
    for (const Seance& S : schedule)
    {
        S.print();
    }
}
