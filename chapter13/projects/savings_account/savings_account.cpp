/**
 * @file savings_account.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class Loan
{
private:
    double balance;
    double interestRate;
public:
    Loan(double balance, double interestRate);
    void pay(double amount);
    void addInterest();
    double getBalance();
    double getInterestRate();
};

Loan::Loan(double balance, double interestRate)
{
    this->balance = balance;
    this->interestRate = interestRate / 1200; // Convert APR to monthly percentage
}

void Loan::pay(double amount)
{
    this->balance -= amount;
}

void Loan::addInterest()
{
    this->balance += this->balance * this->interestRate;
}

double Loan::getBalance()
{
    return this->balance;
}

double Loan::getInterestRate()
{
    return this->interestRate;
}

void showAmortizationTable(double amount, double interestRate, double monthlyPayment);
int calculatePaymentPeriod(double interestRate, double monthlyPayment, double balance);

void showAmortizationTable(double amount, double interestRate, double monthlyPayment)
{
    Loan loan(amount, interestRate);
    int month = 0;
    double principal, interest;

    cout << "Month\tBalance\t\tPrincipal\tInterest" << endl;
    cout << fixed << setprecision(2);

    while (loan.getBalance() > 0)
    {
        interest = loan.getBalance() * loan.getInterestRate();
        principal = monthlyPayment - interest;

        if (loan.getBalance() + interest < monthlyPayment)
        {
            monthlyPayment = loan.getBalance() + interest;
            principal = loan.getBalance();
        }

        loan.addInterest();
        loan.pay(principal);

        cout << month << "\t" << loan.getBalance() << "\t\t" << principal << "\t\t" << interest << endl;

        month++;
    }
}

int calculatePaymentPeriod(double interestRate, double monthlyPayment, double balance)
{
    Loan loan(balance, interestRate);
    int month = 0;
    double principal, interest;

    while (loan.getBalance() > 0)
    {
        interest = loan.getBalance() * loan.getInterestRate();
        principal = monthlyPayment - interest;

        if (loan.getBalance() + interest < monthlyPayment)
        {
            monthlyPayment = loan.getBalance() + interest;
            principal = loan.getBalance();
        }

        loan.addInterest();
        loan.pay(principal);

        month++;
    }

    return month;
}

    int main()
{
    double amount = 100000;
    double interestRate = 5; // 5% Annual Percentage Rate
    double monthlyPayment = 1000;

    cout << "Loan Amount: " << amount << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Monthly Payment: " << monthlyPayment << endl;
    cout << endl;

    showAmortizationTable(amount, interestRate, monthlyPayment);

    return 0;
}
