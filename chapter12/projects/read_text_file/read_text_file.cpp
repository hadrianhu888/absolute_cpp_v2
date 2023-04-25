/**
 * @file read_text_file.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string inFileName = "textfile.txt";
string outFileName = "textile_updated.txt";

int main(int argc, char **argv);
void readFile(ifstream &inStream);
void resetStreamPosition(ifstream &inStream);
int countLinesInFile(ifstream &inStream);
void displayFile(ifstream &inStream);
void addNumbersSpacesToEachLine(ifstream &inStream);
void writeChangesToNewFileFromReferenceFile(ifstream &inStream, ofstream &outStream);
void displayNewFile(ifstream &inStream);

void readFile(ifstream &inStream)
{
    inStream.open(inFileName);
    if (inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
}

void resetStreamPosition(ifstream &inStream)
{
    inStream.clear();
    inStream.seekg(0, ios::beg);
}

int countLinesInFile(ifstream &inStream)
{
    int count = 0;
    string line;
    while (getline(inStream, line))
    {
        count++;
    }
    resetStreamPosition(inStream);
    return count;
}

void displayFile(ifstream &inStream)
{
    string line;
    while (getline(inStream, line))
    {
        cout << line << endl;
    }
    resetStreamPosition(inStream);
}

void addNumbersSpacesToEachLine(ifstream &inStream)
{
    string line;
    int count = 1;
    while (getline(inStream, line))
    {
        line = to_string(count) + ".     " + line;
        count++;
        cout << line << endl;
    }
    resetStreamPosition(inStream);
}

void writeChangesToNewFileFromReferenceFile(ifstream &inStream, ofstream &outStream)
{
    string line;
    int count = 1;
    while (getline(inStream, line))
    {
        if (line.empty())
        {
            outStream << line << endl;
            continue;
        }
        else
        {
            line = to_string(count) + ".     " + line;
            count++;
            outStream << line << endl;
        }
    }
    resetStreamPosition(inStream);
}

void displayNewFile(ifstream &inStream)
{
    string line;
    while (getline(inStream, line))
    {
        cout << line << endl;
    }
    resetStreamPosition(inStream);
}

int main(int argc, char **argv)
{
    ifstream inStream;
    ofstream outStream;
    readFile(inStream);
    int count = countLinesInFile(inStream);
    cout << "Number of lines in file: " << count << endl;
    cout << "Displaying file: " << endl;
    displayFile(inStream);
    cout << "Displaying file with numbers and spaces: " << endl;
    addNumbersSpacesToEachLine(inStream);
    outStream.open(outFileName);
    if (outStream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    writeChangesToNewFileFromReferenceFile(inStream, outStream);
    inStream.close();
    outStream.close();
    ifstream updatedInStream(outFileName);
    if (updatedInStream.fail())
    {
        cout << "Updated input file opening failed.\n";
        exit(1);
    }
    cout << "Displaying new file: " << endl;
    displayNewFile(updatedInStream);
    updatedInStream.close();
    return 0;
}
