/**
 * @file DayofYear.cpp
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

class DayofYear
{
    private:
        int day;
        int month;
        int year;
    public:
        DayofYear();
        DayofYear(int newDay, int newMonth);
        DayofYear(int newDay, int newMonth, int newYear);
        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear);
        int getDay() {return day;}
        int getMonth() {return month;}
        int getYear();
        void print();
        DayofYear creator();
        DayofYear destructor();
};

class Holiday: public DayofYear
{
    private:
        string holidayName;
        bool isHoliday;
        int day;
        int month;
        int year;
    public:
        Holiday();
        Holiday(int newDay, int newMonth, int newYear, string newHolidayName, bool isHoliday);
        Holiday(string newHolidayName);
        void setHolidayName(string newHolidayName);
        string getHolidayName();
        void print();
        Holiday creator();
        Holiday destructor();
};

int day;
int month;
int year;

int main(int argc, char **argv);

DayofYear::DayofYear()
{
    day = 0;
    month = 0;
    year = 0;
}

DayofYear::DayofYear(int newDay, int newMonth)
{
    day = newDay;
    month = newMonth;
    year = 0;
}

DayofYear::DayofYear(int newDay, int newMonth, int newYear)
{
    day = newDay;
    month = newMonth;
    year = newYear;
}

void DayofYear::setDay(int newDay)
{
    day = newDay;
}

void DayofYear::setMonth(int newMonth)
{
    month = newMonth;
}

void DayofYear::setYear(int newYear)
{
    year = newYear;
}

int DayofYear::getYear()
{
    return year;
}

void DayofYear::print()
{
    cout << "The date is " << month << "/" << day << "/" << year << endl;
}

DayofYear DayofYear::creator()
{
    DayofYear temp;
    return temp;
}

DayofYear DayofYear::destructor()
{
    DayofYear temp;
    return temp;
}

Holiday::Holiday()
{
    holidayName = "";
    isHoliday = false;
}

Holiday::Holiday(int newDay, int newMonth, int newYear, string newHolidayName, bool isHoliday)
{
    day = newDay;
    month = newMonth;
    year = newYear;
    holidayName = newHolidayName;
    isHoliday = isHoliday;
}

Holiday::Holiday(string newHolidayName)
{
    holidayName = newHolidayName;
    isHoliday = false;
}

void Holiday::setHolidayName(string newHolidayName)
{
    holidayName = newHolidayName;
}

string Holiday::getHolidayName()
{
    return holidayName;
}

void Holiday::print()
{
    cout << "The date is " << month << "/" << day << "/" << year << endl;
    cout << "The holiday is " << holidayName << endl;
}

Holiday Holiday::creator()
{
    Holiday temp;
    return temp;
}

Holiday Holiday::destructor()
{
    Holiday temp;
    return temp;
}

int main(int argc, char **argv)
{
    DayofYear today;
    today.setDay(8);
    today.setMonth(3);
    today.setYear(2023);
    /**
     * @brief test holiday class
     * 
     */
    Holiday todayHoliday;
    todayHoliday.setDay(8);
    todayHoliday.setMonth(3);
    todayHoliday.setYear(2023);
    todayHoliday.setHolidayName("My Birthday");
    todayHoliday.print();
    /**
     * @brief test holiday class
     * 
     */
    today.print();
    return 0;
}

