/**
 * @file vector_example.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file


using namespace std;

int main(int argc, char **argv); 

/**
 * @brief Test out the vector class with an example of creating a vector. 
 * 
 */


int main(int argc, char **argv)
{
    vector<int> v;
    cout << "Enter a list of positive numbers: " << endl;\
    cout << "Enter a negative number to end the list" << endl;
    int x;
    cin >> x;
    while (x >= 0)
    {
        v.push_back(x);
        cin >> x;
    }
    cout << "The list of numbers is: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}