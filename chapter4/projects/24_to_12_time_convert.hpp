/**
 * @file 24_to_12_time_convert.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __24_TO_12_TIME_CONVERT_HPP__
#define __24_TO_12_TIME_CONVERT_HPP__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

char recognize_am_pm(int hour);
void convert_24_to_12(int hour, int minute, int second, char am_pm);
int main(int argc, char** argv);

#endif // __24_TO_12_TIME_CONVERT_HPP__