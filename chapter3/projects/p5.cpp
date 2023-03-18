/**
 * @file p5.cpp
 * @author your name (you@domain.com)
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
#include <cctype>

using namespace std; 

const int MAX = 500; 

int main (int argc, char ** argv); 
void getArrayValues(float array[], int size); 
void initializeArray(float array[], int size); 
void printArray(float array[], int size); 
float calculateAverage(float array[], int size); 
float calculateStandardDeviation(float array[], float average, int size); 

int main (int argc, char ** argv) 
{
    int size = 0; 
    int i = 0; 
    float value = 0; 
    float array[MAX];
    float average = 0.0; 
    float stdDev = 0.0;  
    initializeArray(array,MAX);
    i = 0;
    cout << endl << "Enter the size of the array: "; 
    cin >> size; 
    cout << endl << "Array Size: " << size << endl;
    getArrayValues(array, size);
    average = calculateAverage(array, size);
    stdDev = calculateStandardDeviation(array, average, size); 
    cout << "Standard deviation is: " << stdDev << endl; 
}
void getArrayValues(float array[], int size)
{
    float value = 0.0;   
    for(int i = 0; i < size; i++) 
    {
        cout << "Enter the value: "; 
        cin >> value;
        array[i] = value; 
    }
    printArray(array, size);
}
void initializeArray(float array[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        array[i] = 0;
    }
    printArray(array, size);
}
void printArray(float array[], int size) 
{
    for(int i = 0; i < size; i++) 
    {
        cout << endl << i + 1 << " .) " << array[i] << endl; 
    }
}
float calculateAverage(float array[], int size) 
{
    float average = 0.0; 
    float sum = 0.0;
    for (int i = 0; i < size; i++) 
    {
         sum = sum + array[i]; 
    }
    average = sum / size; 
    return average; 
}
float calculateStandardDeviation(float array[], float average, int size)
{
    float stdDeviation = 0.0; 
    float tempSum = 0.0; 
    for (int i = 0; i < size; i++) 
    {
        tempSum = tempSum + pow((array[i] - average),2);
    }
    tempSum = tempSum / size; 
    stdDeviation = sqrt(tempSum); 
    return stdDeviation; 
}



