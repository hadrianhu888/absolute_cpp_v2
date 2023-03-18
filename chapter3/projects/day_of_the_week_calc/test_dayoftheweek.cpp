#include "dayofweek.hpp"
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

using namespace std;

bool test_isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int test_getCentury(int year) {
    return year / 100;
}

int test_getYear(int year) {
    return year % 100;
}

int test_getMonth(int month) {
    if (month == 1 || month == 2) {
        return month + 12;
    } else {
        return month;
    }
}

int test_getDay(int day) {
    return day;
}

int test_getDayOfWeek(int year, int month, int day) {
    int century = test_getCentury(year);
    int yearInCentury = test_getYear(year);
    int monthInYear = test_getMonth(month);
    int dayInMonth = test_getDay(day);
    int dayOfWeek = (dayInMonth + (int) (13 * (monthInYear + 1) / 5) + yearInCentury + (int) (yearInCentury / 4) + (int) (century / 4) - 2 * century) % 7;
    if (dayOfWeek < 0) {
        dayOfWeek += 7;
    }
    return dayOfWeek;
}

int main (int argc, char **argv) {
    int year = 2023;
    int month = rand() % 12 + 1;
    int day = rand() % 31 + 1;
    int dayOfWeek = test_getDayOfWeek(year, month, day);
    cout << "Day of week: " << dayOfWeek << endl;
    return 0;
}

/**
 * @brief 
 * 
 */