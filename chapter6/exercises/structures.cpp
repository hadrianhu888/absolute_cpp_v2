/**
 * @file structures.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "F:/GitHubRepos/absolute_cpp/common.hpp"

typedef struct CDAccountV1
{
    double balance; 
    double interest_rate;
    int term; 
} Account; 

typedef struct FertilizerStock
{
    double quantity; 
    double nitrogen_content; 
} Fertilizer;

typedef struct CropYield
{
    double quantity; 
    double nitrogen_content; 
} Crop;

typedef struct StudentRecord
{
    string name; 
    int id; 
    double gpa; 
    char grade; 
} Student;

typedef struct Automobile
{
    string make; 
    string model; 
    int year; 
    double price; 
} Automobile; 

typedef struct WeatherData
{
    double temperature; 
    double humidity; 
    double wind_speed; 
    double wind_direction; 
} Weather;

typedef struct Date
{
    int month; 
    int day; 
    int year; 
} Date;

typedef struct PErsonaInfo
{
    string name; 
    string address; 
    string phone_number; 
    string email_address; 
} Person;

int main(int argc, char **argv);
void getAccountData(Account &account);
void getFertilizerData(Fertilizer &fertilizer);
void getCropData(Crop &crop);
void getStudentData(Student &student);
void getAutomobileData(Automobile &automobile);
void getWeatherData(Weather &weather);
void getDateData(Date &date);
void getPersonData(Person &person);
Account getAccountData(void);
Fertilizer getFertilizerData(void);
Crop getCropData(void);
Student getStudentData(void);
Automobile getAutomobileData(void);
Weather getWeatherData(void);
Date getDateData(void);
Person getPersonData(void);

Account getAccountData(void)
{
    Account account;
    cout << "Enter the account balance: ";
    cin >> account.balance;
    cout << "Enter the interest rate: ";
    cin >> account.interest_rate;
    cout << "Enter the term: ";
    cin >> account.term;
    return account;
}

Fertilizer getFertilizerData(void)
{
    Fertilizer fertilizer;
    cout << "Enter the fertilizer quantity: ";
    cin >> fertilizer.quantity;
    cout << "Enter the fertilizer nitrogen content: ";
    cin >> fertilizer.nitrogen_content;
    return fertilizer;
}

Crop getCropData(void)
{
    Crop crop;
    cout << "Enter the crop quantity: ";
    cin >> crop.quantity;
    cout << "Enter the crop nitrogen content: ";
    cin >> crop.nitrogen_content;
    return crop;
}

Student getStudentData(void)
{
    Student student;
    cout << "Enter the student name: ";
    cin >> student.name;
    cout << "Enter the student id: ";
    cin >> student.id;
    cout << "Enter the student gpa: ";
    cin >> student.gpa;
    cout << "Enter the student grade: ";
    cin >> student.grade;
    return student;
}

Automobile getAutomobileData(void)
{
    Automobile automobile;
    cout << "Enter the automobile make: ";
    cin >> automobile.make;
    cout << "Enter the automobile model: ";
    cin >> automobile.model;
    cout << "Enter the automobile year: ";
    cin >> automobile.year;
    cout << "Enter the automobile price: ";
    cin >> automobile.price;
    return automobile;
}

Weather getWeatherData(void)
{
    Weather weather;
    cout << "Enter the temperature: ";
    cin >> weather.temperature;
    cout << "Enter the humidity: ";
    cin >> weather.humidity;
    cout << "Enter the wind speed: ";
    cin >> weather.wind_speed;
    cout << "Enter the wind direction: ";
    cin >> weather.wind_direction;
    return weather;
}

Date getDateData(void)
{
    Date date;
    cout << "Enter the month: ";
    cin >> date.month;
    cout << "Enter the day: ";
    cin >> date.day;
    cout << "Enter the year: ";
    cin >> date.year;
    return date;
}

Person getPersonData(void)
{
    Person person;
    cout << "Enter the person name: ";
    cin >> person.name;
    cout << "Enter the person address: ";
    cin >> person.address;
    cout << "Enter the person phone number: ";
    cin >> person.phone_number;
    cout << "Enter the person email address: ";
    cin >> person.email_address;
    return person;
}

void getPersonData(Person &person)
{
    cout << "Enter the person name: ";
    cin >> person.name;
    cout << "Enter the person address: ";
    cin >> person.address;
    cout << "Enter the person phone number: ";
    cin >> person.phone_number;
    cout << "Enter the person email address: ";
    cin >> person.email_address;
}


void getAccountData(Account &account)
{
    cout << "Enter the account balance: ";
    cin >> account.balance;
    cout << "Enter the interest rate: ";
    cin >> account.interest_rate;
    cout << "Enter the term: ";
    cin >> account.term;
}

void getFertilizerData(Fertilizer &fertilizer)
{
    cout << "Enter the fertilizer quantity: ";
    cin >> fertilizer.quantity;
    cout << "Enter the fertilizer nitrogen content: ";
    cin >> fertilizer.nitrogen_content;
}

void getCropData(Crop &crop)
{
    cout << "Enter the crop quantity: ";
    cin >> crop.quantity;
    cout << "Enter the crop nitrogen content: ";
    cin >> crop.nitrogen_content;
}

void getStudentData(Student &student)
{
    cout << "Enter the student name: ";
    cin >> student.name;
    cout << "Enter the student id: ";
    cin >> student.id;
    cout << "Enter the student gpa: ";
    cin >> student.gpa;
    cout << "Enter the student grade: ";
    cin >> student.grade;
}

void getAutomobileData(Automobile &automobile)
{
    cout << "Enter the automobile make: ";
    cin >> automobile.make;
    cout << "Enter the automobile model: ";
    cin >> automobile.model;
    cout << "Enter the automobile year: ";
    cin >> automobile.year;
    cout << "Enter the automobile price: ";
    cin >> automobile.price;
}

void getWeatherData(Weather &weather)
{
    cout << "Enter the temperature: ";
    cin >> weather.temperature;
    cout << "Enter the humidity: ";
    cin >> weather.humidity;
    cout << "Enter the wind speed: ";
    cin >> weather.wind_speed;
    cout << "Enter the wind direction: ";
    cin >> weather.wind_direction;
}

void getDateData(Date &date)
{
    cout << "Enter the month: ";
    cin >> date.month;
    cout << "Enter the day: ";
    cin >> date.day;
    cout << "Enter the year: ";
    cin >> date.year;
}

int main(int argc, char **argv)
{
    Account account;
    getAccountData(account);
    cout << "The account balance is: " << account.balance << endl;
    cout << "The interest rate is: " << account.interest_rate << endl;
    cout << "The term is: " << account.term << endl;
    /**
     * @brief test the other structures with a basic input and output 
     * 
     */
    Fertilizer fertilizer;
    getFertilizerData(fertilizer);
    // cout << "The fertilizer quantity is: " << fertilizer.quantity << endl;
    cout << "The fertilizer nitrogen content is: " << fertilizer.nitrogen_content << endl;
    Crop crop;
    getCropData(crop);
    cout << "The crop quantity is: " << crop.quantity << endl;
    cout << "The crop nitrogen content is: " << crop.nitrogen_content << endl;
    Student student;
    getStudentData(student);
    cout << "The student name is: " << student.name << endl;
    cout << "The student id is: " << student.id << endl;
    cout << "The student gpa is: " << student.gpa << endl;
    cout << "The student grade is: " << student.grade << endl;
    Automobile automobile;
    getAutomobileData(automobile);
    cout << "The automobile make is: " << automobile.make << endl;
    cout << "The automobile model is: " << automobile.model << endl;
    cout << "The automobile year is: " << automobile.year << endl;
    cout << "The automobile price is: " << automobile.price << endl;
    Weather weather;
    getWeatherData(weather);
    cout << "The temperature is: " << weather.temperature << endl;
    cout << "The humidity is: " << weather.humidity << endl;
    cout << "The wind speed is: " << weather.wind_speed << endl;
    cout << "The wind direction is: " << weather.wind_direction << endl;
    Date date;
    getDateData(date);
    cout << "The month is: " << date.month << endl;
    cout << "The day is: " << date.day << endl;
    // cout << "The year is: " << date.year << endl;
    /**
     * @brief test the other structures-based functions with a basic input and output
     * 
     */
    Person person;
    getPersonData(person);
    cout << "The person name is: " << person.name << endl;
    cout << "The person address is: " << person.address << endl;
    cout << "The person phone number is: " << person.phone_number << endl;
    cout << "The person email address is: " << person.email_address << endl;
    /**
     * @brief test the void functions with a basic input and output
     * 
     */
    Account account1;
    getAccountData(account1);
    cout << "The account balance is: " << account1.balance << endl;
    cout << "The interest rate is: " << account1.interest_rate << endl;
    cout << "The term is: " << account1.term << endl;
    Fertilizer fertilizer1;
    getFertilizerData(fertilizer1);
    cout << "The fertilizer quantity is: " << fertilizer1.quantity << endl;
    cout << "The fertilizer nitrogen content is: " << fertilizer1.nitrogen_content << endl;
    Crop crop1;
    getCropData(crop1);
    cout << "The crop quantity is: " << crop1.quantity << endl;
    cout << "The crop nitrogen content is: " << crop1.nitrogen_content << endl;
    Student student1;
    getStudentData(student1);
    cout << "The student name is: " << student1.name << endl;
    cout << "The student id is: " << student1.id << endl;
    cout << "The student gpa is: " << student1.gpa << endl;
    cout << "The student grade is: " << student1.grade << endl;
    Automobile automobile1;
    getAutomobileData(automobile1);
    cout << "The automobile make is: " << automobile1.make << endl;
    cout << "The automobile model is: " << automobile1.model << endl;
    cout << "The automobile year is: " << automobile1.year << endl;
    cout << "The automobile price is: " << automobile1.price << endl;
    Weather weather1;
    getWeatherData(weather1);
    cout << "The temperature is: " << weather1.temperature << endl;
    cout << "The humidity is: " << weather1.humidity << endl;
    cout << "The wind speed is: " << weather1.wind_speed << endl;
    cout << "The wind direction is: " << weather1.wind_direction << endl;
    Date date1;
    getDateData(date1);
    cout << "The month is: " << date1.month << endl;
    cout << "The day is: " << date1.day << endl;
    cout << "The year is: " << date1.year << endl;
    Person person1;
    getPersonData(person1);
    cout << "The person name is: " << person1.name << endl;
    cout << "The person address is: " << person1.address << endl;
    cout << "The person phone number is: " << person1.phone_number << endl;
    cout << "The person email address is: " << person1.email_address << endl;
    return 0;
}

