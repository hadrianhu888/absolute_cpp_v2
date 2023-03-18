/**
 * @file BankAccount.cpp
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

class BankAccount
{
    private:
        string name;
        string address;
        string accountNumber;
        double balance;
        float rate; 
        int period; 
        int dollars;
        double cents;
    public:
        BankAccount();
        BankAccount(double newBalance, float newRate, int newPeriod);
        BankAccount(string newName, string newAddress, string newAccountNumber, double newBalance);
        void setName(string newName);
        void setAddress(string newAddress);
        void setAccountNumber(string newAccountNumber);
        void setBalance(double newBalance);
        void setRate(float newRate);
        void setPeriod(int newPeriod);
        int setDollars(int newDollars);
        double setCents(double newCents);
        string getName();
        string getAddress();
        string getAccountNumber();
        double getBalance();
        float getRate();
        int getPeriod();
        int getDollars();
        double getCents();
        void print();
        float amortizationPerPeriod();
        BankAccount creator();
        BankAccount destructor();
        int convertToDollars();
        double convertToCents();
};

int main(int argc, char **argv);

BankAccount::BankAccount()
{
    name = "";
    address = "";
    accountNumber = "";
    balance = 0;
}

BankAccount::BankAccount(double newBalance, float newRate, int newPeriod)
{
    balance = newBalance;
    rate = newRate;
    period = newPeriod;
}

BankAccount::BankAccount(string newName, string newAddress, string newAccountNumber, double newBalance)
{
    name = newName;
    address = newAddress;
    accountNumber = newAccountNumber;
    balance = newBalance;
}

void BankAccount::setName(string newName)
{
    name = newName;
}

void BankAccount::setAddress(string newAddress)
{
    address = newAddress;
}

void BankAccount::setAccountNumber(string newAccountNumber)
{
    accountNumber = newAccountNumber;
}

void BankAccount::setBalance(double newBalance)
{
    balance = newBalance;
}

void BankAccount::setRate(float newRate)
{
    rate = newRate;
}

void BankAccount::setPeriod(int newPeriod)
{
    period = newPeriod;
}

int BankAccount::setDollars(int newDollars)
{
    dollars = newDollars;
}

double BankAccount::setCents(double newCents)
{
    cents = newCents;
}

string BankAccount::getName()
{
    return name;
}

string BankAccount::getAddress()
{
    return address;
}

string BankAccount::getAccountNumber()
{
    return accountNumber;
}

double BankAccount::getBalance()
{
    return balance;
}

float BankAccount::getRate()
{
    return rate;
}

int BankAccount::getDollars()
{
    return dollars;
}

double BankAccount::getCents()
{
    return cents;
}

float BankAccount::amortizationPerPeriod()
{
    return balance * rate / period;
}

int BankAccount::getPeriod()
{
    return period;
}

void BankAccount::print()
{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}

int BankAccount::convertToDollars()
{
    return balance / 100;
}

double BankAccount::convertToCents()
{
    balance = balance * 100;
    return static_cast<int>(balance) - (static_cast<int>(balance) / 100) * 100;
}

BankAccount BankAccount::creator()
{
    BankAccount newAccount;
    return newAccount;
}

BankAccount BankAccount::destructor()
{
    BankAccount newAccount;
    return newAccount;
}

int main(int argc, char **argv)
{
    BankAccount account1;
    BankAccount account2("John Smith", "123 Main Street", "123456789", 1000);
    account1.setName("Jane Doe");
    account1.setAddress("456 Main Street");
    account1.setAccountNumber("987654321");
    account1.setBalance(500);
    account1.setRate(0.05);
    account1.setPeriod(1);
    cout << "Name: " << account1.getName() << endl;
    cout << "Address: " << account1.getAddress() << endl;
    cout << "Account Number: " << account1.getAccountNumber() << endl;
    cout << "Balance: " << account1.getBalance() << endl;
    cout << "Rate: " << account1.getRate() << endl;
    cout << "Period: " << account1.getPeriod() << endl;
    cout << "Dollars: " << account1.convertToDollars() << endl;
    cout << "Cents: " << account1.convertToCents() << endl;
    cout << "Amortization per period: " << (account1.amortizationPerPeriod()) << endl;
    account1.print();
    account2.print();
    return 0;
}