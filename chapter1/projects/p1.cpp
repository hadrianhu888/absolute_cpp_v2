/**
 * @file p1.cpp
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

using namespace std; 

#define METRIC_TO_OZ 35273.92 

int main(int argc, char ** argv) {
    /**
     * @brief 
     * 
     */
    double cerealBoxWeight = 0.0; 
    int numberOfBoxes = 0; 
    double weightOfBoxInMetricTons = 0.0; 
    cout << "What is the weight of one cereal box? ";
    cin >> cerealBoxWeight; 
    weightOfBoxInMetricTons = cerealBoxWeight / METRIC_TO_OZ; 
    cout <<"The weight of the box in metric tons is: " << weightOfBoxInMetricTons << " metric tons" << endl; 
    numberOfBoxes = METRIC_TO_OZ / weightOfBoxInMetricTons; 
    cout <<"The number of cereal boxes to generate one metric ton is: " << numberOfBoxes << " boxes" << endl; 
    return 0;
}