/**
 * @file add_number_arays.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Purpose of this program is to add two arrays of numbers
 * 
 */

#include <iostream> 
#include <array>
#include <cstdio> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath> 
#include <algorithm>

using namespace std;

int *array1;
int *array2; 
int *array3; 

int main(int argc,char **argv); 
int *add_two_arrays(int *array1,int *array2,int size);

int *add_two_arrays(int *array1,int *array2,int size) {
    int *array3 = new int[size];
    for (int i = 0; i < size; i++) {
        array3[i] = array1[i] + array2[i];
    }
    return array3;
}

int main(int argc,char **argv) {
    int size;
    cout << "Enter the size of the arrays: ";
    cin >> size;
    array1 = new int[size];
    array2 = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << " element of the first array: ";
        cin >> array1[i];
    }
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << " element of the second array: ";
        cin >> array2[i];
    }
    int *array3 = new int[size];
    array3 = add_two_arrays(array1,array2,size);
    for (int i = 0; i < size; i++) {
        cout << "The " << i + 1 << " element of the third array is: " << array3[i] << endl;
    }
    printf("The sum of the two arrays is: %d",*array3);
    return 0;
}

