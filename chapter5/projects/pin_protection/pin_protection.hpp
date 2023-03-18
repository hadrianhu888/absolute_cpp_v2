/**
 * @file pin_protection.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PIN_PROTECTION_HPP
#define PIN_PROTECTION_HPP



#ifdef __cplusplus

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <map>
#include <set>
#include <iterator>
#include <functional>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
#include <limits>
#include <typeinfo>
#include <stdexcept>
#include <exception>
#include <new>
#include <initializer_list>
#include <tuple>
#include <array>
#include <regex>
#include <chrono>
#include <random>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono; 

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);
std::uniform_int_distribution<int> distribution(1,100);

extern string PIN; 
extern int *pin; 
extern int *randomized_int_pin; 
extern int pin_length; 

int string2int(string str); 
string int2string(int num);
string obfuscate_pin(string pin);
string deobfuscate_pin(string pin);
void randomize_int_pin(int *pin);
int main_pin(int argc,char **argv); 

#endif // __cplusplus
#endif // PIN_PROTECTION_HPP