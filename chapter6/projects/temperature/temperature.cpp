/**
 * @file temperature.cpp
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

class Temperature
{
    private:
        int fahrenheit;
        int celsius;
    public:
        Temperature();
        Temperature(int newFahrenheit, int newCelsius);
        void setFahrenheit(int newFahrenheit);
        void setCelsius(int newCelsius);
        int getFahrenheit();
        int getCelsius();
        double convertFahrenheitToCelsius();
        double convertCelsiusToFahrenheit();
        void print();
        Temperature creator();
        Temperature destructor();
};

int main(int argc, char **argv); 

Temperature::Temperature()
{
    fahrenheit = 0;
    celsius = 0;
}

Temperature::Temperature(int newFahrenheit, int newCelsius)
{
    fahrenheit = newFahrenheit;
    celsius = newCelsius;
}

void Temperature::setFahrenheit(int newFahrenheit)
{
    fahrenheit = newFahrenheit;
}

void Temperature::setCelsius(int newCelsius)
{
    celsius = newCelsius;
}

int Temperature::getFahrenheit()
{
    return fahrenheit;
}

int Temperature::getCelsius()
{
    return celsius;
}

double Temperature::convertFahrenheitToCelsius()
{
    return (fahrenheit - 32) * 5 / 9;
}

double Temperature::convertCelsiusToFahrenheit()
{
    return (celsius * 9 / 5) + 32;
}

void Temperature::print()
{
    cout << "Fahrenheit: " << fahrenheit << endl;
    cout << "Celsius: " << celsius << endl;
}

Temperature Temperature::creator()
{
    Temperature temp;
    return temp;
}

Temperature Temperature::destructor()
{
    Temperature temp;
    return temp;
}

int main(int argc, char **argv)
{
    Temperature temp;
    temp.setFahrenheit(212);
    temp.setCelsius(100);
    temp.print();
    cout << "Fahrenheit to Celsius: " << temp.convertFahrenheitToCelsius() << " Celsius" << endl;
    cout << "Celsius to Fahrenheit: " << temp.convertCelsiusToFahrenheit() << " Fahrenheit" << endl;
    temp.destructor();
    return 0;
}
