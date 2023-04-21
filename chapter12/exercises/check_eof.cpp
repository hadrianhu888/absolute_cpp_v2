/**
 * @file check_eof.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Opening the datafile.txt" << endl;
    ifstream inStream;
    inStream.open("datafile.txt");
    if (inStream.fail())
    {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    string line;
    int count = 0;
    while (getline(inStream, line))
    {
        count++;
    }
    cout << "Number of lines in the file: " << count << endl;
    inStream.close();
    inStream.open("datafile.txt");
    int halfway = count / 2;
    cout << "Halfway: " << halfway << endl;
    for (int i = 0; i < halfway; i++)
    {
        getline(inStream, line);
    }
    cout << "Halfway line: " << line << endl;
    inStream.close();
    //reopens the file and finds where is end of file
    inStream.open("datafile.txt");
    while (getline(inStream, line))
    {
        if (inStream.eof())
        {
            cout << "End of file reached" << endl;
        }
    }
    inStream.close();
    return 0;
}
