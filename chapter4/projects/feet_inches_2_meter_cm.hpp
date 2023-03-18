/**
 * @file feet2inches.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __FEET_INCHES_2_METER_CM_HPP__
#define __FEET_INCHES_2_METER_CM_HPP__

#ifdef __cplusplus

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int feet;
int inches;
int meters;
int centimeters;

#define INCHES_PER_FOOT 12
#define INCHES_PER_YARD 36
#define INCHES_PER_MILE 63360

#define INCH_2_METER 0.0254
#define INCH_2_CENTIMETER 2.54

#define METER_2_INCH 39.37
#define METER_2_CENTIMETER 100

#define CENTIMETER_2_INCH 0.3937

double feet2inches(double feet);
double inches2meters(double inches);
double inches2centimers(double inches);
double meters2inches(double meters);
double centimeters2inches(double centimeters);
/**
 * @brief Also check if the user enters an inch value greater than a foot. If
 * greater, then add to the original measurement in feet and inches. Return this
 * value to the user.
 *
 * @param argc
 * @param argv
 * @return int
 */
double check_total_measurement_feet_inches(double feet, double inches);
int main(int argc, char const *argv[]);

#endif
#endif
