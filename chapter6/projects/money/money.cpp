/**
 * @file money.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Money
{
    private:
        int dollars;
        int cents;
    public:
        Money();
        Money(int newDollars, int newCents);
        void setDollars(int newDollars);
        void setCents(int newCents);
        int getDollars();
        int getCents();
        void print();
        double getAmount();
        Money creator();
        Money destructor();
};

class NewMoney
{
    public:
        NewMoney(int newDollars, int newCents);
        void setDollars(int newDollars);
        void setCents(int newCents);
        int getDollars();
        int getCents();
        void print();
        double getAmount();
        NewMoney creator();
        NewMoney destructor();
};

int dollars; 
int cents;

int main(int argc, char **argv);

Money::Money()
{
    dollars = 0;
    cents = 0;
}

Money::Money(int newDollars, int newCents)
{
    dollars = newDollars;
    cents = newCents;
}

void Money::setDollars(int newDollars)
{
    dollars = newDollars;
}

void Money::setCents(int newCents)
{
    cents = newCents;
}

int Money::getDollars()
{
    return dollars;
}

int Money::getCents()
{
    return cents;
}

void Money::print()
{
    cout << "Dollars: " << dollars << endl;
    cout << "Cents: " << cents << endl;
}

double Money::getAmount()
{
    return dollars + (cents / 100.0);
}

NewMoney::NewMoney(int newDollars, int newCents)
{
    dollars = newDollars;
    cents = newCents;
}

void NewMoney::setDollars(int newDollars)
{
    dollars = newDollars;
}

void NewMoney::setCents(int newCents)
{
    cents = newCents;
}

int NewMoney::getDollars()
{
    return dollars;
}

int NewMoney::getCents()
{
    return cents;
}

void NewMoney::print()
{
    cout << "Dollars: " << dollars << endl;
    cout << "Cents: " << cents << endl;
}

double NewMoney::getAmount()
{
    return dollars + (cents / 100.0);
}

int main(int argc, char **argv)
{
    Money m1;
    Money m2(10, 20);
    m1.setDollars(5);
    m1.setCents(10);
    m1.print();
    cout << "Amount: " << m1.getAmount() << endl;
    m2.print();
    cout << "Amount: " << m2.getAmount() << endl;
    NewMoney m3(10, 20);
    m3.print();
    cout << "Amount: " << m3.getAmount() << endl;
    return 0;
}

