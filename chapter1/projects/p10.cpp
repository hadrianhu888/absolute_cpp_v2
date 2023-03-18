/**
 * @file p10.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std; 

/**
 * @brief constant definitions 
 * 
 */

const float gravity = 32.2; 

float distanceTravelled(float time); 
/**
 * @brief 
 * 
 * @param time 
 * @return float distance travelled in ft 
 */
float distanceTravelled(float time) {
    float distance = 0; 
    distance = 0.5 * gravity * pow(time,2); 
    return distance;
}

int main(int argc, char ** argv) {
    /**
     * @brief initialize variables 
     * 
     */
    float distance = 0.0; 
    float time = 0.0; 
    cout << "Enter the time: "; 
    cin >> time; 
    distance = distanceTravelled(time); 
    cout << "Distance travelled in ft: " << distance << " ft. in " << time << " seconds." << endl; 
    return 0; 
}