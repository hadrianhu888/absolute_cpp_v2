/**
 * @file dtime.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <ctime>
#include "dtime.h"

using namespace std;

int dtime_main();

DTime::DTime()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

DTime::DTime(int h, int m, int s)
{
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
    this->normalize();
}

void DTime::setHours(int h)
{
    this->hours = h;
    this->normalize();
}

void DTime::setMinutes(int m)
{
    this->minutes = m;
    this->normalize();
}

void DTime::setSeconds(int s)
{
    this->seconds = s;
    this->normalize();
}

int DTime::getHours() const
{
    return this->hours;
}

int DTime::getMinutes() const
{
    return this->minutes;
}

int DTime::getSeconds() const
{
    return this->seconds;
}

void DTime::print() const
{
    cout << this->hours << ":" << this->minutes << ":" << this->seconds << endl;
}

void DTime::printUniversal() const
{
    cout << this->hours << ":" << this->minutes << ":" << this->seconds << endl;
}

void DTime::normalize()
{
    if (this->seconds >= 60)
    {
        this->minutes += this->seconds / 60;
        this->seconds = this->seconds % 60;
    }
    if (this->minutes >= 60)
    {
        this->hours += this->minutes / 60;
        this->minutes = this->minutes % 60;
    }
    if (this->hours >= 24)
    {
        this->hours = this->hours % 24;
    }
}

DTime DTime::operator+(const DTime &rhs) const
{
    DTime temp;
    temp.hours = this->hours + rhs.hours;
    temp.minutes = this->minutes + rhs.minutes;
    temp.seconds = this->seconds + rhs.seconds;
    temp.normalize();
    return temp;
}

DTime DTime::operator-(const DTime &rhs) const
{
    DTime temp;
    temp.hours = this->hours - rhs.hours;
    temp.minutes = this->minutes - rhs.minutes;
    temp.seconds = this->seconds - rhs.seconds;
    temp.normalize();
    return temp;
}

DTime DTime::operator*(const DTime &rhs) const
{
    DTime temp;
    temp.hours = this->hours * rhs.hours;
    temp.minutes = this->minutes * rhs.minutes;
    temp.seconds = this->seconds * rhs.seconds;
    temp.normalize();
    return temp;
}

DTime DTime::operator/(const DTime &rhs) const
{
    DTime temp;
    temp.hours = this->hours / rhs.hours;
    temp.minutes = this->minutes / rhs.minutes;
    temp.seconds = this->seconds / rhs.seconds;
    temp.normalize();
    return temp;
}

DTime DTime::operator%(const DTime &rhs) const
{
    DTime temp;
    temp.hours = this->hours % rhs.hours;
    temp.minutes = this->minutes % rhs.minutes;
    temp.seconds = this->seconds % rhs.seconds;
    temp.normalize();
    return temp;
}

DTime DTime::operator++()
{
    this->seconds++;
    this->normalize();
    return *this;
}

DTime DTime::operator++(int)
{
    DTime temp = *this;
    this->seconds++;
    this->normalize();
    return temp;
}

DTime DTime::operator--()
{
    this->seconds--;
    this->normalize();
    return *this;
}

DTime DTime::operator--(int)
{
    DTime temp = *this;
    this->seconds--;
    this->normalize();
    return temp;
}

bool DTime::operator==(const DTime &rhs) const
{
    return this->hours == rhs.hours && this->minutes == rhs.minutes && this->seconds == rhs.seconds;
}

bool DTime::operator!=(const DTime &rhs) const
{
    return this->hours != rhs.hours || this->minutes != rhs.minutes || this->seconds != rhs.seconds;
}

bool DTime::operator<(const DTime &rhs) const
{
    if (this->hours < rhs.hours)
    {
        return true;
    }
    else if (this->hours == rhs.hours)
    {
        if (this->minutes < rhs.minutes)
        {
            return true;
        }
        else if (this->minutes == rhs.minutes)
        {
            if (this->seconds < rhs.seconds)
            {
                return true;
            }
        }
    }
    return false;
}

bool DTime::operator>(const DTime &rhs) const
{
    if (this->hours > rhs.hours)
    {
        return true;
    }
    else if (this->hours == rhs.hours)
    {
        if (this->minutes > rhs.minutes)
        {
            return true;
        }
        else if (this->minutes == rhs.minutes)
        {
            if (this->seconds > rhs.seconds)
            {
                return true;
            }
        }
    }
    return false;
}

bool DTime::operator<=(const DTime &rhs) const
{
    if (this->hours < rhs.hours)
    {
        return true;
    }
    else if (this->hours == rhs.hours)
    {
        if (this->minutes < rhs.minutes)
        {
            return true;
        }
        else if (this->minutes == rhs.minutes)
        {
            if (this->seconds <= rhs.seconds)
            {
                return true;
            }
        }
    }
    return false;
}

bool DTime::operator>=(const DTime &rhs) const
{
    if (this->hours > rhs.hours)
    {
        return true;
    }
    else if (this->hours == rhs.hours)
    {
        if (this->minutes > rhs.minutes)
        {
            return true;
        }
        else if (this->minutes == rhs.minutes)
        {
            if (this->seconds >= rhs.seconds)
            {
                return true;
            }
        }
    }
    return false;
}

//friend operators

ostream& operator<<(ostream &out, const DTime &rhs)
{
    out << rhs.hours << ":" << rhs.minutes << ":" << rhs.seconds;
    return out;
}

istream& operator>>(istream &in, DTime &rhs)
{
    in >> rhs.hours >> rhs.minutes >> rhs.seconds;
    rhs.normalize();
    return in;
}

void DTime :: advance(int seconds)
{
    this->seconds += seconds;
    this->normalize();
}

void DTime :: advance(int minutes, int seconds)
{
    this->minutes += minutes;
    this->seconds += seconds;
    this->normalize();
}

void DTime :: advance(int hours, int minutes, int seconds)
{
    this->hours += hours;
    this->minutes += minutes;
    this->seconds += seconds;
    this->normalize();
}

int dtime_main()
{
    DTime t1(1, 2, 3);
    DTime t2(4, 5, 6);
    DTime t3 = t1 + t2;
    DTime t4 = t1 - t2;
    DTime t5 = t1 * t2;
    DTime t6 = t1 / t2;
    DTime t7 = t1 % t2;
    DTime t8 = ++t1;
    DTime t9 = t1++;
    DTime t10 = --t1;
    DTime t11 = t1--;
    bool b1 = t1 == t2;
    bool b2 = t1 != t2;
    bool b3 = t1 < t2;
    bool b4 = t1 > t2;
    bool b5 = t1 <= t2;
    bool b6 = t1 >= t2;
    cout << t1 << endl;
    cout << t2 << endl;
    cout << t3 << endl;
    cout << t4 << endl;
    cout << t5 << endl;
    cout << t6 << endl;
    cout << t7 << endl;
    cout << t8 << endl;
    cout << t9 << endl;
    cout << t10 << endl;
    cout << t11 << endl;
    cout << b1 << endl;
    cout << b2 << endl;
    cout << b3 << endl;
    cout << b4 << endl;
    cout << b5 << endl;
    cout << b6 << endl;
    t1.advance(1);
    cout << t1 << endl;
    t1.advance(1,1);
    cout << t1 << endl;
    t1.advance(1,1,1);
    cout << t1 << endl;
    return 0;
}
