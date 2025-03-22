#pragma once
#include "Film.h"


class Seance : public Film
{
private:
	string day;
	string start_seance;
	 

public:
	Seance(string t, string c, double d, string da, string st);
	string getEndTime();
	void moveToNextDay();
	void printOn() const;

	bool operator<(const Seance& S) const;

};

