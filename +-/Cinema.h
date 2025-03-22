#pragma once

#include <string>

// Робота виконана Анастасією Гуль !!!!!

const int MAX_SESSIONS = 100;

struct Session 
{
    std::string movie;
    std::string day;
    int startHour;
    int startMinute;
    int duration;
};

class Cinema 
{
public:
    Cinema(const std::string& filename);
    void addSession(const std::string& movie, const std::string& day, int startHour, int startMinute, int duration);
    void loadSessionsFromFile();
    Session getLatestSession(const std::string& day) const;
    void printSessions() const;

private:
    std::string filename;
    Session schedule[MAX_SESSIONS];
    int sessionCount;
};

