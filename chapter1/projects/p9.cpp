/**
 * @file p9.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <cmath>
#include <string> 
#include <stdio.h>
#include <cstdlib>

/**
 * @brief namespaces and defines, universal and global variables, function, methods, classes, structures, enums, and others as needed 
 * 
 */

using namespace std; 

/**
 * @brief main function
 * 
 */

const int candyBars = 10; 
const int gumballs = 3; 

int main(int argc, char ** argv) {
    /**
     * @brief initialize variables 
     * 
     */
    int totalcoupons = 0; 
    int candyBarsAvailable = 0; 
    int gumballsAvailable = 0; 
    int remainingCoupons = 0; 
    cout << "Enter how many total coupons you have: "; 
    cin >> totalcoupons;
    /**
     * @brief calculate candy bars and gumballs available with given coupon numbers 
     * 
     */
    candyBarsAvailable = totalcoupons / candyBars; 
    remainingCoupons = totalcoupons % candyBars; 
    gumballsAvailable = remainingCoupons / gumballs; 
    cout << "Candy Bars: " << candyBarsAvailable << endl; 
    cout << "Gumballs: " << gumballsAvailable << endl; 
    return 0; 
}