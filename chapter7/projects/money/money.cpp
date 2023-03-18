/**
 * @file money.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class Money
{
    private:
        int dollars;
        int cents;
    public:
        Money(int dollars, int cents);
        Money(); 
        void print();
        int getDollars();
        void setDollars(int dollars);
        int getCents();
        void setCents(int cents);
        void add(Money m);
        void add(int dollars, int cents);
        void subtract(Money m);
        void subtract(int dollars, int cents);
        void multiply(int factor);
        void divide(int factor);
};

Money::Money(int dollars, int cents)
{
    this->dollars = dollars;
    this->cents = cents;
}

Money::Money()
{
    this->dollars = 0;
    this->cents = 0;
}

void Money::print()
{
    cout << "dollars = " << dollars << endl;
    cout << "cents = " << cents << endl;
}

int Money::getDollars()
{
    return dollars;
}

void Money::setDollars(int dollars)
{
    this->dollars = dollars;
}

int Money::getCents()
{
    return cents;
}

void Money::setCents(int cents)
{
    this->cents = cents;
}

void Money::add(Money m)
{
    this->dollars += m.getDollars();
    this->cents += m.getCents();
}

void Money::add(int dollars, int cents)
{
    this->dollars += dollars;
    this->cents += cents;
}

void Money::subtract(Money m)
{
    this->dollars -= m.getDollars();
    this->cents -= m.getCents();
}

void Money::subtract(int dollars, int cents)
{
    this->dollars -= dollars;
    this->cents -= cents;
}

void Money::multiply(int factor)
{
    this->dollars *= factor;
    this->cents *= factor;
}

void Money::divide(int factor)
{
    this->dollars /= factor;
    this->cents /= factor;
}

int main(int argc, char **argv)
{
    Money m1(10, 20);
    Money m2(30, 40);
    Money m3;
    m1.print();
    m2.print();
    m3.print();
    m3.add(m1);
    m3.print();
    m3.add(10, 20);
    m3.print();
    m3.subtract(m2);
    m3.print();
    m3.subtract(10, 20);
    m3.print();
    m3.multiply(2);
    m3.print();
    m3.divide(2);
    m3.print();
    return 0;
}