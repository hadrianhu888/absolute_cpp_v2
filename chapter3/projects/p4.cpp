/**
 * @file p4.cpp
 * @author Hadrian (hadrian.hu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-19
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

const float hatConstant = 2.9; 
const float JacketSizeConstantOne = 288; 
const float JacketSizeAdjustmentPerTenYearsAfterThirty = 0.125; 
const float WaistConstant = 5.7; 
const float JacketSizeAdjustmentEveryTwoYearsAfterTwentyEight = 0.1; 

int main (int argc, char ** argv); 
float calculateHatSize (float height, float weight, int age); 
float calculateJacketSize (float height, float weight, int age); 
float calculateWaistSize(float height, float weight, int age); 

int main (int argc, char ** argv)
{
    bool repeat = true; 
    while (repeat == true)
    {
        float height = 0.0; 
        float weight = 0.0;
        float hatSize = 0.0; 
        float jacketSize = 0.0; 
        float waistSize = 0.0;
        int age = 0; 
        char repeatChoice = '\0'; 
        cout << "Enter height in inches, weight in lbs and age as a natural number: "; 
        cin >> height; 
        cin >> weight; 
        cin >> age; 
        cout << endl << "Calculating the values for hat size, jacket size and waist size: " << endl; 
        hatSize = calculateHatSize(weight, height, age); 
        jacketSize = calculateJacketSize(weight, height, age); 
        waistSize = calculateWaistSize(weight, height, age);
        cout << endl << "Hat size = " << hatSize << endl; 
        cout << endl << "Jacket size = " << jacketSize << endl; 
        cout << endl << "Waist size = " << waistSize << endl; 
        cout << endl << "Repeat the calculations? [y/n]"; 
        cin >> repeatChoice; 
        if (repeatChoice == 'y' || repeatChoice == 'Y')
        {
            repeat = true; 
            main(argc, argv); 
        } 
        else if (repeatChoice == 'n' || repeatChoice == 'N')
        {
            repeat = false; 
            exit(0);
        }
    }
    return 0;
}
float calculateHatSize (float height, float weight, int age)
{
    float hatSize = 0.0; 
    hatSize = (weight / height) * hatConstant; 
    return hatSize; 
}
float calculateJacketSize (float height, float weight, int age)
{
    float jacketSize = 0.0; 
    int countTenYears = 0; 
    int ageRemainder = 0; 
    if (age < 30) {
        jacketSize = (weight * height) / JacketSizeConstantOne; 
    } 
    else {
        age = age - 30; 
        age = age / 10; 
        ageRemainder = age % 10; 
        if (ageRemainder == 0)
        {
            jacketSize = ((weight * height) / JacketSizeConstantOne) + (JacketSizeAdjustmentPerTenYearsAfterThirty * (age - ageRemainder));
        }
        else 
        {
            jacketSize = ((weight * height) / JacketSizeConstantOne);
        }
    }
    return jacketSize; 
}
float calculateWaistSize(float height, float weight, int age)
{   
    float waistSize = 0.0; 
    int countTwoYears = 0; 
    int ageRemainder = 0; 
    if (age < 28) 
    {
        waistSize = weight / WaistConstant;         
    }
    else if (age >=  28) 
    {
        age = age - 28; 
        age = age / 2; 
        ageRemainder = age % 2; 
        if (ageRemainder == 0) 
        {
            waistSize = weight / WaistConstant + (age * JacketSizeAdjustmentEveryTwoYearsAfterTwentyEight);     
        }
        else 
        {
            waistSize = weight / WaistConstant + ((age - ageRemainder) * JacketSizeAdjustmentEveryTwoYearsAfterTwentyEight);
        }
    }
    return waistSize;
}

