/**
 * @file p11.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

const int seconds2HoursConversion = 3600; 
const int seconds2MinutesConversion = 60; 

int main(int argc, char ** argv) {
    /**
     * @brief initialize variables 
     * 
     */
    int givenSeconds = 0; 
    int hours = 0; 
    int minutes = 0; 
    int seconds = 0; 
    /**
     * @brief get user inputs 
     * 
     */
    cout << "Enter the given number of total seconds: "; 
    cin >> givenSeconds; \
    /**
     * @brief calculate the values 
     * 
     */
    hours = givenSeconds / seconds2HoursConversion; 
    minutes = givenSeconds % seconds2HoursConversion; 
    minutes = minutes / seconds2MinutesConversion; 
    seconds = minutes % seconds2MinutesConversion; 
    /**
     * @brief output 
     * 
     */
    cout << "The time in hours, minutes, seconds is: " << hours << " hours " << minutes << " min " << seconds << " sec." << endl;     
    return 0; 
}