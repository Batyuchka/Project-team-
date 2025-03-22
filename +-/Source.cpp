#include"../+-/Film.h"
#include "../+-/Cinema.h"
#include"../+-/Seance.h"
#include <iostream>

int main()
{

    // Робота виконана Анастасією Гуль !!!!!
    Cinema cinema("Text.txt");

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



	return 0;
}