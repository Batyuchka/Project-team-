#pragma once
#include <string>
#include "Seance.h"
#include "Film.h"
#include <list>
using namespace std;

// This was written by Anastasia Hul

class Cinema 
{
public:
    Cinema();
    void addSeance(const Seance& S);
    void ReadFromFile(string fileName);
    Seance getLastSeance (Days day);
    void Print();

private:

    list< Seance> schedule; 
   
};

