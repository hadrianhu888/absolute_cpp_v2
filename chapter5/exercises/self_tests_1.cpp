/**
 * @file self_tests_1.cpp
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

using namespace std;
using namespace std::chrono;

void numberArray(int a[], int size);
void showArray(int a[], int size);
void fillArray(int a[], int size);
void check_positive_numbers(int a[], int size);
void check_negative_numbers(int a[], int size);
void letterBox(char a[], int size);
void showLetterBox(char a[], int size);
int main(int argc, char **argv); // main function prototype

int main(int argc, char **argv)
{
    /**
     * @brief fill the array
        If the array contains only positive numbers, print the array 
        If the array contains negative numbers, print the array and the message "The array contains negative numbers"
        If the array contains both positive and negative numbers, print the array and the message "The array contains both positive and negative numbers"
        If the array contains both positive and negative numbers, print the array and the message "The array contains both positive and negative numbers"
     * 
     */
    char b[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};  
    int a[10];
    fillArray(a, 10);
    showArray(a, 10);
    check_positive_numbers(a, 10);
    check_negative_numbers(a, 10);    
    showLetterBox(b, 10);
    letterBox(b, 10);
    return 0;
}

void fillArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
    }
}

void showArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

void numberArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = i;
    }
}

void check_positive_numbers(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            cout << "The array contains negative numbers" << endl;
            break;
        }
    }
}

void check_negative_numbers(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            cout << "The array contains negative numbers" << endl;
            break;
        }
    }
}

void letterBox(char a[], int size)
{
    /**
     * @brief reverse the letters in the array
     * 
     */
    for (int i = 0; i < size; i++) {
        a[i] = a[size - i - 1];
        cout << a[i] << endl;
    } 
    /**
     * @brief terminate with the period character
     * 
     */
    cout << "." << endl;
}

void showLetterBox(char a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}
