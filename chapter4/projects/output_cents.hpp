/**
 * @file output_cents.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef OUTPUT_CENTS_HPP
#define OUTPUT_CENTS_HPP

#ifdef __cplusplus

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Only returns cents between 1 cent and 99 cents using pennies, quarters and dimes.  
* No other denomination of coins are allowed, including half-dollars and nickels. 
 * 
 */

void computeCoin(int coinValue, int& number, int &amountLeft); 
void outputCents(int cents);
void outputDimes(int dimes);
void outputPennies(int pennies);
void outputQuarters(int quarters);
bool check_input_less_than_100(int cents);
int main(int argc, char const * argv[]);

#endif 
#endif 


