/**
 * @file volume.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]); // function prototype
void showVolume(double length, double width, double height); // function prototype

void showVolume(double length, double width, double height) {
    cout << "Volume: " << length * width * height << endl;
}

int main(int argc, char const *argv[])
{
    double length, width, height;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    showVolume(length, width, height);
    return 0;
}

// Compare this snippet from chapter4\exercises\volume.cpp: