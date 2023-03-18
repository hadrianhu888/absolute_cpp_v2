/**
 * @file charpair.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class CharPair
{
    private:
        char first;
        char second;
    public:
        CharPair();
        CharPair(char first, char second);
        CharPair(char sz, int index);
        CharPair(char **sz, int index);
        void set_first(char first);
        void set_second(char second);
        char get_first();
        char get_second();
        friend bool operator==(CharPair p1, CharPair p2);
        friend bool operator!=(CharPair p1, CharPair p2);
        friend bool operator<(CharPair p1, CharPair p2);
        friend bool operator<=(CharPair p1, CharPair p2);
        friend bool operator>(CharPair p1, CharPair p2);
        friend bool operator>=(CharPair p1, CharPair p2);
        friend ostream& operator<<(ostream& out, CharPair p);
        friend istream& operator>>(istream& in, CharPair& p);
        CharPair operator[](int index);
        CharPair operator+(int index);
        CharPair operator-(int index);
        CharPair operator++();
        CharPair operator++(int);   
        CharPair operator--();
        CharPair operator--(int);
};

CharPair::CharPair()
{
    first = 'a';
    second = 'a';
}

CharPair::CharPair(char first, char second)
{
    this->first = first;
    this->second = second;
}

CharPair::CharPair(char sz, int index)
{
    first = sz; 
    second = first; 
}

CharPair::CharPair(char **sz, int index)
{
    first = (*sz)[index];
    second = (*sz)[index + 1];
}

void CharPair::set_first(char first)
{
    this->first = first;
}

void CharPair::set_second(char second)
{
    this->second = second;
}

char CharPair::get_first()
{
    return first;
}

char CharPair::get_second()
{
    return second;
}

bool operator==(CharPair p1, CharPair p2)
{
    return (p1.first == p2.first && p1.second == p2.second);
}

bool operator!=(CharPair p1, CharPair p2)
{
    return !(p1 == p2);
}

bool operator<(CharPair p1, CharPair p2)
{
    return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
}

bool operator<=(CharPair p1, CharPair p2)
{
    return (p1 < p2 || p1 == p2);
}

bool operator>(CharPair p1, CharPair p2)
{
    return !(p1 <= p2);
}

bool operator>=(CharPair p1, CharPair p2)
{
    return !(p1 < p2);
}

ostream& operator<<(ostream& out, CharPair p)
{
    out << p.first << p.second;
    return out;
}

istream& operator>>(istream& in, CharPair& p)
{
    in >> p.first >> p.second;
    return in;
}

CharPair CharPair::operator[](int index)
{
    return CharPair(first + index, second + index);
}

CharPair CharPair::operator+(int index)
{
    return CharPair(first + index, second + index);
}

CharPair CharPair::operator-(int index)
{
    return CharPair(first - index, second - index);
}

CharPair CharPair::operator++()
{
    first++;
    second++;
    return *this;
}

CharPair CharPair::operator++(int)
{
    CharPair temp = *this;
    first++;
    second++;
    return temp;
}

CharPair CharPair::operator--()
{
    first--;
    second--;
    return *this;
}

CharPair CharPair::operator--(int)
{
    CharPair temp = *this;
    first--;
    second--;
    return temp;
}

int main(int argc, char **argv)
{
    CharPair p1('a', 'b');
    CharPair p2('a', 'b');
    CharPair p3('a', 'c');
    CharPair p4('b', 'a');
    CharPair p5('b', 'b');
    CharPair p6('b', 'c');
    CharPair p7('c', 'a');
    CharPair p8('c', 'b');
    CharPair p9('c', 'c');
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;
    cout << "p5 = " << p5 << endl;
    cout << "p6 = " << p6 << endl;
    cout << "p7 = " << p7 << endl;
    cout << "p8 = " << p8 << endl;
    cout << "p9 = " << p9 << endl;
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 == p3: " << (p1 == p3) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;
    cout << "p1 != p3: " << (p1 != p3) << endl;
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "p1 < p3: " << (p1 < p3) << endl;
    cout << "p1 <= p2: " << (p1 <= p2) << endl;
    cout << "p1 <= p3: " << (p1 <= p3) << endl;
    cout << "p1 > p2: " << (p1 > p2) << endl;
    cout << "p1 > p3: " << (p1 > p3) << endl;
    cout << "p1 >= p2: " << (p1 >= p2) << endl;
    cout << "p1 >= p3: " << (p1 >= p3) << endl;
    cout << "p1[0] = " << p1[0] << endl;
    return 0;
}

