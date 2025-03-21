#pragma once
#include <iostream>
#include<string>
using namespace std;

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

	string getDurationInHours()const;
    Film operator-(int minutes);
	virtual void print() const;

	string getTitle();
	string getCountry();
	int getDuration();





};

