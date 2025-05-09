#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Duration
{
	int hours;
	int minutes;

	Duration(int h = 0, int m = 0) : hours(h), minutes(m) {}
};

class Film
{
protected:
	string f_title;
	string f_country;
	int f_duration;
public:
	Film();
	Film(string title, string country, int duration);
	Film(const Film& F);
	virtual ~Film();

	Duration getDurationAsNumber() const;
	Film operator-(int minutes);
	virtual void print() const;

	string getTitle() const;
	string getCountry() const;
	int getDuration() const;
};
