/**
 * @file p3.cpp
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

const double RETROACTIVE_SALARY_INCREASE = 1.076; 
const int MONTHS = 12; 

int main(int argc, char ** argv) {
    /**
     * @brief 
     * 
     */
    double lastYearSalary = 0.0; 
    double lastPayMonthlySalary = 0.0; 
    double newYearSalary = 0.0; 
    double newMonthlySalary = 0.0; 

    cout << "What is the yearly salary from last year? "; 
    cin >> lastYearSalary; 
    lastPayMonthlySalary = lastYearSalary / MONTHS; 
    newMonthlySalary = lastPayMonthlySalary * RETROACTIVE_SALARY_INCREASE; 
    newYearSalary = newMonthlySalary * MONTHS; 
    cout << "The new monthly and annual salaries of the employees will be: " << cout.precision(2) << newMonthlySalary << " per month and " << cout.precision(2) << newYearSalary << " per year." << endl << endl << endl; 

    return 0;
}


