/**
 * @file file_append.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    cout << "Opening the datafile.txt"<<endl;
    ofstream outStream;
    outStream.open("datafile.txt", ios::app);
    if (outStream.fail())
    {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    outStream << "5 6 pick up the sticks" <<endl;
    outStream << "7 8 ain't C++ great!"  <<endl;

    outStream.close();

    cout << "Closing the datafile.txt"<<endl;

    return 0;
}
