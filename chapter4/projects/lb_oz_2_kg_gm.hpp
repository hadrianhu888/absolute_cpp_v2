/**
 * @file lb_oz_2_kg_gm.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LB_OZ_2_KG_GM_HPP
#define LB_OZ_2_KG_GM_HPP

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
#include <vector>

#ifndef _MSC_VER
#include <unistd.h>
#endif

#define POUND_2_KG 0.45359237
#define KG_2_POUND 2.2046226218
#define GM_2_OUNCE 0.03527396195
#define OUNCE_2_GM 28.349523125
#endif

float pounds2kg(float pounds);
float kg2pounds(float kg);
float gm2ounce(float gm);
float ounce2gm(float ounce);
int main(int argc, char const *argv[]);

using namespace std;
#endif /*lb_oz_2_kg_gm.hpp*/
