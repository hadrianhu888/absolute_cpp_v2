/**
 * @file account_exceptions.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
class Account
{
    private:
        T _balance;
    public:
        Account(T balance = 0);
        void deposit(T amount);
        void withdraw(T amount);
        T getBalance() const;
};

template <class T>
class Credit: public Account<T>
{
    private:
        T _creditLimit;
    public:
        Credit(T balance = 0, T creditLimit = 0);
        void withdraw(T amount);
};

template <class T>
class Debit: public Account<T>
{
    private:
        T _debitLimit;
    public:
        Debit(T balance = 0, T debitLimit = 0);
        void withdraw(T amount);
};

    template <class T>
    Account<T>::Account(T balance)
{
    _balance = balance;
}

template <class T>
void Account<T>::deposit(T amount)
{
    _balance += amount;
}

template <class T>
void Account<T>::withdraw(T amount)
{
    try
    {
        if (_balance - amount < 0)
        {
            throw _balance;
        }
        _balance -= amount;
    }
    catch (T e)
    {
        cout << "Withdraw amount of " << amount << " exceeds balance of " << e << endl;
    }
}

template <class T>
T Account<T>::getBalance() const
{
    return _balance;
}

template <class T>
Credit<T>::Credit(T balance, T creditLimit) : Account<T>(balance)
{
    _creditLimit = creditLimit;
}

template <class T>
void Credit<T>::withdraw(T amount)
{
    try
    {
        if (Account<T>::getBalance() - amount < -_creditLimit)
        {
            throw Account<T>::getBalance();
        }
        Account<T>::withdraw(amount);
    }
    catch (T e)
    {
        cout << "Withdraw amount of " << amount << " exceeds credit limit of " << e << endl;
    }
}

template <class T>
Debit<T>::Debit(T balance, T debitLimit) : Account<T>(balance)
{
    _debitLimit = debitLimit;
}

template <class T>
void Debit<T>::withdraw(T amount)
{
    try
    {
        if (Account<T>::getBalance() - amount < -_debitLimit)
        {
            throw Account<T>::getBalance();
        }
        Account<T>::withdraw(amount);
    }
    catch (T e)
    {
        cout << "Withdraw amount of " << amount << " exceeds debit limit of " << e << endl;
    }
}

int main(int argc, char **argv)
{
    Account<int> a(100);
    a.withdraw(50);
    a.withdraw(100);
    a.deposit(100);
    a.withdraw(200);
    cout << "Balance: " << a.getBalance() << endl;
    cout << endl;
    Credit <int> c(100, 50);
    c.withdraw(50);
    c.withdraw(100);
    c.deposit(100);
    Debit<int> d(100, 50);
    d.withdraw(50);
    d.withdraw(100);
    d.deposit(100);
    return 0;
}
