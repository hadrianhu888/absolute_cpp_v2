/**
 * @file dtime.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DTIME_H
#define DTIME_H

#include <iostream>

using namespace std;

class DTime
{
private:
    int hours;
    int minutes;
    int seconds;
    void normalize();
public:
    DTime();
    DTime(int h, int m, int s);
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void print() const;
    void printUniversal() const;
    void advance(int seconds);
    void advance(int seconds,int minutes);
    void advance(int seconds,int minutes,int hours);
    DTime operator+(const DTime &rhs) const;
    DTime operator-(const DTime &rhs) const;
    DTime operator*(const DTime &rhs) const;
    DTime operator/(const DTime &rhs) const;
    DTime operator%(const DTime &rhs) const;
    DTime operator++();
    DTime operator++(int);
    DTime operator--();
    DTime operator--(int);
    bool operator==(const DTime &rhs) const;
    bool operator!=(const DTime &rhs) const;
    bool operator<(const DTime &rhs) const;
    bool operator>(const DTime &rhs) const;
    bool operator<=(const DTime &rhs) const;
    bool operator>=(const DTime &rhs) const;
    friend ostream &operator<<(ostream &out, const DTime &rhs);
    friend istream &operator>>(istream &in, DTime &rhs);
};

#endif // DTIME_H
