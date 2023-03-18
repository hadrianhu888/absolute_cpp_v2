/**
 * @file p4.cpp
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
#include <math.h>
#include <cmath> 

using namespace std; 

const int MONTHS = 12; 

int main(int argc, char ** argv) {
    /**
     * @brief 
     * 
     */
    double interest = 0.0; 
    double interestRate = 0.0; 
    double consumerAmount = 0.0; 
    int months = 0; 
    int years = 0; 
    double monthlyPayments = 0.0; 
    double deduction = 0.0; 
    double principalAmount = 0.0; 
    cout << "Enter the amount the consumer needs: "; 
    cin >> consumerAmount; 
    cout << endl << "Enter the interest rate: "; 
    cin >> interest; 
    interest = interest / 100; 
    cout << endl << "Enter the number of months: "; 
    cin >> months; 
    years = months / MONTHS; 
    interestRate = interest / MONTHS; 
    principalAmount = consumerAmount / (1 - interestRate * years); 
    monthlyPayments = principalAmount / months; 
    cout << "Principal Amount : $" << principalAmount << endl; 
    cout << "Monthly Payment: $" << monthlyPayments << endl; 
    return 0;
}




