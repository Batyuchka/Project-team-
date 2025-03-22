#include"../+-/Film.h"
#include "../+-/CinemabyHULN.h"
#include"../+-/Seance.h"
#include <iostream>

int main()
{

    //This was written by Anastasia Hul
    Cinema cinema("TextbyHULN.txt");

    cinema.loadSessionsFromFile();
    cinema.addSession("Interstellar", "Monday", 19, 30, 169);
    cinema.addSession("Inception", "Monday", 21, 00, 148);
    cinema.addSession("Avatar", "Tuesday", 18, 00, 162);

    std::cout << "Session schebule:\n";
    cinema.printSessions();

    std::string searchDay = "Monday";
    Session latest = cinema.getLatestSession(searchDay);
    if (!latest.movie.empty()) {
        std::cout << "\nLater session in " << searchDay << ": "
            << latest.movie << " in " << latest.startHour << ":"
            << (latest.startMinute < 10 ? "0" : "") << latest.startMinute << std::endl;
    }
    else {
        std::cout << "\nNo seassion on this day.\n";
    }


    Seance s1("Interstellar", "USA", 169, "Monday", "19:30");
    Seance s2("Inception", "USA", 148, "Monday", "21:00");
    Seance s3("Mavka. The Forest Song", "Ukraine", 99, "Wednesday", "17:45");


    cout << "Initial sessions:\n";
    s1.printOn();
    s2.printOn();
    s3.printOn();


    cout << "\nReducing 'Interstellar' duration by 20 minutes:\n";
    Film shorterFilm = s1 - 20;


    s1 = Seance(shorterFilm.getTitle(), shorterFilm.getCountry(), shorterFilm.getDuration(), s1.getDay(), s1.getStartSeance());
    s1.printOn();

    cout << "\nComparing sessions:\n";
    if (s1 < s2) {
        cout << "'Interstellar' ends earlier than 'Inception'\n";
    }
    else {
        cout << "'Inception' ends earlier than 'Interstellar'\n";
    }

	return 0;
}