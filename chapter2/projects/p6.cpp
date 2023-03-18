/**
 * @file p6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cmath>

const float PI = 3.14159; 
const float specificWeightOfWater = 62.54; 

using namespace std; 

int main (int argc, char ** argv) {
    float weight = 0.0; 
    float buoyancy = 0.0; 
    float volume = 0.0; 
    float radius = 0.0; 
    cout << "Enter the weight of the object: "; 
    cin >> weight; 
    cout << endl << "Enter the radius of tbe object: "; 
    cin >> radius; 
    volume = (4/3)*PI*pow(radius,3); 
    buoyancy = volume * specificWeightOfWater; 
    if (buoyancy >= volume) {
        cout << "The object will float.\n\n"; 
    } else { 
        cout << "The object will sink.\n\n";
    }
    return 0; 
}

