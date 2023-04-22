/**
 * @file file_merge.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void openFile1(ifstream& in1);
void openFile2(ifstream& in2);
void saveFileContents(ifstream& in1, ifstream& in2, ofstream& out);
void mergeFileContentsToFile3(ifstream& in1, ifstream& in2, ofstream& out);
void openFile3(ofstream& out);
void displayFileContents(ifstream& in1, ifstream& in2, ifstream& in3);
void displayFileContent(ifstream &file);
void closeFiles(ifstream &in1, ifstream &in2, ifstream &in3, ofstream &out);
void sortFileContent(ifstream& in3);

void openFile1(ifstream& in1)
{
    in1.open("file1.txt");
    if (in1.fail())
    {
        cout << "Error opening file1.txt" << endl;
        exit(1);
    }
    else
    {
        cout << "file1.txt opened successfully" << endl;
    }
}

void openFile2(ifstream& in2)
{
    in2.open("file2.txt");
    if (in2.fail())
    {
        cout << "Error opening file2.txt" << endl;
        exit(1);
    }
    else
    {
        cout << "file2.txt opened successfully" << endl;
    }
}

void openFile3(ofstream& out)
{
    out.open("file3.txt");
    if (out.fail())
    {
        cout << "Error opening file3.txt" << endl;
        exit(1);
    }
    else
    {
        cout << "file3.txt opened successfully" << endl;
    }
}

void saveFileContents(ifstream& in1, ifstream& in2, ofstream& out)
{
    string line;
    while (getline(in1, line))
    {
        out << line << endl;
    }
    while (getline(in2, line))
    {
        out << line << endl;
    }
}

void mergeFileContentsToFile3(ifstream& in1, ifstream& in2, ofstream& out)
{
    openFile3(out);
    saveFileContents(in1, in2, out);
}

void displayFileContents(ifstream& in1, ifstream& in2, ifstream& in3)
{
    string line;
    cout << "file1.txt contents: " << endl;
    while (getline(in1, line))
    {
        cout << line << endl;
    }
    cout << "file2.txt contents: " << endl;
    while (getline(in2, line))
    {
        cout << line << endl;
    }
    cout << "file3.txt contents: " << endl;
    while (getline(in3, line))
    {
        cout << line << endl;
    }
}

void closeFiles(ifstream& in1, ifstream& in2, ifstream& in3, ofstream& out)
{
    in1.close();
    in2.close();
    in3.close();
    out.close();
}

void displaySortedMergedFile(ifstream& in3)
{
    string line;
    vector<string> lines;
    while (getline(in3, line))
    {
        lines.push_back(line);
    }

    sort(lines.begin(), lines.end());

    cout << "Sorted contents of file3.txt:" << endl;
    for (const string& sorted_line : lines)
    {
        cout << sorted_line << endl;
    }
}

int main(int argc, char **argv)
{
    ifstream in1;
    ifstream in2;
    ifstream in3;
    ofstream out;

    openFile1(in1);
    openFile2(in2);
    mergeFileContentsToFile3(in1, in2, out);
    closeFiles(in1, in2, in3, out); // Close the files after merging

    openFile1(in1); // Reopen file1.txt to reset its position
    openFile2(in2); // Reopen file2.txt to reset its position
    in3.open("file3.txt");

    displayFileContents(in1, in2, in3);
    closeFiles(in1, in2, in3, out); // Close the files after displaying their contents

    in3.open("file3.txt"); // Reopen file3.txt to reset its position
    displaySortedMergedFile(in3); // Display the sorted contents of the merged file
    in3.close(); // Close file3.txt

    return 0;
}
