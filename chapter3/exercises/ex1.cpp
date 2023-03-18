/**
 * @file ex1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std; 

int main (int argc, char ** argv) {
    cout << sqrt(16.0) << endl; 
    cout << pow(2,3) << endl; 
    cout << abs(3) << endl; 
    cout << fabs(-3.0) << endl; 
    cout << ceil(5.1) << endl; 
    cout << floor(5.8) << endl; 
    cout << 7 / abs(-2) << endl; 
    cout << sqrt(16) << endl; 
    cout << pow(2.0, 3) << endl; 
    cout << abs(-3) << endl; 
    cout << fabs(-3.5) << endl; 
    cout << ceil(5.8) << endl; 
    cout << pow(3.0,2) / 2.0 << endl; 
    cout << (7 + sqrt(4.0)) / 3.0 << endl; 
    cout << pow(2.0, 3.0) << endl; 
    cout << pow(1.1,2) << endl; 
    cout << abs(0) << endl; 
    cout << fabs(3.5) << endl; 
    cout << floor(5.1) << endl; 
    cout << pow(3.0,2) / 2 << endl; 
    cout << sqrt(pow(3,2)) << endl;
    /**
     * @brief 
     * sqrt(x+y)
     * pow(x,y+7)
     * sqrt(area+fudge)
     * sqrt(time+tide)/nobody
     * -b±sqrt(pow(b,2.0)-4*a*c)/(2*a)
     * abs(x-y)
     * 
     */
    cout << endl << "Printing out the square roots of numbers from 1 to 10 " << endl << endl; 
    for (float i = 1; i <= 10.0; i = i + 1.0) {
        cout << i << " " << sqrt(i) << endl; 
    }
    /**
     * @brief the function of the int argument to the void argument exit is to make sure there is a true condition met for exiting any program
     * 
     */
    return 0;
}