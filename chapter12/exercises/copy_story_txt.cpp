/**
 * @file copy_story_txt.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string copy_text_from_source_to_destination(ifstream &inStream, ofstream &outStream);

string copy_text_from_source_to_destination(ifstream &inStream, ofstream &outStream)
{
    string line;
    while (getline(inStream, line))
    {
        outStream << line << endl;
    }
    return line;
}

    int main(int argc, char **argv)
{
    //copy text from story.txt to story_copy.txt
    ifstream inStream;
    inStream.open("story.txt");
    if (inStream.fail())
    {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    ofstream outStream;
    outStream.open("story_copy.txt");
    if (outStream.fail())
    {
        cout << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
    string line;
    while (getline(inStream, line))
    {
        outStream << line << endl;
    }
    inStream.close();
    outStream.close();
    return 0;
}
