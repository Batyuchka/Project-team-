#include "pch.h"
#include"../+-/Film.h"
#include"../+-/Seance.h"
#include"../+-/CinemabyHULN.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
//Тест класу Film
TEST(FilmTest, DurationConversion) {
    Film film("Test Movie", "USA", 125);
    EXPECT_EQ(film.getDurationInHours(), "2 5");
}

TEST(FilmTest, DurationReduction) {
    Film film("Test Movie", "USA", 100);
    Film shorter = film - 20;
    EXPECT_EQ(shorter.getDuration(), 80);
}

//Тест класу Seance
TEST(SeanceTest, EndTimeCalculation) {
    Seance seance("Test Movie", "USA", 125, "Monday", "14:30");
    EXPECT_EQ(seance.getEndTime(), "16:35");
}

TEST(SeanceTest, MoveToNextDay) {
    Seance seance("Test Movie", "USA", 125, "Monday", "14:30");
    seance.moveToNextDay();
    EXPECT_EQ(seance.getEndTime(), "16:35");
}

//Тест класу Cinema
TEST(CinemaTest, AddSession) {
    Cinema cinema("test.txt");
    cinema.addSession("Test Movie", "Monday", 14, 30, 125);
    Session latest = cinema.getLatestSession("Monday");
    EXPECT_EQ(latest.movie, "Test Movie");
    EXPECT_EQ(latest.startHour, 14);
    EXPECT_EQ(latest.startMinute, 30);
    EXPECT_EQ(latest.duration, 125);
}