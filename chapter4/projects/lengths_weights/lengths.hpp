/**
 * @file lengths.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LENGTHS_HPP
#define LENGTHS_HPP

#ifdef __cplusplus

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define FEET_METERS 0.3048
#define INCHES_FEET 0.0833333
#define INCHES_METERS 0.0254
#define CENTIMETERS_INCHES 0.393701
#define CENTIMETERS_FEET 0.0328084

double feet;
double inches;
double meters;
double centimeters;

double feet2meters(double feet);
double meters2feet(double meters);
double inches2meters(double inches);
double meters2inches(double meters);

#endif
#endif /* LENGTHS_HPP */