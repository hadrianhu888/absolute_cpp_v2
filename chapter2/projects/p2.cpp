/**
 * @file p2.cpp
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
#include <cstdlib>
#include <cstdio>
#include <complex>

using namespace std; 

const int months = 12; 
const float percentConversion = 0.01; 

int main(int argc, char ** argv) {
    float payment = 0.0; 
    float monthlyPayment = 0.0; 
    float annualInterestRate = 0.0; 
    int months = 0; 
    float monthlyPayments = 0.0; 
    float monthlyInterestRate = 0.0; 
    float interestPaid = 0.0;
    float principalRemaining = 0.0; 
    cout << "Enter the principal, interest and months to pay off the payment: "; 
    cin >> payment; 
    cin >> annualInterestRate; 
    cin >> months; 
    monthlyInterestRate = float (annualInterestRate / months * percentConversion); 
    cout << "Monthly interest rate is: "  <<  monthlyInterestRate << endl; 
    monthlyPayments = payment / months; 
    cout << "Monthly amount is: " << monthlyPayments << endl; 
    while (payment > 0) {
        monthlyPayment = payment * monthlyInterestRate; 
        payment = payment - monthlyPayments; 
        cout << monthlyPayments;         
        cout << "\t" << payment << endl;
    }
    return 0; 
}