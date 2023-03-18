/**
 * @file ex6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <cstdio> 

using namespace std; 

int main(int argc, char ** argv) {
    /**
     * @brief 
     * 
     */
    int divisor = 0; 
    int divident = 0; 
    int quotient = 0; 
    int remainder = 0; 
    cout << "Enter the divisor and dividend: "; 
    cin >> divisor; 
    cin >> divident; 
    quotient = divisor / divident; 
    remainder = divisor % divident; 
    cout << "The quotient and remainder are: " << quotient  << " and " << remainder << endl; 
    return 0;
}

