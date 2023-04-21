/**
 * @file read_list.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-20
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

void toScreen(ifstream &inStream);

void toScreen(ifstream &inStream)
{
    string line;
    while (getline(inStream, line))
    {
        cout << line << endl;
    }
}

void outputStuff(ofstream& outStream);

void outputStuff(ofstream& outStream)
{
    outStream << "This is a line of text" << endl;
    outStream << "This is another line of text" << endl;
    outStream << "This is the last line of text" << endl;
}

int main(int argc,char **argv)
{
    ifstream ins;
    ins.open("list.txt");
    if (ins.fail())
    {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    int count = 0;
    int next;
    while(ins >> next)
    {
        count++;
        cout << next << endl;
    }
    ins.close();
    cout <<count;
    toScreen(ins);
    ins.close();
    ofstream outs;
    outs.open("output_list.txt");
    outputStuff(outs);
    return 0;
}
