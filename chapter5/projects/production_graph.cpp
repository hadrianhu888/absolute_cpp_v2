/**
 * @file production_graph.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <cmath> 

using namespace std;
using namespace std::chrono;

const int NUMBER_OF_PLANTS = 4;

void inputData(int a[], int lastPlantNumber);
void scale(int a[], int size); 
void draw_graph(const int asteriskCount[], int lastPlantNumber);
void draw_vertical_graph(const int asteriskCount[], int lastPlantNumber);
void getTotal(int &sum); 
int get_round(double number);
void printAsterisks(int asteriskCount);
void printVerticalAsterisks(int asteriskCount);
int main(int argc, char **argv); // main function prototype

void inputData(int a[], int lastPlantNumber)
{
    for (int plantNumber = 1; plantNumber <= lastPlantNumber; plantNumber++)
    {
        cout << "Enter production data for plant number " << plantNumber << endl;
        cout << "Enter number of units produced by each department." << endl;
        getTotal(a[plantNumber - 1]);
    }
}

void scale(int a[], int size)
{
    int largest = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        a[i] = static_cast<int>(10.0 * a[i] / largest);
    }
}

void draw_graph(const int asteriskCount[], int lastPlantNumber)
{
    cout << "Units produced in millions of units:" << endl;
    for (int plantNumber = 1; plantNumber <= lastPlantNumber; plantNumber++)
    {
        cout << "Plant #" << plantNumber << " ";
        printAsterisks(asteriskCount[plantNumber - 1]);
        cout << endl;
    }
}

void draw_vertical_graph(const int asteriskCount[], int lastPlantNumber)
{
    /**
     * @brief display the graph vertically with the asterisks
     * and headings at the bottom
     * 
     */
    int largest = asteriskCount[0];
    for (int i = 1; i < lastPlantNumber; i++)
    {
        if (asteriskCount[i] > largest)
        {
            largest = asteriskCount[i];
        }
    }
    for (int i = largest; i > 0; i--)
    {
        for (int j = 0; j < lastPlantNumber; j++)
        {
            if (asteriskCount[j] >= i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= lastPlantNumber; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

void getTotal(int &sum)
{
    int departmentNumber;
    int total = 0;
    for (departmentNumber = 1; departmentNumber <= 4; departmentNumber++)
    {
        int input;
        cout << "Enter data for department number " << departmentNumber << endl;
        cin >> input;
        total += input;
    }
    sum = total;
}


int get_round(double number)
{
    return static_cast<int>(floor(number + 0.5));
}

void printAsterisks(int asteriskCount)
{
    for (int i = 0; i < asteriskCount; i++)
    {
        cout << "*";
    }
}

void printVerticalAsterisks(int asteriskCount)
{
    for (int i = 0; i < asteriskCount; i++)
    {
        cout << "*" << endl;
    }
}

int main(int argc, char **argv)
{
    int production[NUMBER_OF_PLANTS];
    inputData(production, NUMBER_OF_PLANTS);
    scale(production, NUMBER_OF_PLANTS);
    draw_graph(production, NUMBER_OF_PLANTS);
    draw_vertical_graph(production, NUMBER_OF_PLANTS);
    return 0;
}


