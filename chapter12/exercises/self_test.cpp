/**
 * @file self_test.cpp
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
    ifstream fin;
    ofstream fout;

    fin.open("datafile.txt");

    // Check if the file is open
    if(fin.fail())
    {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    //display to terminal
    string line;
    while(getline(fin,line))
    {
        cout << line << endl;
    }
    //write to file
    fout.open("datafile.txt",ios::app);
    if(fout.fail())
    {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    //open stuff1.txt and stuff2.txt
    ifstream fin1;
    ifstream fin2;
    fin1.open("stuff1.txt");
    fin2.open("stuff2.txt");
    //display to terminal
    string line1;
    string line2;
    while(getline(fin1,line1))
    {
        cout << line1 << endl;
    }
    while(getline(fin2,line2))
    {
        cout << line2 << endl;
    }
    //close all files
    fin.close();
    fout.close();
    fin1.close();
    fin2.close();
    return 0;
}
