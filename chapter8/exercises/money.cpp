/**
 * @file money.cpp
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

int static dollar; //static variable

int main(int argc, char **argv);

class Money
{
    private: 
        int dollars;
        int cents;
    public: 
        Money();
        Money(int dollars, int cents);
        ~Money();
        int get_dollars();
        int get_cents();
        void set_dollars(int dollars);
        void set_cents(int cents);
        void add(Money m);
        void subtract(Money m);
        void input();
        void output();
        void print();
        friend Money operator+(Money m1, Money m2);
        friend Money operator-(Money m1, Money m2);
        friend bool operator==(Money m1, Money m2);
        friend bool operator!=(Money m1, Money m2);
        friend bool operator<(Money m1, Money m2);
        friend bool operator<=(Money m1, Money m2);
        friend bool operator>(Money m1, Money m2);
        friend bool operator>=(Money m1, Money m2);
        friend ostream& operator<<(ostream& out, Money m);
        friend istream& operator>>(istream& in, Money& m);
        friend Money operator+=(Money& m1, Money m2);
        friend Money operator-=(Money& m1, Money m2);
        friend Money operator++(Money& m);
        friend Money operator++(Money& m, int);
        friend Money operator--(Money& m);
        friend Money operator--(Money& m, int);
        const Money operator-() const;
        const Money operator+() const;
        const Money operator=(const Money& m) const;
        const Money operator+=(const Money& m) const;
        const Money operator-=(const Money& m) const;
        const Money operator++() const; 
};

Money::Money()
{
    dollars = 0;
    cents = 0;
}

Money::Money(int dollars, int cents)
{
    this->dollars = dollars;
    this->cents = cents;
}

Money::~Money()
{
    cout << "Destructor called" << endl;
}

int Money::get_dollars()
{
    return dollars;
}

int Money::get_cents()
{
    return cents;
}

void Money::set_dollars(int dollars)
{
    this->dollars = dollars;
}

void Money::set_cents(int cents)
{
    this->cents = cents;
}

void Money::add(Money m)
{
    dollars += m.dollars;
    cents += m.cents;
    if (cents >= 100)
    {
        dollars++;
        cents -= 100;
    }
}

void Money::subtract(Money m)
{
    dollars -= m.dollars;
    cents -= m.cents;
    if (cents < 0)
    {
        dollars--;
        cents += 100;
    }
}

void Money::input()
{
    cout << "Enter dollars: ";
    cin >> dollars;
    cout << "Enter cents: ";
    cin >> cents;
}

void Money::output()
{
    cout << "Dollars: " << dollars << endl;
    cout << "Cents: " << cents << endl;
}

void Money::print()
{
    cout << "$" << dollars << "." << cents << endl;
}

Money operator+(Money m1, Money m2)
{
    Money m;
    m.dollars = m1.dollars + m2.dollars;
    m.cents = m1.cents + m2.cents;
    if (m.cents >= 100)
    {
        m.dollars++;
        m.cents -= 100;
    }
    return m;
}

Money operator-(Money m1, Money m2)
{
    Money m;
    m.dollars = m1.dollars - m2.dollars;
    m.cents = m1.cents - m2.cents;
    if (m.cents < 0)
    {
        m.dollars--;
        m.cents += 100;
    }
    return m;
}

bool operator==(Money m1, Money m2)
{
    return (m1.dollars == m2.dollars && m1.cents == m2.cents);
}

bool operator!=(Money m1, Money m2)
{
    return !(m1 == m2);
}

bool operator<(Money m1, Money m2)
{
    if (m1.dollars < m2.dollars)
    {
        return true;
    }
    else if (m1.dollars == m2.dollars)
    {
        return (m1.cents < m2.cents);
    }
    else
    {
        return false;
    }
}

bool operator<=(Money m1, Money m2)
{
    return (m1 < m2 || m1 == m2);
}

bool operator>(Money m1, Money m2)
{
    return !(m1 <= m2);
}

bool operator>=(Money m1, Money m2)
{
    return !(m1 < m2);
}

ostream& operator<<(ostream& out, Money m)
{
    out << "$" << m.dollars << "." << m.cents;
    return out;
}

istream& operator>>(istream& in, Money& m)
{
    in >> m.dollars >> m.cents;
    return in;
}

Money operator+=(Money& m1, Money m2)
{
    m1.dollars += m2.dollars;
    m1.cents += m2.cents;
    if (m1.cents >= 100)
    {
        m1.dollars++;
        m1.cents -= 100;
    }
    return m1;
}

Money operator-=(Money& m1, Money m2)
{
    m1.dollars -= m2.dollars;
    m1.cents -= m2.cents;
    if (m1.cents < 0)
    {
        m1.dollars--;
        m1.cents += 100;
    }
    return m1;
}

Money operator++(Money& m)
{
    m.dollars++;
    return m;
}

Money operator++(Money& m, int)
{
    Money temp = m;
    m.dollars++;
    return temp;
}

Money operator--(Money& m)
{
    m.dollars--;
    return m;
}

Money operator--(Money& m, int)
{
    Money temp = m;
    m.dollars--;
    return temp;
}

const Money Money::operator-() const
{
    Money m;
    m.dollars = -dollars;
    m.cents = -cents;
    return m;
}

const Money Money::operator+() const
{
    Money m;
    m.dollars = +dollars;
    m.cents = +cents;
    return m;
}

const Money Money::operator++() const
{
    Money m;
    m.dollars = ++dollar;
    m.cents = cents;
    return m;
}

int main(int argc, char **argv)
{
    Money m1(10, 50);
    Money m2(5, 25);
    Money m3;
    m3 = m1 + m2;
    m3.print();
    m3 = m1 - m2;
    m3.print();
    if (m1 == m2)
    {
        cout << "m1 and m2 are equal" << endl;
    }
    else
    {
        cout << "m1 and m2 are not equal" << endl;
    }
    if (m1 != m2)
    {
        cout << "m1 and m2 are not equal" << endl;
    }
    else
    {
        cout << "m1 and m2 are equal" << endl;
    }
    if (m1 < m2)
    {
        cout << "m1 is less than m2" << endl;
    }
    else
    {
        cout << "m1 is not less than m2" << endl;
    }
    if (m1 <= m2)
    {
        cout << "m1 is less than or equal to m2" << endl;
    }
    else
    {
        cout << "m1 is not less than or equal to m2" << endl;
    }
    if (m1 > m2)
    {
        cout << "m1 is greater than m2" << endl;
    }
    else
    {
        cout << "m1 is not greater than m2" << endl;
    }
    if (m1 >= m2)
    {
        cout << "m1 is greater than or equal to m2" << endl;
    }
    else
    {
        cout << "m1 is not greater than or equal to m2" << endl;
    }
    cout << m1 << endl;
    cout << m2 << endl;
    cin >> m3;
    cout << m3 << endl;
    m3 += m1;
    cout << m3 << endl;
    m3 -= m1;
    cout << m3 << endl;
    ++m3;
    cout << m3 << endl;
    m3++;
    cout << m3 << endl;
    --m3;
    cout << m3 << endl;
    m3--;
    cout << m3 << endl;
    return 0;
}

/**
 * @brief A binary operator is an operator that takes two operands. A function can take two parameters and be used as a binary operator.
 * To overload Money with the < operator, we need to define a function that takes two Money objects as parameters and returns a bool.
 * It is possible to use operator overloading to overload + operator by defining a function that takes two Money objects as parameters and returns a Money object.
 * If we omit the const operator in the function declaration, we can modify the object that is passed as a parameter.
 * A friend function is a function that is not a member of a class but has access to the private and protected members of the class. A member function is a function that is a member of a class.
 * If we want to overload the < operator, we can use the friend function.
 * The << operator is not a circular definition because the << operator is not a member of the Money class.
 * We cannot overload << and >> operators as member functions because they are not binary operators.
 */