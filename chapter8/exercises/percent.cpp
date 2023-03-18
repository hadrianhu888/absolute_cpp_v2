/**
 * @file percent.cpp
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

class Percent
{
    private: 
        int numerator;
        int denominator;
    public: 
        Percent();
        Percent(int numerator, int denominator);
        ~Percent();
        int get_numerator();
        int get_denominator();
        void set_numerator(int numerator);
        void set_denominator(int denominator);
        void input();
        void output();
        void print();
        friend Percent operator+(Percent p1, Percent p2);
        friend Percent operator-(Percent p1, Percent p2);
        friend bool operator==(Percent p1, Percent p2);
        friend bool operator!=(Percent p1, Percent p2);
        friend bool operator<(Percent p1, Percent p2);
        friend bool operator<=(Percent p1, Percent p2);
        friend bool operator>(Percent p1, Percent p2);
        friend bool operator>=(Percent p1, Percent p2);
        friend ostream& operator<<(ostream& out, Percent p);
        friend istream& operator>>(istream& in, Percent& p);
        friend Percent operator+=(Percent& p1, Percent p2);
        friend Percent operator-=(Percent& p1, Percent p2);
        friend Percent operator++(Percent& p);
        friend Percent operator++(Percent& p, int);
        friend Percent operator--(Percent& p);
        friend Percent operator--(Percent& p, int);
        const Percent operator-() const;
        const Percent operator+() const;
        const Percent operator=(const Percent& p) const;
        const Percent operator+=(const Percent& p) const;
        const Percent operator-=(const Percent& p) const;
        const Percent operator++() const; 
};

Percent::Percent()
{
    numerator = 0;
    denominator = 1;
}

Percent::Percent(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

Percent::~Percent()
{
    //destructor
}

int Percent::get_numerator()
{
    return numerator;
}

int Percent::get_denominator()
{
    return denominator;
}

void Percent::set_numerator(int numerator)
{
    this->numerator = numerator;
}

void Percent::set_denominator(int denominator)
{
    this->denominator = denominator;
}

void Percent::input()
{
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
}

void Percent::output()
{
    cout << numerator << "/" << denominator;
}

void Percent::print()
{
    cout << numerator << "/" << denominator << endl;
}

Percent operator+(Percent p1, Percent p2)
{
    Percent temp;
    temp.numerator = p1.numerator * p2.denominator + p2.numerator * p1.denominator;
    temp.denominator = p1.denominator * p2.denominator;
    return temp;
}

Percent operator-(Percent p1, Percent p2)
{
    Percent temp;
    temp.numerator = p1.numerator * p2.denominator - p2.numerator * p1.denominator;
    temp.denominator = p1.denominator * p2.denominator;
    return temp;
}

bool operator==(Percent p1, Percent p2)
{
    return (p1.numerator * p2.denominator == p2.numerator * p1.denominator);
}

bool operator!=(Percent p1, Percent p2)
{
    return (p1.numerator * p2.denominator != p2.numerator * p1.denominator);
}

bool operator<(Percent p1, Percent p2)
{
    return (p1.numerator * p2.denominator < p2.numerator * p1.denominator);
}

bool operator<=(Percent p1, Percent p2)
{
    return (p1.numerator * p2.denominator <= p2.numerator * p1.denominator);
}

bool operator>(Percent p1, Percent p2)
{
    return (p1.numerator * p2.denominator > p2.numerator * p1.denominator);
}

bool operator>=(Percent p1, Percent p2)
{
    return (p1.numerator * p2.denominator >= p2.numerator * p1.denominator);
}

ostream& operator<<(ostream& out, Percent p)
{
    out << p.numerator << "/" << p.denominator;
    return out;
}

istream& operator>>(istream& in, Percent& p)
{
    in >> p.numerator >> p.denominator;
    return in;
}

Percent operator+=(Percent& p1, Percent p2)
{
    p1.numerator = p1.numerator * p2.denominator + p2.numerator * p1.denominator;
    p1.denominator = p1.denominator * p2.denominator;
    return p1;
}

Percent operator-=(Percent& p1, Percent p2)
{
    p1.numerator = p1.numerator * p2.denominator - p2.numerator * p1.denominator;
    p1.denominator = p1.denominator * p2.denominator;
    return p1;
}

Percent operator++(Percent& p)
{
    p.numerator += p.denominator;
    return p;
}

Percent operator++(Percent& p, int)
{
    Percent temp = p;
    p.numerator += p.denominator;
    return temp;
}

Percent operator--(Percent& p)
{
    p.numerator -= p.denominator;
    return p;
}

Percent operator--(Percent& p, int)
{
    Percent temp = p;
    p.numerator -= p.denominator;
    return temp;
}

const Percent Percent::operator-() const
{
    Percent temp;
    temp.numerator = -numerator;
    temp.denominator = denominator;
    return temp;
}

const Percent Percent::operator+() const
{
    Percent temp;
    temp.numerator = numerator;
    temp.denominator = denominator;
    return temp;
}

const Percent Percent::operator=(const Percent& p) const
{
    Percent temp;
    temp.numerator = p.numerator;
    temp.denominator = p.denominator;
    return temp;
}

const Percent Percent::operator+=(const Percent& p) const
{
    Percent temp;
    temp.numerator = numerator * p.denominator + p.numerator * denominator;
    temp.denominator = denominator * p.denominator;
    return temp;
}

const Percent Percent::operator-=(const Percent& p) const
{
    Percent temp;
    temp.numerator = numerator * p.denominator - p.numerator * denominator;
    temp.denominator = denominator * p.denominator;
    return temp;
}

const Percent Percent::operator++() const
{
    Percent temp;
    temp.numerator = numerator + denominator;
    temp.denominator = denominator;
    return temp;
}

int main(int argc, char** argv) {
  Percent p1, p2, p3;
    p1.input();
    p2.input();
    p3 = p1 + p2;
    p3.print();
    p3 = p1 - p2;
    p3.print();
    if (p1 == p2)
        cout << "p1 == p2" << endl;
    if (p1 != p2)
        cout << "p1 != p2" << endl;
    if (p1 < p2)
        cout << "p1 < p2" << endl;
    if (p1 <= p2)
        cout << "p1 <= p2" << endl;
    if (p1 > p2)
        cout << "p1 > p2" << endl;
    if (p1 >= p2)    
        cout << "p1 >= p2" << endl;
    cout << p1 << endl;
    cin >> p1;
    cout << p1 << endl;
    p1 += p2;
    cout << p1 << endl;
    p1 -= p2;
    cout << p1 << endl;
    ++p1;
    cout << p1 << endl;
    p1++;
    cout << p1 << endl;
    --p1;
    cout << p1 << endl;
    p1--;
    cout << p1 << endl;
    p1 = -p1;
    cout << p1 << endl;
    p1 = +p1;
    cout << p1 << endl;
    p1 = p2;
    cout << p1 << endl;
    p1 += p2;
    cout << p1 << endl;
    return 0;
} 

