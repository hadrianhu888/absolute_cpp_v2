/**
 * @file intpair.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv); 

class IntPair
{
    private: 
        int first;
        int second;
    public: 
        IntPair();
        IntPair(int first, int second);
        ~IntPair();
        int get_first();
        int get_second();
        void set_first(int first);
        void set_second(int second);
        void input();
        void output();
        void print();
        friend IntPair operator+(IntPair i1, IntPair i2);
        friend IntPair operator-(IntPair i1, IntPair i2);
        friend bool operator==(IntPair i1, IntPair i2);
        friend bool operator!=(IntPair i1, IntPair i2);
        friend bool operator<(IntPair i1, IntPair i2);
        friend bool operator<=(IntPair i1, IntPair i2);
        friend bool operator>(IntPair i1, IntPair i2);
        friend bool operator>=(IntPair i1, IntPair i2);
        friend ostream& operator<<(ostream& out, IntPair i);
        friend istream& operator>>(istream& in, IntPair& i);
        friend IntPair operator+=(IntPair& i1, IntPair i2);
        friend IntPair operator-=(IntPair& i1, IntPair i2);
        friend IntPair operator++(IntPair& i);
        friend IntPair operator++(IntPair& i, int);
        friend IntPair operator--(IntPair& i);
        friend IntPair operator--(IntPair& i, int);
        IntPair operator=(const IntPair& i);
};

IntPair::IntPair()
{
    first = 0;
    second = 0;
}

IntPair::IntPair(int first, int second)
{
    this->first = first;
    this->second = second;
}

IntPair::~IntPair()
{
}

int IntPair::get_first()
{
    return first;
}

int IntPair::get_second()
{
    return second;
}

void IntPair::set_first(int first)
{
    this->first = first;
}

void IntPair::set_second(int second)
{
    this->second = second;
}

void IntPair::input()
{
    cout << "Enter first integer: ";
    cin >> first;
    cout << "Enter second integer: ";
    cin >> second;
}

void IntPair::output()
{
    cout << "First integer: " << first << endl;
    cout << "Second integer: " << second << endl;
}

void IntPair::print()
{
    cout << "(" << first << ", " << second << ")" << endl;
}

IntPair operator+(IntPair i1, IntPair i2)
{
    IntPair temp;
    temp.first = i1.first + i2.first;
    temp.second = i1.second + i2.second;
    return temp;
}

IntPair operator-(IntPair i1, IntPair i2)
{
    IntPair temp;
    temp.first = i1.first - i2.first;
    temp.second = i1.second - i2.second;
    return temp;
}

bool operator==(IntPair i1, IntPair i2)
{
    return (i1.first == i2.first && i1.second == i2.second);
}

bool operator!=(IntPair i1, IntPair i2)
{
    return !(i1 == i2);
}

bool operator<(IntPair i1, IntPair i2)
{
    return (i1.first < i2.first && i1.second < i2.second);
}

bool operator<=(IntPair i1, IntPair i2)
{
    return (i1 < i2 || i1 == i2);
}

bool operator>(IntPair i1, IntPair i2)
{
    return !(i1 <= i2);
}

bool operator>=(IntPair i1, IntPair i2)
{
    return !(i1 < i2);
}

ostream& operator<<(ostream& out, IntPair i)
{
    out << "(" << i.first << ", " << i.second << ")" << endl;
    return out;
}

istream& operator>>(istream& in, IntPair& i)
{
    in >> i.first >> i.second;
    return in;
}

IntPair operator+=(IntPair& i1, IntPair i2)
{
    i1.first += i2.first;
    i1.second += i2.second;
    return i1;
}

IntPair operator-=(IntPair& i1, IntPair i2)
{
    i1.first -= i2.first;
    i1.second -= i2.second;
    return i1;
}

IntPair operator++(IntPair& i)
{
    i.first++;
    i.second++;
    return i;
}

IntPair operator++(IntPair& i, int)
{
    IntPair temp = i;
    i.first++;
    i.second++;
    return temp;
}

IntPair operator--(IntPair& i)
{
    i.first--;
    i.second--;
    return i;
}

IntPair operator--(IntPair& i, int)
{
    IntPair temp = i;
    i.first--;
    i.second--;
    return temp;
}

IntPair IntPair::operator=(const IntPair& i)
{
    first = i.first;
    second = i.second;
    return *this;
}

int main(int argc, char **argv)
{
    IntPair i1(1, 2);
    IntPair i2(3, 4);
    IntPair i3;
    i1++; 
    i1.print();
    i1--;
    i1.print();
    i1 += i2;
    i1.print();
    i1 -= i2;
    i1.print();
    i1 = i2;
    i1.print();
    i1 = i1;
    i1.print();
    i1 = i2 = i1;
    i1.print();
    i2.print();
    i1 = i2 = i1 = i2;
    i1.print();
    i2.print();
    i1 = i2 = i1 = i2 = i1;
    i1.print();
    i2.print();
    i3 = i1 + i2;
    i3.print();
    i3 = i1 - i2;
    i3.print();
    i3 = i1;
    i3.print();
    return 0;
}