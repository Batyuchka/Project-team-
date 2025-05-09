#pragma once
#include "Film.h"

enum Days
{
	Monday, Tuesday, Wednesday, Thursday, Fridey, Saturday, Sunday
};

string to_string(Days day) ;

class Seance : public Film
{
private:
	Days day;
	Duration start_seance;
	 

public:
	Seance(string t, string c, int d, Days da, Duration st);
	Days getDay() const;
	Duration getStartSeance() const;
	Duration getEndTime() const; 
	void moveToNextDay();
	void print() const override;
	bool operator<(const Seance& S) const;

};

