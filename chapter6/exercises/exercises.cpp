/**
 * @file exercises.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file 

using namespace std;

typedef struct CDAccountV2
{
    double balance;
    double interestRate;
    int term;
    char initial_1; 
    char initial_2;
} CDAccountV2;

typedef struct ShoeType 
{
    int size;
    string brand;
    string color;
    float price; 
} ShoeType;

typedef struct Stuff
{
    int x;
    int y;
    int z;
} Stuff;

typedef struct A
{
    int memberB; 
    int memberC;
} A;

typedef struct Date 
{
    int month;
    int day;
    int year;
} Date;

typedef struct EmployeeRecord
{
    int employeeNumber;
    float hoursWorked;
    float hourlyWage;
    float grossPay;
    float taxes;
    float netPay;
} EmployeeRecord;

void readShoeRecord(ShoeType &shoe);
ShoeType discount(ShoeType &shoe, float discount);

void readShoeRecord(ShoeType &shoe)
{
    cout << "Enter the size of the shoe: ";
    cin >> shoe.size;
    cout << "Enter the brand of the shoe: ";
    cin >> shoe.brand;
    cout << "Enter the color of the shoe: ";
    cin >> shoe.color;
    cout << "Enter the price of the shoe: ";
    cin >> shoe.price;
}

ShoeType discount(ShoeType &shoe, float discount)
{
    shoe.price = shoe.price - (shoe.price * discount);
    return shoe;
}

int main(int argc,char **argv); 

int main(int argc, char **argv)
{
    /**
     * @brief initialize the bank account 
     * 
     */
    CDAccountV2 account;
    account.balance = 1000;
    account.interestRate = 0.05;
    account.term = 3;
    account.initial_1 = 'A';
    account.initial_2 = 'B';
    /**
     * @brief print the bank account
     * 
     */
    cout << "Account balance: $" << account.balance << endl;
    cout << "Account interest rate: " << account.interestRate << endl;
    cout << "Account term: " << account.term << endl;
    cout << "Account initials: " << account.initial_1 << account.initial_2 << endl;
    ShoeType shoe1, shoe2; 
    shoe1.size = 10;
    shoe1.brand = "Nike";
    shoe1.color = "Red";
    shoe1.price = 100.00;
    shoe2.size = 8;
    shoe2.brand = "Adidas";
    shoe2.color = "Blue";
    shoe2.price = shoe1.price / 2;
    cout << "Shoe 1 is a size " << shoe1.size << " " << shoe1.brand << " shoe in " << shoe1.color << shoe1.price << endl;
    cout << "Shoe 2 is a size " << shoe2.size << " " << shoe2.brand << " shoe in " << shoe2.color << shoe2.price << endl;
    Stuff stuff1, stuff2;
    stuff1.x = 1;
    stuff1.y = 2;
    stuff1.z = 3;
    stuff2.x = 4;
    stuff2.y = 5;
    stuff2.z = 6;
    cout << "Stuff 1: " << stuff1.x << " " << stuff1.y << " " << stuff1.z << endl;
    cout << "Stuff 2: " << stuff2.x << " " << stuff2.y << " " << stuff2.z << endl;
    A a1, a2;
    a1.memberB = 1;
    a1.memberC = 2;
    a2.memberB = 3;
    a2.memberC = 4;
    cout << "A1: " << a1.memberB << " " << a1.memberC << endl;
    cout << "A2: " << a2.memberB << " " << a2.memberC << endl;
    Date date1, date2;
    date1.month = 1;
    date1.day = 2;
    date1.year = 3;
    date2.month = 4;
    date2.day = 5;
    date2.year = 6;
    cout << "Date 1: " << date1.month << "/" << date1.day << "/" << date1.year << endl;
    cout << "Date 2: " << date2.month << "/" << date2.day << "/" << date2.year << endl;
    EmployeeRecord employee1, employee2;
    employee1.employeeNumber = 1;
    employee1.hoursWorked = 2;
    employee1.hourlyWage = 3;
    employee1.grossPay = 4;
    employee1.taxes = 5;
    employee1.netPay = 6;
    employee2.employeeNumber = 7;
    employee2.hoursWorked = 8;
    employee2.hourlyWage = 9;
    employee2.grossPay = 10;
    employee2.taxes = 11;
    employee2.netPay = 12;
    cout << "Employee 1: " << employee1.employeeNumber << " " << employee1.hoursWorked << " " << employee1.hourlyWage << " " << employee1.grossPay << " " << employee1.taxes << " " << employee1.netPay << endl;
    cout << "Employee 2: " << employee2.employeeNumber << " " << employee2.hoursWorked << " " << employee2.hourlyWage << " " << employee2.grossPay << " " << employee2.taxes << " " << employee2.netPay << endl;
    ShoeType shoe3;
    readShoeRecord(shoe3);
    cout << "Shoe 3 is a size " << shoe3.size << " " << shoe3.brand << " shoe in " << shoe3.color << shoe3.price << endl;
    ShoeType shoe4;
    shoe4 = discount(shoe3, 0.5);
    cout << "Shoe 4 is a size " << shoe4.size << " " << shoe4.brand << " shoe in " << shoe4.color << shoe4.price << endl;
    return 0;
}



