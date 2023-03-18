/**
 * @file p1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <assert.h>

using namespace std; 

float calculateInflation(void);
float customPowerFunction(float base, int p);
float calculateInflation(float price, float interest, int years); 
/**
 * @brief 
 * 
 * @param base 
 * @param p 
 * @return float 
 */
float customPowerFunction(float base, int p) {
    float power = 1; 
    if (p == 0 ) {
        power = 1; 
    } else if (p == 1) {
        power = base; 
    } else {
        for (int i = p; i >= 1; i--) {
            power = base * customPowerFunction(base, i-1); 
        }
    }
    return power; 
}
/**
 * @brief 
 * 
 * @param price 
 * @param interest 
 * @param years 
 * @return float 
 */
float calculateInflation(float price, float interest, int years) {
    float inflationaryPrice = price * pow((1 + interest / 100),years);
    cout << "The price after " << years << " years at an inflation rate of " << interest << "per cent per year is " << inflationaryPrice << endl;  
    return inflationaryPrice; 
} 

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char ** argv) {
    float price = 0.0;
    float interest = 0.0;
    int years = 0;
    cout << "Enter initial price: "; 
    cin >> price; 
    cout << endl << "Enter the inflation rate: "; 
    cin >> interest; 
    cout << endl << "Enter the number of years: "; 
    cin >> years; 
    float inflationValue = 0.0; 
    inflationValue = calculateInflation(price, interest, years); 
    return 0;
}