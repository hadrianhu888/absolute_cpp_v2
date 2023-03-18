/**
 * @file pizza.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert> 
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>

#define M_PI 3.14159265358979323846

using namespace std;

int main(int argc, char** argv); // function prototype
void printPizzaInfo(int diameter, int slices, int cost);
//void printPizzaInfo(int sides, int slices, int cost); // overloaded function
int calcCostPerSlice(int diameter, int slices, int cost); // function prototype
void giveResults(int& diameter, int& slices, int& cost); // function prototype
double calculateArea(int& diameter); // function prototype
double test_pizza_cost_by_assertion(int& diameter, int& slices, int& cost); // function prototype
double test_pizza_area_by_assertion(int& diameter, int& slices, int& cost); // function prototype

/* void printPizzaInfo(int sides, int slices, int cost) {
    cout << "Sides: " << sides << endl;
    cout << "Slices: " << slices << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Cost per slice: $" << calcCostPerSlice(sides, slices, cost) << endl;
} */

/**
 * @brief Cannot be overloaded because the return type is the same as the round pizza scenario parameters
 * 
 * @param diameter 
 * @param slices 
 * @param cost 
 */

double test_pizza_cost_by_assertion(int& diameter, int& slices, int& cost) {
    double area = calculateArea(diameter);
    assert(cost == 10);
    return area;
}

double test_pizza_area_by_assertion(int& diameter, int& slices, int& cost) {
    double area = calculateArea(diameter);
    assert(area == 78.53981633974483);
    return area;
}

void printPizzaInfo(int diameter, int slices, int cost) {
    cout << "Diameter: " << diameter << " inches" << endl;
    cout << "Slices: " << slices << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Cost per slice: $" << calcCostPerSlice(diameter, slices, cost) << endl;
}

int calcCostPerSlice(int diameter, int slices, int cost) {
    return cost / slices;
}

void giveResults(int& diameter, int& slices, int& cost) {
    cout << "Diameter: " << diameter << " inches" << endl;
    cout << "Slices: " << slices << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Cost per slice: $" << calcCostPerSlice(diameter, slices, cost) << endl;
}

double calculateArea(int& diameter) {
    return M_PI * pow(diameter / 2, 2);
}

int main(int argc, char** argv) {
    int diameter = 0, slices = 0, cost = 0;
    cout << "Enter the diameter of the pizza: ";
    cin >> diameter;
    cout << "Enter the number of slices: ";
    cin >> slices;
    cout << "Enter the cost of the pizza: ";
    cin >> cost;
    /**
     * @brief Display the area of the pizza
     * 
     */
    cout << "Area: " << calculateArea(diameter) << endl;
    printPizzaInfo(diameter, slices, cost);
    giveResults(diameter, slices, cost);
    return 0;
}

