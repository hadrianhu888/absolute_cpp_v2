/**
 * @file p9.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>
#include <string> 
#include <cstring>
#include <cctype> 
#include <string> 
#include <ctime> 
#include <time.h> 

using namespace std; 

int inchesHeightMother = 0; 
int inchesHeightFather = 0; 
int FeetHeightMale = 0; 
int InchHeightMale = 0; 
int FeetHeightFemale = 0; 
int InchHeightFemale = 0; 
int childHeight = 0; 
char gender ='\0'; 

const int feetToInchConversion = 12; 
const int inchesToFeetConversion = 1 / feetToInchConversion; 

int main(int argc, char ** argv); 
int getMaleHeight(int FatherHeight, int MotherHeight); 
int getFemaleHeight(int FatherHeight, int MotherHeight); 
int getHeightFromGender(char gender); 
int getHeightFromGender(char gender, int FatherHeight, int MotherHeight);
char setGender(char gender);
char getGender(char gender);
int getFeet(int Height);
int getRemainingInches(int Height);
void getHeightFeetAndInches (int Height);

int main(int argc, char ** argv)
{
    cout << "Enter the father's height and mother's height in Inches: "; 
    cin >> inchesHeightFather; 
    cin >> inchesHeightMother; 
    cout << endl << "Enter the child's gender: "; 
    cin >> gender; 
    childHeight = getHeightFromGender(gender, inchesHeightFather, inchesHeightMother);
    getHeightFeetAndInches (childHeight);
    return 0;
}
int getMaleHeight(int FatherHeight, int MotherHeight)
{
    InchHeightMale = ((MotherHeight * (13/12) + FatherHeight)) / 2; 
    return InchHeightMale;
}
int getFemaleHeight(int FatherHeight, int MotherHeight)
{
    InchHeightFemale = ((FatherHeight * (12/13) + MotherHeight)) / 2; 
    return InchHeightFemale;
}
int getHeightFromGender(char gender, int FatherHeight, int MotherHeight)
{
    int Height = 0; 
    if (gender == 'm' || gender == 'M')
    {
        Height = getMaleHeight(FatherHeight, MotherHeight); 
        cout << Height << " inches." << endl; 
    }
    else if (gender == 'f' || gender == 'F') 
    {
        Height = getFemaleHeight(FatherHeight, MotherHeight); 
        cout << Height << " inches." << endl; 
    }
    else 
    {
        cout << "Not a valid gender. Please type 'm' or 'f' for male or female, respectively\n"; 
    }
    return Height; 
}
char setGender(char gender) 
{
    return gender = gender; 
}
char getGender(char gender)
{
    return gender; 
}
int getFeet(int Height) 
{
    return (Height / feetToInchConversion); 
}
int getRemainingInches (int Height) 
{
    return (Height % feetToInchConversion);
}
void getHeightFeetAndInches (int Height) 
{
    int feet = getFeet(Height); 
    int inches = getRemainingInches(Height); 
    cout << "The child's height in feet and inches is " << feet << " ft " << inches << " inches." << endl; 
}
