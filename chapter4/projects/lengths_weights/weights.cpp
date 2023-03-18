/**
 * @file weights.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "weights.hpp"
#include "common.hpp"

double pounds2kg(double pounds) { return pounds * POUNDS_KILOGRAMS; }

double kg2pounds(double kg) { return kg / POUNDS_KILOGRAMS; }

double gm2ounce(double gm) { return gm * GRAMS_OUNCES; }

double ounce2gm(double ounce) { return ounce / GRAMS_OUNCES; }
