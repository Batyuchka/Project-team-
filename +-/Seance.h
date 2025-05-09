#pragma once
#include "Film.h"
#include <string>
#include <iostream>

enum Days
{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

class Seance : public Film
{
private:
    Days day;          
    string start_seance; 
public:
 
    Seance(string title, string country, int duration, Days da, string st);

 
    string getDay() const;
    string getStartSeance() const;
    string getEndTime() const;
    void moveToNextDay();
    void printOn() const;

    bool operator<(const Seance& S) const; // Порівняння часу закінчення
};
