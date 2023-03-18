/**
 * @file convert2mph.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>

using namespace std;
using namespace std::chrono;

#define KPH_TO_MPH 0.621371

#define MPH_TO_KPH 0.304873

#define MPH_TO_MPH_PER_HOUR (MPH_TO_KPH / 3600)
#define MPH_TO_KPH_PER_HOUR (KPH_TO_MPH / 3600)
/**
 * @brief 
 * Convert a speed in kilometers per hour to miles per hour
 * @param kph 
 * @return double 
 */

double convert_minute_to_mph(double minute); 
double convert_second_to_mph(double second);
int main(int argc, char **argv); 

double convert_minute_to_mph(double minute)
{
    double mph = 0.0;
    mph = 1.0 / minute;
    return mph;
}

double convert_second_to_mph(double second)
{
    double mph = 0.0;
    mph = 1.0 / second;
    return mph;
}

int main(int argc, char **argv)
{
    double minute = 0.0;
    double second = 0.0;
    double mph = 0.0;
    cout << "Enter the speed in minutes: ";
    cin >> minute;
    cout << "Enter the speed in seconds: ";
    cin >> second;
    mph = convert_minute_to_mph(minute);
    cout << "The speed in miles per hour is: " << mph << endl;
    mph = convert_second_to_mph(second);
    cout << "The speed in miles per hour is: " << mph << endl;
    /**
     * @brief convert to mph and kph from minutes and seconds 
     * 
     */
    cout << "The speed in miles per hour is: " << convert_minute_to_mph(minute) << endl;
    cout << "The speed in miles per hour is: " << convert_second_to_mph(second) << endl;
    return 0;
}

