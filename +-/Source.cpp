#include"../+-/Film.h"
#include "../+-/CinemabyHULN.h"
#include"../+-/Seance.h"
#include <iostream>

int main()
{
    
    //This was written by Anastasia Hul 
    Cinema cinema;
    cinema.ReadFromFile("TextbyHULN.txt");

    cinema.addSeance(Seance ("Interstellar","Ukraine", 169, Days::Monday, Duration(19,30)));
    cinema.addSeance(Seance ("Inception","Poland", 148, Days::Sunday, Duration(18,45)));
    cinema.addSeance(Seance ("Avatar","Ukraine", 162, Days::Monday,Duration(18,30)));

    std::cout << "Seance schebule:\n";
    cinema.Print();

    Days searchDay = Days::Monday;
    try
    {
        Seance latest = cinema.getLastSeance(searchDay);
        cout << "\nLater seance in " << to_string(searchDay) << ": ";
        latest.print();
    }
    catch (const char* e)
    {
        cout << e; 
    }

   
    Seance s1("Interstellar", "USA", 169, Days::Monday, Duration(19,30));
    Seance s2("Inception", "USA", 148, Days::Monday, Duration(20, 45));
    Seance s3("Mavka. The Forest Song", "Ukraine", 99, Days::Wednesday, Duration(18,20));


    cout << "Initial sessions:\n";
    s1.print();
    s2.print();
    s3.print();


    cout << "\nReducing 'Interstellar' duration by 20 minutes:\n";
    Film shorterFilm = s1 - 20;


    s1 = Seance(shorterFilm.getTitle(), shorterFilm.getCountry(), shorterFilm.getDuration(), s1.getDay(), s1.getStartSeance());
    s1.print();

    cout << "\nComparing sessions:\n";
    if (s1 < s2) {
        cout << "'Interstellar' ends earlier than 'Inception'\n";
    }
    else {
        cout << "'Inception' ends earlier than 'Interstellar'\n";
    }
    
	return 0;
}