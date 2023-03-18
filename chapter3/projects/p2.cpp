/**
 * @file p2.cpp
 * @author hadrian (hadrian.hu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief inflation rate calculator 
 * 
 */

#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <math.h> 

using namespace std; 

int main (int argc, char ** argv); 
double calculateInflationRate(double presentValue, double pastValue); 
double calculatePriceFromInflationRateInXYears(int years, double price, double inflationRate); 

double calculateInflationRate(double presentValue, double pastValue) 
{
    return ((presentValue - pastValue) / pastValue) * 100; 
}

double calculatePriceFromInflationRateInXYears(int years, double price, double inflationRate)
{
    return (price * pow((1+inflationRate/100), years)); 
}

int main (int argc, char ** argv) 
{
    double presentValue = 0.0; 
    double pastValue = 0.0; 
    double inflation = 0.0; 
    double price = 0.0; 
    double currentInflationRate = 0.0; 
    double futurePrice = 0.0; 
    int years = 0; 
    cout << "What is the present value? "; 
    cin >> presentValue; 
    cout << endl << "What is the past value? "; 
    cin >> pastValue; 
    /**
     * @brief calculate inflation rate 
     * 
     */
    inflation = calculateInflationRate(fabs(presentValue),fabs(pastValue)); 
    cout << "The inflation rate is at " << inflation << "% based on last years' values" << endl; 
    cout << endl << "Enter the number of years to project the price of an item: ";
    cin >> years; 
    cout << endl << "Enter the current price of an item: "; 
    cin >> price; 
    cout << endl << "Enter the current inflation rate: "; 
    cin >> currentInflationRate; 
    /**
     * @brief calculate future cost based on current inflation rate, item price and years forward in time
     * 
     */
    futurePrice = calculatePriceFromInflationRateInXYears(years, price, currentInflationRate); 
    cout << "The cost of the item in " << years << " years with "; 
    cout << currentInflationRate << " inflation rate is " << futurePrice << endl; 
    return 0;
}