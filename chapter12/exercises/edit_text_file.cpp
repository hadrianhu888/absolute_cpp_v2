/**
 * @file edit_text_file.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool fileExists(ifstream& file)
{
    return file.good();
}

bool fileExists(ofstream& file)
{
    return file.good();
}

void newLine(ifstream& inStream, ofstream& outStream)
{
    string line;
    while (getline(inStream, line))
    {
        outStream << line << endl;
    }
}

void addPlusPlus(ifstream& inStream, ofstream& outStream)
{
    string line;
    while (getline(inStream, line))
    {
        outStream << line << "++" << endl;
    }
}

int main(int argc,char  **argv)
{
    ifstream in;
    ofstream out;
    in.open("datafile.txt");
    while(!in.eof())
    {
        newLine(in, out);
    }
    bool inFileExists;
    bool outFileExists;
    inFileExists=fileExists(in);
    outFileExists = fileExists(out);
    out.open("datafilePlusPlus.txt");
    while(!in.eof())
    {
        addPlusPlus(in, out);
    }
    addPlusPlus(in, out);
    in.close();
    out.close();
    return 0;
}

//stream cin is of fstream. stream cout is  of ofstream.
