/**
 * @file feet_inches_2_meter_cm.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "feet_inches_2_meter_cm.hpp"

/**
 * @brief converts feet and inches to meters and centimeters. 
    Do this repeatedly until the user enters 0 feet and 0 inches.
 * 
 */

double feet2inches(double feet) {
    double inches = feet * INCHES_PER_FOOT;
    return inches;
}

double inches2meters(double inches) {
    double meters = inches * INCH_2_METER;
    return meters;
}

double inches2centimeters(double inches) {
    double centimeters = inches * INCH_2_CENTIMETER;
    return centimeters;
}

double meters2inches(double meters) {
    double inches = meters * METER_2_INCH;
    return inches;
}

double centimeters2inches(double centimeters) {
    double inches = centimeters * CENTIMETER_2_INCH;
    return inches;
}

double check_total_measurement_feet_inches(double feet, double inches) {
    double total_inches = feet2inches(feet) + inches;
    if (total_inches > INCHES_PER_FOOT) {
        double feet = total_inches / INCHES_PER_FOOT;
        double inches = (int)total_inches % INCHES_PER_FOOT;
        cout << "Total measurement: " << feet << " feet and " << inches << " inches" << endl;
    }
    return total_inches;
}

int main(int argc, char const *argv[]) {
    cout << "Enter feet and inches: ";
    cin >> feet >> inches;
    while (feet != 0 && inches != 0) {
        double total_inches = check_total_measurement_feet_inches(feet, inches);
        double meters = inches2meters(total_inches);
        double centimeters = inches2centimeters(total_inches);
        cout << "Total measurement: " << meters << " meters and " << centimeters << " centimeters" << endl;
        cout << "Enter feet and inches: ";
        cin >> feet >> inches;
    }
    return 0;
}

