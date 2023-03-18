/**
 * @file lengths.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "lengths.hpp"
#include "common.hpp"

double feet2meters(double feet) { return feet * FEET_METERS; }

double meters2feet(double meters) { return meters / FEET_METERS; }

double inches2meters(double inches) { return inches * INCHES_METERS; }

double meters2inches(double meters) { return meters / INCHES_METERS; }
