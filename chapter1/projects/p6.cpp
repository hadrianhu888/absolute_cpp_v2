#include <iostream> 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib> 

using namespace std; 

const double payRate = 16.78; 
const double overTime = 1.5; 
const double socialSecurity = 0.06; 
const double federalIncomeTax = 0.14;
const double stateincomeTax = 0.05; 
const double unionDues = 10.00; 
const double dependentsCosts = 35.00; 
const int standardHoursPerWeek = 40;  
const int minDependentsBeforeDeductions = 3; 

int main(int argc, char ** argv) {  
    /**
     * @brief initialize variables 
     * 
     */
    int numberofDependents = 0; 
    int hoursWorkedPerWeek = 0; 
    double grossPay = 0.0; 
    double totalDeductions = 0.0; 
    double netPay = 0.0; 
    /**
     * @brief get inputs 
     * 
     */
    cout <<  "Enter the number of hours worked this week: "; 
    cin >> hoursWorkedPerWeek; 
    cout << endl << "Enter the number of dependents: "; 
    cin >> numberofDependents;
    /**
     * @brief > and > case 
     * 
     */
    if ((numberofDependents > minDependentsBeforeDeductions) && (hoursWorkedPerWeek > standardHoursPerWeek)) {
        grossPay = standardHoursPerWeek * payRate + (hoursWorkedPerWeek - standardHoursPerWeek) * payRate * overTime; 
        totalDeductions = dependentsCosts + (socialSecurity + stateincomeTax + federalIncomeTax) * grossPay + unionDues; 
        netPay = grossPay - totalDeductions; 
        /**
         * @brief < and > case 
         * 
         */
    } else if ((numberofDependents < minDependentsBeforeDeductions) && (hoursWorkedPerWeek > standardHoursPerWeek)) {
        grossPay = standardHoursPerWeek * payRate + (hoursWorkedPerWeek - standardHoursPerWeek) * payRate * overTime; 
        totalDeductions = (socialSecurity + stateincomeTax + federalIncomeTax) * grossPay + unionDues; 
        netPay = grossPay - totalDeductions; 
        /**
         * @brief < and < case 
         * 
         */
    } else if ((numberofDependents < minDependentsBeforeDeductions) && (hoursWorkedPerWeek < standardHoursPerWeek)) {
        grossPay = standardHoursPerWeek * payRate; 
        totalDeductions = (socialSecurity + stateincomeTax + federalIncomeTax) * grossPay + unionDues; 
        netPay = grossPay - totalDeductions;
        /**
         * @brief > and < case 
         * 
         */
    } else if ((numberofDependents > minDependentsBeforeDeductions) && (hoursWorkedPerWeek < standardHoursPerWeek)) {
        grossPay = standardHoursPerWeek * payRate; 
        totalDeductions = dependentsCosts + (socialSecurity + stateincomeTax + federalIncomeTax) * grossPay + unionDues; 
        netPay = grossPay - totalDeductions; 
    } 
    /**
     * @brief print out the results 
     * 
     */
    cout << "Gross Pay: $"; 
    cout << grossPay << endl; 
    cout << "Deductions: $"; 
    cout << totalDeductions << endl; 
    cout << "Net Pay: $"; 
    cout << netPay << endl;
    return 0; 
}