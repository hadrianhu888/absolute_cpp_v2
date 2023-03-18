/**
 * @file rattional.cpp
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

class Rational 
{
    private: 
        int numerator;
        int denominator;
    public: 
        Rational();
        Rational(int numerator, int denominator);
        ~Rational();
        int get_numerator();
        int get_denominator();
        void set_numerator(int numerator);
        void set_denominator(int denominator);
        void input();
        void output();
        void print();
        friend Rational operator+(Rational r1, Rational r2);
        friend Rational operator-(Rational r1, Rational r2);
        friend bool operator==(Rational r1, Rational r2);
        friend bool operator!=(Rational r1, Rational r2);
        friend bool operator<(Rational r1, Rational r2);
        friend bool operator<=(Rational r1, Rational r2);
        friend bool operator>(Rational r1, Rational r2);
        friend bool operator>=(Rational r1, Rational r2);
        friend ostream& operator<<(ostream& out, Rational r);
        friend istream& operator>>(istream& in, Rational& r);
        friend Rational operator+=(Rational& r1, Rational r2);
        friend Rational operator-=(Rational& r1, Rational r2);
        friend Rational operator++(Rational& r);
        friend Rational operator++(Rational& r, int);
        friend Rational operator--(Rational& r);
        friend Rational operator--(Rational& r, int);
        const Rational operator-() const;
        const Rational operator+() const;
        const Rational operator/(const Rational& r) const;
        const Rational operator*(const Rational& r) const;
        const Rational operator%(const Rational& r) const;
        const Rational operator=(const Rational& r) const;
        const Rational operator+=(const Rational& r) const;
        const Rational operator-=(const Rational& r) const;
        const Rational operator++() const; 
};

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

Rational::~Rational()
{
}

int Rational::get_numerator()
{
    return numerator;
}

int Rational::get_denominator()
{
    return denominator;
}

void Rational::set_numerator(int numerator)
{
    this->numerator = numerator;
}

void Rational::set_denominator(int denominator)
{
    this->denominator = denominator;
}

void Rational::input()
{
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
}

void Rational::output()
{
    cout << numerator << "/" << denominator;
}

void Rational::print()
{
    cout << numerator << "/" << denominator << endl;
}

Rational operator+(Rational r1, Rational r2)
{
    Rational temp;
    temp.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    temp.denominator = r1.denominator * r2.denominator;
    return temp;
}

Rational operator-(Rational r1, Rational r2)
{
    Rational temp;
    temp.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    temp.denominator = r1.denominator * r2.denominator;
    return temp;
}

bool operator==(Rational r1, Rational r2)
{
    return (r1.numerator * r2.denominator == r2.numerator * r1.denominator);
}

bool operator!=(Rational r1, Rational r2)
{
    return (r1.numerator * r2.denominator != r2.numerator * r1.denominator);
}

bool operator<(Rational r1, Rational r2)
{
    return (r1.numerator * r2.denominator < r2.numerator * r1.denominator);
}

bool operator<=(Rational r1, Rational r2)
{
    return (r1.numerator * r2.denominator <= r2.numerator * r1.denominator);
}

bool operator>(Rational r1, Rational r2)
{
    return (r1.numerator * r2.denominator > r2.numerator * r1.denominator);
}

bool operator>=(Rational r1, Rational r2)
{
    return (r1.numerator * r2.denominator >= r2.numerator * r1.denominator);
}

ostream& operator<<(ostream& out, Rational r)
{
    out << r.numerator << "/" << r.denominator;
    return out;
}

istream& operator>>(istream& in, Rational& r)
{
    in >> r.numerator >> r.denominator;
    return in;
}

Rational operator+=(Rational& r1, Rational r2)
{
    r1.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    r1.denominator = r1.denominator * r2.denominator;
    return r1;
}

Rational operator-=(Rational& r1, Rational r2)
{
    r1.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    r1.denominator = r1.denominator * r2.denominator;
    return r1;
}

Rational operator++(Rational& r)
{
    r.numerator += r.denominator;
    return r;
}

Rational operator++(Rational& r, int)
{
    Rational temp = r;
    r.numerator += r.denominator;
    return temp;
}

Rational operator--(Rational& r)
{
    r.numerator -= r.denominator;
    return r;
}

Rational operator--(Rational& r, int)
{
    Rational temp = r;
    r.numerator -= r.denominator;
    return temp;
}

const Rational Rational::operator-() const
{
    Rational temp;
    temp.numerator = -numerator;
    temp.denominator = denominator;
    return temp;
}

const Rational Rational::operator+() const
{
    Rational temp;
    temp.numerator = numerator;
    temp.denominator = denominator;
    return temp;
}

const Rational Rational::operator=(const Rational& r) const
{
    Rational temp;
    temp.numerator = r.numerator;
    temp.denominator = r.denominator;
    return temp;
}

const Rational Rational::operator+=(const Rational& r) const
{
    Rational temp;
    temp.numerator = numerator * r.denominator + r.numerator * denominator;
    temp.denominator = denominator * r.denominator;
    return temp;
}

const Rational Rational::operator-=(const Rational& r) const
{
    Rational temp;
    temp.numerator = numerator * r.denominator - r.numerator * denominator;
    temp.denominator = denominator * r.denominator;
    return temp;
}

const Rational Rational::operator++() const
{
    Rational temp;
    temp.numerator = numerator + denominator;
    temp.denominator = denominator;
    return temp;
}

const Rational Rational::operator/(const Rational& r) const
{
    Rational temp;
    temp.numerator = numerator * r.denominator;
    temp.denominator = denominator * r.numerator;
    return temp;
}

const Rational Rational::operator*(const Rational& r) const
{
    Rational temp;
    temp.numerator = numerator * r.numerator;
    temp.denominator = denominator * r.denominator;
    return temp;
}

int main(int argc, char **argv)
{
    /**
     * @brief test each member function once
     * 
     */
    Rational **r = new Rational*[10];
    for (int i = 0; i < 10; i++)
    {
        r[i] = new Rational(i, i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        r[i]->print();
        cout << endl; // print each rational number
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        r[i]->set_numerator(i + 1);
        r[i]->set_denominator(i + 2);
    }
    for (int i = 0; i < 10; i++)
    {
        r[i]->print();
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        r[i]->input();
    }
    for (int i = 0; i < 10; i++)
    {
        r[i]->print();
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        r[i]->output();
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        delete r[i];
    }
    delete[] r;
    /**
     * @brief test each operator once
     * Test the friend operators
     */
    Rational r1(1, 2), r2(1, 3), r3(1, 4), r4(1, 5), r5(1, 6), r6(1, 7), r7(1, 8), r8(1, 9), r9(1, 10), r10(1, 11);
    cout << r1 + r2 << endl;
    cout << r1 - r2 << endl;
    cout << r1 * r2 << endl;
    cout << r1 / r2 << endl;
    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    cout << r4 << endl;
    return 0;
}

