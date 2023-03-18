/**
 * @file 24_2_12_time_convert.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream> // for cin and cout
#include <cstdlib> // for atoi
#include <cmath> // for pow
#include <cassert> // for assert
#include "24_to_12_time_convert.hpp" // for 24_to_12_time_convert.hpp

using namespace std;

char recognize_am_pm(int hour)
{
    char am_pm = ' ';
    if (hour >= 0 && hour <= 11)
    {
        am_pm = 'A';
    }
    else if (hour >= 12 && hour <= 23)
    {
        am_pm = 'P';
    }
    return am_pm;
}
void convert_24_to_12(int hour, int minute, int second, char am_pm)
{
    if (hour >= 0 && hour <= 11)
    {
        cout << "The time in 12-hour format is: " << hour << ":" << minute << ":" << second << " " << am_pm << "M" << endl;
    }
    else if (hour >= 12 && hour <= 23)
    {
        cout << "The time in 12-hour format is: " << hour - 12 << ":" << minute << ":" << second << " " << am_pm << "M" << endl;
    }
}

int main(int argc, char** argv) {
    int hour = 0;
    int minute = 0;
    int second = 0;
    char am_pm = ' ';
    cout << "Enter a 24-hour time (hh:mm:ss): ";
    cin >> hour >> minute >> second;
    am_pm = recognize_am_pm(hour);
    convert_24_to_12(hour, minute, second, am_pm);
    return 0;
}
