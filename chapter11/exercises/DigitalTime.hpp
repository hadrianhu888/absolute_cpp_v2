/**
 * @file DigitalTime.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DIGITALTIME_HPP
#define DIGITALTIME_HPP

#include <iostream>
#include <string>
using namespace std;

namespace DigitalTime
{
    class DigitalTime
    {
    private:
        int hour;
        int minute;
        int second;
    public:
        DigitalTime();
        DigitalTime(int theHour, int theMinute);
        DigitalTime(int theHour, int theMinute, int theSecond);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        int readHour();
        int readMinute();
        int readSecond();
        void readTheHour(int theHour);
        void readTheMinute(int theMinute);
        void readTheSecond(int theSecond);
        void advance(int minutesAdded);
        void advance(int hoursAdded, int minutesAdded);
        void advance(int hoursAdded, int minutesAdded, int secondsAdded);
        friend istream& operator >>(istream& ins, DigitalTime& theObject);
        friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);
        void getCurrentTime();
    };
}

#endif // DIGITALTIME_HPP
