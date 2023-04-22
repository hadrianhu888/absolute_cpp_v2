/**
 * @file programming_advise.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2//common.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void openFile(ifstream &file);
void displayFileContent(ifstream &file);
void askForAdviseFromUser(string &text);
void appendToFile(ifstream &file);
void appendUserStringToFile(string &advise, ifstream &file);
int main(int argc, char **argv);

void openFile(ifstream &file)
{
    file.open("program_advise.txt");
    if (!file)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
}

void displayFileContent(ifstream &file)
{
    string next;
    while (getline(file, next))
    {
        cout << next << endl;
    }
}

void askForAdviseFromUser(string &text)
{
    cout << "Enter your advise: ";
    getline(cin, text);
    //terminate after two enters
    if (text == "\n\n")
    {
        cout << "Terminating program" << endl;
        exit(1);
    }
    if(!text.empty())
    {
        cout << "You entered: " << text << endl;
    }
}

void appendToFile(ifstream &file)
{
    ofstream outFile;
    outFile.open("program_advise.txt", ios::app);
    string text;
    askForAdviseFromUser(text);
    outFile << text << endl;
    outFile.close();
}

void appendUserStringToFile(string &advise, ifstream &file)
{
    ofstream outFile;
    outFile.open("program_advise.txt", ios::app);
    outFile << advise << endl;
    outFile.close();
}

void displayOnlyLatestAdvise(string &advise, ifstream &file)
{
    //get the last line of the file
    string lastLine;
    while (getline(file, lastLine))
    {
        cout << lastLine << endl;
    }
}

int main(int argc, char **argv)
{
    ifstream file;
    string advise;
    openFile(file);
    displayFileContent(file);
    file.close();
    appendToFile(file);
    displayOnlyLatestAdvise(advise, file);
    appendUserStringToFile(advise, file);
    return 0;
}
