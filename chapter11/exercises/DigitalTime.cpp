/**
 * @file DigitalTime.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "DigitalTime.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

namespace DigitalTime
{
    DigitalTime::DigitalTime()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    DigitalTime::DigitalTime(int theHour, int theMinute)
    {
        hour = theHour;
        minute = theMinute;
    }

    DigitalTime::DigitalTime(int theHour, int theMinute, int theSecond)
    {
        hour = theHour;
        minute = theMinute;
        second = theSecond;
    }

    int DigitalTime::getHour() const
    {
        return hour;
    }

    int DigitalTime::getMinute() const
    {
        return minute;
    }

    int DigitalTime::getSecond() const
    {
        return second;
    }

    int DigitalTime::readHour()
    {
        return hour;
    }

    int DigitalTime::readMinute()
    {
        return minute;
    }

    int DigitalTime::readSecond()
    {
        return second;
    }

    void DigitalTime::readTheHour(int theHour)
    {
        hour = theHour;
    }

    void DigitalTime::readTheMinute(int theMinute)
    {
        minute = theMinute;
    }

    void DigitalTime::readTheSecond(int theSecond)
    {
        second = theSecond;
    }

    void DigitalTime::advance(int minutesAdded)
    {
        int grossMinutes = minute + minutesAdded;
        minute = grossMinutes % 60;
        int hourAdjustment = grossMinutes / 60;
        hour = (hour + hourAdjustment) % 24;
    }

    void DigitalTime::advance(int hoursAdded, int minutesAdded)
    {
        hour = (hour + hoursAdded) % 24;
        advance(minutesAdded);
    }

    void DigitalTime::advance(int hoursAdded, int minutesAdded, int secondsAdded)
    {
        hour = (hour + hoursAdded) % 24;
        advance(minutesAdded);
        second = (second + secondsAdded) % 60;
    }

    istream& operator >>(istream& ins, DigitalTime& theObject)
    {
        char dummyChar;
        ins >> theObject.hour >> dummyChar >> theObject.minute;
        return ins;
    }

    ostream& operator <<(ostream& outs, const DigitalTime& theObject)
    {
        outs << setfill('0') << setw(2) << theObject.hour << ":"
            << setw(2) << theObject.minute;
        return outs;
    }

    void DigitalTime::getCurrentTime()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        second = ltm->tm_sec;
    }
}

int main(int argc, char **argv)
{
    /**test out every functionality*/
    DigitalTime::DigitalTime time1(10, 30, 45);
    DigitalTime::DigitalTime time2(10, 30);
    DigitalTime::DigitalTime time3;
    cout << "time1: " << time1 << endl;
    cout << "time2: " << time2 << endl;
    cout << "time3: " << time3 << endl;
    cout << "time1.getHour(): " << time1.getHour() << endl;
    cout << "time1.getMinute(): " << time1.getMinute() << endl;
    cout << "time1.getSecond(): " << time1.getSecond() << endl;
    cout << "time1.readHour(): " << time1.readHour() << endl;
    cout << "time1.readMinute(): " << time1.readMinute() << endl;
    cout << "time1.readSecond(): " << time1.readSecond() << endl;
    time1.readTheHour(11);
    time1.readTheMinute(31);
    time1.readTheSecond(46);
    cout << "time1: " << time1 << endl;
    time1.advance(1);
    cout << "time1.advance(1): " << time1 << endl;
    time1.advance(1, 1);
    cout << "time1.advance(1, 1): " << time1 << endl;
    time1.advance(1, 1, 1);
    cout << "time1.advance(1, 1, 1): " << time1 << endl;
    cout << "time1: " << time1 << endl;
    cout << "time2: " << time2 << endl;
    cout << "time3: " << time3 << endl;
    cout << "time1.getHour(): " << time1.getHour() << endl;
    cout << "time1.getMinute(): " << time1.getMinute() << endl;
    cout << "time1.getSecond(): " << time1.getSecond() << endl;
    cout << "time1.readHour(): " << time1.readHour() << endl;
    cout << "time1.readMinute(): " << time1.readMinute() << endl;
    cout << "time1.readSecond(): " << time1.readSecond() << endl;
    cout << "time1: " << time1 << endl;
    cout << "time2: " << time2 << endl;
    cout << "time3: " << time3 << endl;
    cout << "time1.getHour(): " << time1.getHour() << endl;
    cout << "time1.getMinute(): " << time1.getMinute() << endl;
    cout << "time1.getSecond(): " << time1.getSecond() << endl;
    cout << "time1.readHour(): " << time1.readHour() << endl;
    cout << "time1.readMinute(): " << time1.readMinute() << endl;
    cout << "time1.readSecond(): " << time1.readSecond() << endl;
    /**get current time*/
    time1.getCurrentTime();
    cout << "time1.getCurrentTime(): " << time1 << endl;
    return 0;
}
