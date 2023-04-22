/**
 * @file format_output.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void makeNeat(ifstream &messyFile, ofstream &neatFile, int numberAfterDecimalPoint, int fieldWidth)
{
    neatFile.setf(ios::fixed);
    neatFile.setf(ios::showpoint);
    neatFile.setf(ios::showpos);
    neatFile.precision(numberAfterDecimalPoint);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(numberAfterDecimalPoint);

    double next;
    while (messyFile >> next)
    {
        cout << setw(fieldWidth) << next << endl;
        neatFile << setw(fieldWidth) << next << endl;
    }
}

int main(int argc, char **argv)
{
    //create a messy file with double variables
    ofstream messy;
    messy.open("messy.txt");
    messy << "123.456" << endl;
    messy << "123.456"
          << "    "
          << "124.156" << endl;
    messy << "123.456"
          << "    "
          << "124.156156"
          << "    "
          << "-125.1514566" << endl;
    messy << "-10.24554     123151.454" << endl;
    messy.close();

    //reorganize the messy file by writing to neat.txt
    ifstream messyFile;
    messyFile.open("messy.txt");
    ofstream neat;
    neat.open("neat.txt");
    makeNeat(messyFile, neat, 3, 10);
    neat.close();
    messyFile.close();

    return 0;
}
