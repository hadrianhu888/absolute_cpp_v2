/**
 * @file p7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>

const float percentage = 100.00; 

using namespace std; 

int main (int argc, char ** argv) {
    int i = 0; 
    int exercises = 0; 
    int earned = 0; 
    int total = 0;
    float average = 0.0; 
    cout << "Enter the number of exercises: "; 
    cin >> exercises; 
    for (i = 0; i < exercises; i++) {
        cout << "Enter the pointed earned: "; 
        cin >> earned; 
        earned += earned; 
        cout << endl << "Enter the total posssible points available: "; 
        cin >> total;
        total += total; 
    }
    total = total; 
    earned = earned; 
    average = float (earned / float (total)) * percentage;
    cout <<  "Your total is " <<  earned << " out of " << total << " or "; 
    printf("%2.2lf%\n\n", average); 
    return 0; 
}



