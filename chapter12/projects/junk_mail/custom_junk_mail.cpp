/**
 * @file custom_junk_mail.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void openFile(ifstream &file);
void displayFile(ifstream &file);
void replaceTags(ifstream &inputFile, ofstream &outputFile, string tags, string name);

int main(int argc, char **argv)
{
    ifstream inputFile;
    ofstream outputFile;
    string tags = "#N#";
    string name = "Hadrian";
    openFile(inputFile);
    cout << "Enter your name: ";
    cin >> name;
    outputFile.open("junk_updated.txt");
    replaceTags(inputFile, outputFile, tags, name);
    inputFile.close();
    outputFile.close();
    return 0;
}

void openFile(ifstream &file)
{
    string fileName;
    cout << "Enter the name of the file: ";
    cin >> fileName;
    file.open(fileName.c_str());
    while (file.fail())
    {
        cout << "Error opening file. Try again: ";
        cin >> fileName;
        file.open(fileName.c_str());
    }
}

void displayFile(ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
}

void replaceTags(ifstream &inputFile, ofstream &outputFile, string tags, string name)
{
    string line;
    while (getline(inputFile, line))
    {
        if (line.find(tags) != string::npos)
        {
            line.replace(line.find(tags), tags.length(), name);
        }
        outputFile << line << endl;
    }
}
