/**
 * @file p8.cpp
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
#include <cstring>

using namespace std; 

int main(int argc, char ** argv) {
    float celcius = 0.0; 
    float fahrenheit = 0.0; 
    for (celcius = 100.0; celcius > 0.00; celcius -= 0.01) {
        fahrenheit = float (((9.0/5)*celcius) + 32);
        cout << celcius << "\t" << fahrenheit << endl; 
        if (fahrenheit == celcius) {     
            cout << "The temperature that celcius equals fahrenheit is " << celcius << endl;        
            break; 
        } else {
            continue; 
        }
    }
    /**cout << "The temperature that celcius equals fahrenheit is " << celcius << endl;**/ 
    return 0; 
}