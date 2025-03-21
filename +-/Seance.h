#pragma once
#include "Film.h"


class Seance : public Film
{
private:
	string day;
	double start_seance;

public:
	Seance(string t, string c, double d, string da, double st);
	int getEndTime() const;
	void moveToNextDay();
	void printOn() const;

	bool operator<(const Seance& S) const;

};

