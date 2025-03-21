#pragma once
#include <iostream>
#include<string>
using namespace std;

class Film
{
protected:
	string title;
	string country;
	double duration;
public:
	Film();
	Film(const Film& F);
	virtual ~Film();
    Film operator-(int minutes) const ;
	virtual void print() const;




};

