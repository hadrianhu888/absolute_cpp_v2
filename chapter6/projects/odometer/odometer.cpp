/**
 * @file odometer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Odometer
{
    private:
        int miles;
        int gallons;
        float mpg;
    public:
        Odometer();
        Odometer(int newMiles, int newGallons);
        void setMiles(int newMiles);
        void setGallons(int newGallons);
        int getMiles();
        int getGallons();
        float getMPG();
        float resetMPG();
        void print();
        Odometer creator();
        Odometer destructor();
}; 

Odometer::Odometer()
{
    miles = 0;
    gallons = 0;
    mpg = 0;
}

Odometer::Odometer(int newMiles, int newGallons)
{
    miles = newMiles;
    gallons = newGallons;
    mpg = miles / gallons;
}

void Odometer::setMiles(int newMiles)
{
    miles = newMiles;
}

void Odometer::setGallons(int newGallons)
{
    gallons = newGallons;
}

int Odometer::getMiles()
{
    return miles;
}

int Odometer::getGallons()
{
    return gallons;
}

float Odometer::getMPG()
{
    return miles / gallons;
}

float Odometer::resetMPG()
{
    miles = 0;
    gallons = 0;
    return mpg = 0;
}

void Odometer::print()
{
    cout << "Miles: " << miles << endl;
    cout << "Gallons: " << gallons << endl;
    cout << "MPG: " << mpg << endl;
}

Odometer Odometer::creator()
{
    Odometer car1;
    return car1;
}

Odometer Odometer::destructor()
{
    Odometer car1;
    return car1;
}

int main()
{
    Odometer car1;
    Odometer car2(100, 10);
    car1.setMiles(200);
    car1.setGallons(20);
    car1.print();
    car2.print();
    cout << "Resetting car1" << endl;
    car1.resetMPG();
    car1.print();
    return 0;
}