/**
 * @file weights.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WEIGHTS_HPP
#define WEIGHTS_HPP

#include "common.hpp"

#define POUNDS_KILOGRAMS 0.453592
#define OUNCES_KILOGRAMS 0.0283495
#define OUNCES_GRAMS 28.3495
#define GRAMS_OUNCES 0.035274

double pounds;
double kilograms;
double ounces;
double grams;

double pounds2kg(double pounds);
double kg2pounds(double kg);
double gm2ounce(double gm);
double ounce2gm(double ounce);

#endif /* WEIGHTS_HPP */