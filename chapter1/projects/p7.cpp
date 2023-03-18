/**
 * @file p7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib> 

using namespace std; 

const double lbToKgConversion = 2.2; 
const double formulaConstant = 0.0175; 

enum activities {
    /**
     * @brief enumerate activities 
     * 
     */
    sleeping = 1,
    running = 10,
    basketball = 8
}; 

int main(int argc, char ** argv) {  
    /**
     * @brief initialize variables 
     * 
     */
    int minutes = 0; 
    double weightInLbs = 0.0; 
    double weightInKgs = 0.0; 
    double caloriesBurned = 0.0; 
    int activity = 0; 
    int mep = 0; 
    /**
     * @brief get inputs 
     * 
     */
    cout << "What is the activity? [1 - sleeping, 2 - running, 3 - basketball] "; 
    cin >> activity; 
    switch(activity) {
        case 1: {
            mep = 1;             
            break; 
        } case 2: {
            mep = 10;             
            break; 
        } case 3: {
            mep = 8;             
            break; 
        } default: {
            mep = 0;            
            break; 
        }
    }
    cout << endl << "How many minutes were spent in this activity? "; 
    cin >> minutes;
    cout << endl << "What is your weight in lbs? "; 
    cin >> weightInLbs; 
    /**
     * @brief convert to kgs 
     * 
     */
    weightInKgs = weightInLbs / lbToKgConversion; 
    /**
     * @brief calculate calories 
     * 
     */
    caloriesBurned = minutes * formulaConstant * mep * weightInKgs; 
    cout << "The total calories burnt is: " << caloriesBurned << " calories." << endl; 
    return 0; 
}


