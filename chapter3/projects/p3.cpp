/**
 * @file p3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <math.h> 

using namespace std; 

const double UniversalGravitationalConstant = 6.673e-8; 

int main (int argc, char ** argv); 
double calculateGravitationalConstant(double Mass1, double Mass2, double Distance); 

double calculateGravitationalConstant(double Mass1, double Mass2, double Distance)
{
    double gravitationalForce = 0.0; 
    gravitationalForce = (UniversalGravitationalConstant * Mass1 * Mass2) / (pow(Distance,2)); 
    return gravitationalForce; 
}

int main (int argc, char ** argv) 
{   
    bool repeat = true;
    while (repeat == true) 
    {
        double Mass1 = 0.0; 
        double Mass2 = 0.0;
        double Distance = 0.0; 
        double gravitationalConstant = 0.0; 
        char repeatChoice = '\0'; 
        cout << "Enter the mass of objects one and object two, including their distance in cm."; 
        cin >> Mass1; 
        cin >> Mass2; 
        cin >> Distance; 
        cout << "Enter the mass of objects one and object two, including their distance in cm."; 
        cin >> Mass1; 
        cin >> Mass2; 
        cin >> Distance; 
        gravitationalConstant = calculateGravitationalConstant(Mass1, Mass2, Distance); 
        cout << endl << "The gravitational constant between the two masses given a distance of "; 
        cout << Mass1 << " kg, " << Mass2 << " kg, " << Distance << " cm is "; 
        cout << gravitationalConstant  << " dyne. "<< endl; 
        cout << endl << "Repeat the calculation? [y/n]"; 
        cin >> repeatChoice; 
        if (repeatChoice == 'y') 
        {
            repeat = true; 
            main(argc, argv); 
        }
        else 
        {
            repeat = false; 
            exit(0);
        }
    }
    return 0; 
}