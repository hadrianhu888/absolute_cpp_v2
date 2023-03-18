/**
 * @file metric_imperial.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef METRIC_IMPERIAL_HPP
#define METRIC_IMPERIAL_HPP

#pragma once 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring> 

using namespace std;

#define INCHES_PER_FOOT 12
#define INCH_2_METER 0.0254
#define INCH_2_CENTIMETER 2.54
#define METER_2_INCH 39.37
#define CENTIMETER_2_INCH 0.3937

/**
 * @brief converts feet and inches to meters and centimeters. 
    Do this repeatedly until the user enters 0 feet and 0 inches.
    Also convert from meters and centimeters to feet and inches.s
    Ask the user continuously for input between metric and imperial until the user enters a negative number. 
 * 
 */

double feet;
double inches; 
double meters;
double centimeters;
double total_inches;
double total_feet;
double total_meters;
double total_centimeters;

double feet2inches(double feet); 
double inches2meters(double inches);
double inches2centimeters(double inches);
double meters2inches(double meters);
double centimeters2inches(double centimeters);
double centimeter2meter(double centimeters);
double meter2centimeter(double meters);
double check_total_measurement_feet_inches(double feet, double inches);
double check_total_measurement_meter_centimeter(double meters, double centimeters);
void display_menu(void);
void display_metric_imperial_menu(void);
void display_imperial_to_metric_menu(void);
char get_user_choice(void);
double imperial_to_metric(char);
double metric_to_imperial(char);
int main(int argc, char const *argv[]);

#endif // METRIC_IMPERIAL_HPP