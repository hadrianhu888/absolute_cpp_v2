/**
 * @file csv_parser.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "F:/GitHubRepos/absolute_cpp_v1/common.hpp"

using namespace std;
int main() 
{
    ifstream csvFile("input.csv");
    vector<string> dataList;
    string line = "";
// read data line by line in csv File
while (getline(csvFile, line))
{
    // vector to save record of a line
    vector<string> vec;
    string word = "";
    // read each word separated by comma
    for (auto x : line) 
    {
        if (x == ',') 
        {
            vec.push_back(word);
            word = "";
        }
        else 
        {
            word = word + x;
        }
    }
    vec.push_back(word);
    /**
     * @brief store the vec in dataList
     * 
     */
    vec.push_back(dataList[dataList.size() - 1]);
}
// print data
cout << "\nData Parsed from CSV File: \n";
for (int i = 0; i < dataList.size(); i++) 
{
    for (int j = 0; j < dataList[i].size(); j++) 
    {
        cout << dataList[i][j] << " ";
    }
    cout << "\n";
}
csvFile.close();
return 0;

}