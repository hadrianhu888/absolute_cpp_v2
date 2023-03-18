/**
 * @file month.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class Month
{
    private:
        int month;
        char month_letter_1; 
        char month_letter_2;
        char month_letter_3;
    public:
        Month(int month);
        Month(char month_letter_1, char month_letter_2, char month_letter_3); 
        void print();
        int getMonth();
        void setMonth(int month);
        int convertCharToInt(char month_letter1, char month_letter2, char month_letter3);
        void printMonth();
        void printMonth(char month_letter_1, char month_letter_2, char month_letter_3); 
        void setMonth(char month_letter_1, char month_letter_2, char month_letter_3);
};

int main(int argc, char **argv) {
    Month m(1);
    m.print();
    Month m1('J', 'a', 'n');
    m1.convertCharToInt('J', 'a', 'n');
    m1.printMonth('J', 'a', 'n');
    return 0;
}

Month::Month(int month)
{
    this->month = month;
}

Month::Month(char month_letter_1, char month_letter_2, char month_letter_3)
{
    this->month_letter_1 = month_letter_1;
    this->month_letter_2 = month_letter_2;
    this->month_letter_3 = month_letter_3;
}

void Month::print()
{
    cout << "month = " << month << endl;
}

int Month::getMonth()
{
    return month;
}

void Month::setMonth(int month)
{
    this->month = month;
}

int Month::convertCharToInt(char month_letter1, char month_letter2, char month_letter3)
{
    /**
     * @brief Take all three letters and convert them to a number
     * 
     */
    int month_number = 0;
    month_number = month_letter1 + month_letter2 + month_letter3;
    switch (month_number)
    {
    case 294:
        month_number = 1;
        break;
    case 296:
        month_number = 2;
        break;
    case 297:
        month_number = 3;
        break;
    case 300:
        month_number = 4;
        break;
    case 303:
        month_number = 5;
        break;
    case 305:
        month_number = 6;
        break;
    case 308:   
        month_number = 7;
        break;  
    case 311:
        month_number = 8;
        break;
    case 313:   
        month_number = 9;
        break;
    case 316:
        month_number = 10;
        break;
    case 318:
        month_number = 11;
        break;
    case 321:
        month_number = 12;
        break;
    default:
        break;
    }
    return month_number;
}

void Month::setMonth(char month_letter_1, char month_letter_2, char month_letter_3)
{
    this->month_letter_1 = month_letter_1;
    this->month_letter_2 = month_letter_2;
    this->month_letter_3 = month_letter_3;
}

void Month::printMonth()
{
    cout << "month = " << month << endl;
}

void Month::printMonth(char month_letter_1, char month_letter_2, char month_letter_3)
{
    cout << "month = " << month_letter_1 << month_letter_2 << month_letter_3 << endl;
}

// Path: chapter7\projects\month\month.cpp


