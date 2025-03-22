#include "CinemabyHULN.h"
#include <iostream>
#include <fstream>

// Робота виконана Анастасією Гуль !!!!!

Cinema::Cinema(const std::string& filename) : filename(filename), sessionCount(0) {}

void Cinema::addSession(const std::string& movie, const std::string& day, int startHour, int startMinute, int duration) {
    if (sessionCount < MAX_SESSIONS) {
        schedule[sessionCount++] = { movie, day, startHour, startMinute, duration };
    }
    else {
        std::cerr << "Maximum session reached!\n";
    }
}

void Cinema::loadSessionsFromFile() {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening folder : " << filename << std::endl;
        return;
    }

    std::string movie, day;
    int startHour, startMinute, duration;
    while (file >> movie >> day >> startHour >> startMinute >> duration) {
        addSession(movie, day, startHour, startMinute, duration);
    }
}

Session Cinema::getLatestSession(const std::string& day) const {
    Session latest = { "", "", 0, 0, 0 };
    int latestEndTime = -1;

    for (int i = 0; i < sessionCount; i++) {
        if (schedule[i].day == day) {
            int endTime = schedule[i].startHour * 60 + schedule[i].startMinute + schedule[i].duration;
            if (endTime > latestEndTime) {
                latest = schedule[i];
                latestEndTime = endTime;
            }
        }
    }

    return latest;
}

void Cinema::printSessions() const {
    for (int i = 0; i < sessionCount; i++) {
        std::cout << schedule[i].movie << " | " << schedule[i].day << " | "
            << schedule[i].startHour << ":" << (schedule[i].startMinute < 10 ? "0" : "") << schedule[i].startMinute
            << " | " << schedule[i].duration << " minute.\n";
    }
}