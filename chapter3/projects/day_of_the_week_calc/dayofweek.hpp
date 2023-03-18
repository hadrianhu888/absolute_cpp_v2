/**
 * @file dayofweek.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef dayofweek_h
#define dayofweek_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstddef>
#include <cassert>

using namespace std;

//  *  The following is a C++ implementation of the algorithm described
//  *  in the Wikipedia article on the calculation of the day of the week
//  *  for any date in the Gregorian calendar.
//  *
//  *  The algorithm is attributed to Carl Friedrich Gauss, and is
//  *  described in his work Disquisitiones Arithmeticae, published in
//  *  1801.
//  *
//  *  The algorithm is as follows:
//  *
//  *  1.  If the month is January or February, subtract 1 from the year
//  *      and add 12 to the month.
//  *
//  *  2.  Let K be the year of the century (i.e., year modulo 100).
//  *
//  *  3.  Let J be the zero-based century (i.e., year divided by 100).
//  *
//  *  4.  Let h be the day of the month (1 to 31).
//  *
//  *  5.  Let m be the month (3 to 14).
//  *
//  *  6.  Let q be the day of the week (0 to 6).
//  *
//  *  7.  Compute q = (h + floor( 13 * (m + 1) / 5 ) + K + floor( K / 4 ) +
//  *      floor( J / 4 ) - 2 * J) modulo 7.
//  *
//  *  8.  If q is negative, add 7 to it.
//  *
//  *  9.  The day of the week is q.

#define DATE 1
#define TIME 2
#define DATE_TIME 3

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

#define JANUARY_STRING "January"
#define FEBRUARY_STRING "February"
#define MARCH_STRING "March"
#define APRIL_STRING "April"
#define MAY_STRING "May"
#define JUNE_STRING "June"
#define JULY_STRING "July"
#define AUGUST_STRING "August"
#define SEPTEMBER_STRING "September"
#define OCTOBER_STRING "October"
#define NOVEMBER_STRING "November"
#define DECEMBER_STRING "December"

#define SUNDAY_STRING "Sunday"
#define MONDAY_STRING "Monday"
#define TUESDAY_STRING "Tuesday"
#define WEDNESDAY_STRING "Wednesday"
#define THURSDAY_STRING "Thursday"
#define FRIDAY_STRING "Friday"
#define SATURDAY_STRING "Saturday"

#define JANUARY_ABBREVIATION "Jan"
#define FEBRUARY_ABBREVIATION "Feb"
#define MARCH_ABBREVIATION "Mar"
#define APRIL_ABBREVIATION "Apr"
#define MAY_ABBREVIATION "May"
#define JUNE_ABBREVIATION "Jun"
#define JULY_ABBREVIATION "Jul"
#define AUGUST_ABBREVIATION "Aug"
#define SEPTEMBER_ABBREVIATION "Sep"
#define OCTOBER_ABBREVIATION "Oct"
#define NOVEMBER_ABBREVIATION "Nov"
#define DECEMBER_ABBREVIATION "Dec"

#define SUNDAY_ABBREVIATION "Sun"
#define MONDAY_ABBREVIATION "Mon"
#define TUESDAY_ABBREVIATION "Tue"
#define WEDNESDAY_ABBREVIATION "Wed"
#define THURSDAY_ABBREVIATION "Thu"
#define FRIDAY_ABBREVIATION "Fri"
#define SATURDAY_ABBREVIATION "Sat"

typedef struct months {
    int month;
    string month_string;
    string month_abbreviation;
} months;

typedef struct weeks {
    int week;
    string week_string;
    string week_abbreviation;
} weeks;

typedef struct date {
    int day;
    int month;
    int year;
} date;

typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;

typedef struct date_time {
    date date;
    Time time;
} date_time;

typedef struct day_of_week {
    int day_of_week;
    string day_of_week_string;
    string day_of_week_abbreviation;
} day_of_week;

typedef struct date_time_day_of_week {
    date_time date_time;
    day_of_week day_of_week;
} date_time_day_of_week;

typedef struct date_time_day_of_week_format {
    date_time_day_of_week date_time_day_of_week;
    int format;
} date_time_day_of_week_format;

bool isLeapYear(int year);
int getCentury(int year);
int getYear(int year);
int getMonthValue(int year, int month);
int getMonthValue(int year, char *month);
int getDayOfWeek(int century, int year, int month);
int main(int argc, char *argv[]);

#endif // DATE_TIME_H