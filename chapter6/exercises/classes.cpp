/**
 * @file classes.cpp
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

class DayOfYear
{
    public:
        void input();
        void output();
        void set(int newMonth, int newDay);
        int getMonthNumber();
        int getDay();
    private:
        int month;
        int day;
};

class Temperature
{
    public:
        void setTemp(double newTemp);
        double getTemp();
        void setScale(char newScale);
        char getScale();
        void input();
        void output();
        void set(double newTemp, char newScale);
    private:
        double temp;
        char scale;
};

class Automobile
{
    public:
        void setMake(string newMake);
        string getMake();
        void setYear(int newYear);
        int getYear();
        void setSpeed(int newSpeed);
        int getSpeed();
        void accelerate();
        void brake();
        string make;
        int yearModel;
        int speed;
};

void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
}

void DayOfYear::output()
{
    cout << "month = " << month << ", day = " << day << endl;
}

void DayOfYear::set(int newMonth, int newDay)
{
    month = newMonth;
    day = newDay;
    switch(newMonth)
    {
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        case 12:
            cout << "December ";
            break;
        default:
            cout << "Error: Invalid month number.\n";
            break;
    }
    cout << newDay << endl;
    cout << "month = " << month << ", day = " << day << endl;
}

int DayOfYear::getMonthNumber()
{
    return month;
}

int DayOfYear::getDay()
{
    return day;
}

void Temperature::setTemp(double newTemp)
{
    temp = newTemp;
}

double Temperature::getTemp()
{
    return temp;
}

void Temperature::setScale(char newScale)
{
    scale = newScale;
}

char Temperature::getScale()
{
    return scale;
}

void Temperature::input()
{
    cout << "Enter the temperature: ";
    cin >> temp;
    cout << "Enter C for Celsius, or F for Fahrenheit: ";
    cin >> scale;
}

void Temperature::output()
{
    cout << "Temperature: " << temp << " degrees " << scale << endl;
}

void Temperature::set(double newTemp, char newScale)
{
    temp = newTemp;
    scale = newScale;
}

void Automobile::setMake(string newMake)
{
    make = newMake;
}

string Automobile::getMake()
{
    return make;
}

void Automobile::setYear(int newYear)
{
    yearModel = newYear;
}

int Automobile::getYear()
{
    return yearModel;
}

void Automobile::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

int Automobile::getSpeed()
{
    return speed;
}

void Automobile::accelerate()
{
    speed += 5;
}

void Automobile::brake()
{
    speed -= 5;
}

int main()
{
    DayOfYear today, bachBirthday;
    cout << "Enter today's date:\n";
    today.input();
    cout << "Today's date is ";
    today.output();
    bachBirthday.set(3, 21);
    cout << "J.S. Bach's birthday is ";
    bachBirthday.output();
    if (today.getMonthNumber() == bachBirthday.getMonthNumber() && today.getDay() == bachBirthday.getDay())
    {
        cout << "Happy Birthday Johann Sebastian!\n";
    }
    else
    {
        cout << "Happy Unbirthday Johann Sebastian!\n";
    }
    Temperature temp1, temp2;
    cout << "Enter the temperature:\n";
    temp1.input();
    cout << "Enter the temperature:\n";
    temp2.input();
    if (temp1.getTemp() == temp2.getTemp() && temp1.getScale() == temp2.getScale())
    {
        cout << "The temperatures are the same.\n";
    }
    else
    {
        cout << "The temperatures are not the same.\n";
    }
    cout << "Public and private members of the Temperature class are defined as follows:\n" << endl;
    cout << "Public members:\n" << endl;
    cout << "void setTemp(double newTemp);\n" << endl;
    cout << "double getTemp();\n" << endl;
    cout << "void setScale(char newScale);\n" << endl;
    cout << "char getScale();\n" << endl;
    cout << "void input();\n" << endl;
    cout << "void output();\n" << endl;
    cout << "void set(double newTemp, char newScale);\n" << endl;
    cout << "Private members:\n" << endl;
    cout << "double temp;\n" << endl;
    cout << "char scale;\n" << endl;
    Automobile car1, car2;
    cout << "Enter the make of the first car: ";
    cin >> car1.make;
    cout << "Enter the year of the first car: ";
    cin >> car1.yearModel;
    cout << "Enter the speed of the first car: ";
    cin >> car1.speed;
    cout << "Enter the make of the second car: ";
    cin >> car2.make;
    cout << "Enter the year of the second car: ";
    cin >> car2.yearModel;
    cout << "Enter the speed of the second car: ";
    cin >> car2.speed;
    cout << "Car 1: " << car1.make << " " << car1.yearModel << " " << car1.speed << endl;
    cout << "Car 2: " << car2.make << " " << car2.yearModel << " " << car2.speed << endl;
    car1.accelerate();
    car2.accelerate();
    cout << "Car 1: " << car1.make << " " << car1.yearModel << " " << car1.speed << endl;
    cout << "Car 2: " << car2.make << " " << car2.yearModel << " " << car2.speed << endl;
    return 0;
}

//member functions of a class are public. Memeber variables are private.
// Interface components are public. Implementation components are private.
// The interface is the part of the class that is visible to the user. The implementation is the part of the class that is not visible to the user.

/**
 * @brief     { function_description }
 * 
 */


