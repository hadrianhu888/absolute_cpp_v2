/**
 * @file time_machine.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>

using namespace std;
using namespace std::chrono;

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

/**
 * @brief a time machine that can travel forward or backward in time by 24 hours. 
* Get current time and move forward or backward 24 hours and display the new time.
 *
 * 
 */

int second; 
int minute;
int hour;
int day;
int month;
int year;

void get_current_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second);
void get_future_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second);
void get_past_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second);
void display_current_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second);
void display_future_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second);
void display_past_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second);
int main(int argc, char **argv); 

void get_current_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    day = ltm->tm_mday;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}

void get_future_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    day = ltm->tm_mday + 1;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}

void get_past_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    day = ltm->tm_mday - 1;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}

void display_current_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    cout << "Current day time is: " << day << "/" << month << "/" << year << " " << hour << ":" << minute << ":" << second << endl;
}

void display_future_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    cout << "Future day time is: " << day << "/" << month << "/" << year << " " << hour << ":" << minute << ":" << second << endl;
}

void display_past_day_time(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    cout << "Past day time is: " << day << "/" << month << "/" << year << " " << hour << ":" << minute << ":" << second << endl;
}

int main(int argc, char **argv)
{
    int choice;
    cout << "1. Current day time" << endl;
    cout << "2. Future day time" << endl;
    cout << "3. Past day time" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        get_current_day_time(day, month, year, hour, minute, second);
        display_current_day_time(day, month, year, hour, minute, second);
        break;
    case 2:
        get_future_day_time(day, month, year, hour, minute, second);
        display_future_day_time(day, month, year, hour, minute, second);
        break;
    case 3:
        get_past_day_time(day, month, year, hour, minute, second);
        display_past_day_time(day, month, year, hour, minute, second);
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    return 0;
}

// Path: chapter4\projects\time_machine.cpp

