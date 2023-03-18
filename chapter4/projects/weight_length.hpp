/**
 * @file weight_length.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WEIGHT_LENGTH_HPP
#define WEIGHT_LENGTH_HPP

#ifdef __cplusplus
#include "lb_oz_2_kg_gm.hpp"
#include "metric_imperial.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifndef _MSC_VER
#include <unistd.h>
#endif

using namespace std;
#endif

const int WEIGHT = 1;   // weight conversion choice
const int LENGTH = 2;   // length conversion choice
const int METRIC = 1;   // metric units choice
const int IMPERIAL = 2; // imperial units choice

int choice;   // user choice between weight and length conversion
char unit;    // user choice between metric and imperial units
float kg;     // kilograms
float gm;     // grams
float ounce;  // ounces
float pounds; // pounds
float meter;  // meters
float cm;     // centimeters
float inch;   // inches
float foot;   // feet

extern float pounds2kg(float pounds); // pounds to kilograms function prototype
extern float kg2pounds(float kg);     // kilograms to pounds function prototype
extern float gm2ounce(float gm);      // grams to ounces function prototype
extern float ounce2gm(float ounce);   // ounces to grams function prototype
extern float meter2cm(float meter); // meters to centimeters function prototype
extern float cm2meter(float cm);    // centimeters to meters function prototype
extern float inch2foot(float inch); // inches to feet function prototype
extern float foot2inch(float foot); // feet to inches function prototype

void show_menu(void);                 // show menu function prototype
void show_weight_menu(void);          // show weight menu function prototype
void show_length_menu(void);          // show length menu function prototype
void show_metric_menu(void);          // show metric menu function prototype
void show_imperial_menu(void);        // show imperial menu function prototype
int main_test(int argc, char **argv); // main function prototype

#endif