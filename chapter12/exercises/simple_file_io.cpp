/**
 * @file simple_file_io.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int main();

int main()
{
    ifstream inStream;
    ofstream outStream;

    inStream.open("input.txt");
    outStream.open("output.txt");

    int first;
    int second;
    int third;

    inStream >> first >> second >> third;
    outStream << "The sum of the three numbers is: " << first + second + third << endl;

    inStream.close();
    outStream.close();

    return 0;

}
