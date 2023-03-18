/**
 * @file ex6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std; 

int main(int argc, char ** argv) {
    int savings = 0; 
    int expenses = 0; 
    if (savings >= expenses) {
        savings -= expenses; 
        expenses = 0; 
    } else if (savings < expenses) {
        savings = savings; 
        expenses = expenses; 
    }
    cout << savings << endl << expenses << endl;
    return 0; 
}