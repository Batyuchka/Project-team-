#pragma once
#include "Film.h"

enum Days
{
	Monday, //.... � ���, �� �������� � ���� �����
};

class Seance : public Film
{
private:
	Days day;
	string start_seance;
	 

public:
	Seance(string t, string c, double d, string da, string st); // ���� ������������
	string getDay() const;
	string getStartSeance() const;
	string getEndTime();
	void moveToNextDay();
	void printOn() const;

	bool operator<(const Seance& S) const;

};

