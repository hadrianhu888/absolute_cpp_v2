/**
 * @file p1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>
#include <cstring>

using namespace std; 

const double LiterToGallon = 0.264179;
const double KmToMiles = 1/1.60934;

double fuelEfficiency (double distance, double gas) {
    return (distance / gas); 
}

int main (int argc, char ** argv) {
    double distance = 0.0; 
    double gas = 0.0;
    bool continueProgram = true; 
    double MilesPerGallon = 0.0; 
    cout << "What is the distance traveled and the gas used [km and liters]: ";     
    cin >> distance; 
    cin >> gas;
    distance = distance * KmToMiles; 
    gas = gas * LiterToGallon; 
    MilesPerGallon = fuelEfficiency(distance, gas);
    cout << "The car has a fuel efficiency of " << MilesPerGallon << " miles per gallon ";
    cout << " for a distance of " << distance << " miles " << " and gas useage of "; 
    cout << gas << " gallons of gas. " << endl; 
    return 0;
}