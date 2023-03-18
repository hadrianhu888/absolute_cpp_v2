/**
 * @file dayofweek.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <cstdarg>
#include <cfloat>
#include <climits>
#include <cctype>
#include <clocale>
#include <cerrno>
#include <csetjmp>
#include <csignal>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cwchar>
#include <cwctype>
#include <ctime>
#include <ciso646>
#include <cstddef>
#include "dayofweek.hpp"

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int getCenturyValue(int year)
{
    int lastTwoDigits = year % 100;
    int firstTwoDigits = year / 100;
    int firstTwoDigitsDividedBy4 = firstTwoDigits / 4;
    int firstTwoDigitsDividedBy4Times5 = firstTwoDigitsDividedBy4 * 5;
    int lastTwoDigitsPlusFirstTwoDigitsDividedBy4Times5 = lastTwoDigits + firstTwoDigitsDividedBy4Times5;
    int lastTwoDigitsPlusFirstTwoDigitsDividedBy4Times5Mod7 = lastTwoDigitsPlusFirstTwoDigitsDividedBy4Times5 % 7;
    return lastTwoDigitsPlusFirstTwoDigitsDividedBy4Times5Mod7;
}

int getMonthValue(int year, int month)
{
    if (month == 1 || month == 2)
    {
        month += 12;
        year -= 1;
    }    
    int monthTimes13 = month * 13;
    int monthTimes13DividedBy5 = monthTimes13 / 5;
    int monthTimes13DividedBy5PlusMonth = monthTimes13DividedBy5 + month;
    return monthTimes13DividedBy5PlusMonth;
}

int getMonthValue(int year, char *month)
    /**
     * @brief Also get the months based on both full month name and abbreviated month name
     * 
     */
{
    if (strcmp(month, "January") == 0 || strcmp(month, "Jan") == 0)
    {
        return 1;
    }
    else if (strcmp(month, "February") == 0 || strcmp(month, "Feb") == 0)
    {
        return 4;
    }
    else if (strcmp(month, "March") == 0 || strcmp(month, "Mar") == 0)
    {
        return 4;
    }
    else if (strcmp(month, "April") == 0 || strcmp(month, "Apr") == 0)
    {
        return 0;
    }
    else if (strcmp(month, "May") == 0 || strcmp(month, "May") == 0)
    {
        return 2;
    }
    else if (strcmp(month, "June") == 0 || strcmp(month, "Jun") == 0)
    {
        return 5;
    }
    else if (strcmp(month, "July") == 0 || strcmp(month, "Jul") == 0)
    {
        return 0;
    }
    else if (strcmp(month, "August") == 0 || strcmp(month, "Aug") == 0)
    {
        return 3;
    }
    else if (strcmp(month, "September") == 0 || strcmp(month, "Sep") == 0)
    {
        return 6;
    }
    else if (strcmp(month, "October") == 0 || strcmp(month, "Oct") == 0)
    {
        return 1;
    }
    else if (strcmp(month, "November") == 0 || strcmp(month, "Nov") == 0)
    {
        return 4;
    }
    else if (strcmp(month, "December") == 0 || strcmp(month, "Dec") == 0)
    {
        return 6;
    }
    else
    {
        return -1;
    }
}

int getDayOfWeek(int day, int month, int year)
{
    int q = day + getMonthValue(month, year) + getCenturyValue(year);
    if (isLeapYear(year) && (month == 1 || month == 2))
    {
        q -= 1;
    }
    q += year / 4;
    q -= year / 100;
    q += year / 400;
    q = q % 7;
    if (q < 0)
    {
        q += 7;
    }
    return q;
}

using namespace std;

int main (int argc, char *argv[])
{
    int day, month, year;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    cout << "Day of week: " << getDayOfWeek(day, month, year) << endl;
    return 0;
}
