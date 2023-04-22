/**
 * @file self_test_part_3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void copyChar(ifstream &inFile, ofstream &outFile, int numberAfterDecimalPoint, int fieldWidth)
{
    outFile.setf(ios::fixed);
    outFile.setf(ios::showpoint);
    outFile.setf(ios::showpos);
    outFile.precision(numberAfterDecimalPoint);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(numberAfterDecimalPoint);

    char next;
    while (inFile >> next)
    {
        cout << setw(fieldWidth) << next << endl;
        outFile << setw(fieldWidth) << next << endl;
    }
}
void copyLine(ifstream &inFile, ofstream &outFile, int number)
{
    string next;
    while (getline(inFile, next))
    {
        cout << setw(number) << next << endl;
        outFile << setw(number) << next << endl;
    }
}
void sendLine(ifstream &inFile, ofstream &outFile, int number)
{
    string next;
    while (getline(inFile, next))
    {
        cout << next << endl;
        outFile << next << endl;
    }
}
ifstream testFile(istream& file)
{
    ifstream inFile;
    inFile.open("inFile.txt");
    return inFile;
}
ofstream testFile(ostream& file)
{
    ofstream outFile;
    outFile.open("outFile.txt");
    return outFile;
}

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("stuff.txt");
    outFile.open("stuff2.txt");
    copyChar(inFile, outFile, 2, 5);
    inFile.close();
    outFile.close();
    ifstream inFile1;
    ofstream outFile1;
    inFile1.open("stuff.txt");
    copyLine(inFile1, outFile1, 5);
    inFile1.close();
    outFile1.close();
    ifstream inFile2;
    ofstream outFile2;
    inFile2.open("stuff.txt");
    sendLine(inFile2, outFile2, 5);
    inFile2.close();
    outFile2.close();
    return 0;
}
