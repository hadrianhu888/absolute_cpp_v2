/**
 * @file bank_account.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp"

typedef struct BankAccount
{
    string name;
    string account_number;
    double balance;
    char type;
    char status;
} BankAccount;

typedef struct date
{
    int day;
    int month;
    int year;
} date;

int main(int argc,char **argv); 
void print_account(BankAccount account);
void print_date(date date);

int main(int argc,char **argv)
{
    BankAccount account;
    date date;
    account.name = "John Doe";
    account.account_number = "123456789";
    account.balance = 1000.00;
    account.type = 'S';
    account.status = 'A';
    date.day = 1;
    date.month = 1;
    date.year = 2023;
    print_account(account);
    print_date(date);
    return 0;
}

void print_account(BankAccount account)
{
    cout << "Name: " << account.name << endl;
    cout << "Account Number: " << account.account_number << endl;
    cout << "Balance: " << account.balance << endl;
    cout << "Type: " << account.type << endl;
    cout << "Status: " << account.status << endl;
}

void print_date(date date)
{
    cout << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;
}

/**
 * @brief // Path: chapter6\exercises\bank_account.cpp
 * 
 */

