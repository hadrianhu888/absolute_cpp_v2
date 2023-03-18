/**
 * @file vector_exercise.cpp
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

int main(int argc, char **argv)
{
    vector<int> v(10);
    int i; 
    for (i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }
    vector<int> copy; 
    copy = v;
    v[0] = 100;
    for (i = 0; i < v.size(); i++)
    {
        cout << "v[" << i << "] = " << v[i] << endl;
    }
    for (i = 0; i < copy.size(); i++)
    {
        cout << "copy[" << i << "] = " << copy[i] << endl;
    }
    return 0;
}

/**
 * @brief Size of a vector means the number of elements in the vector.
 * Vector capacity is the number of elements that can be stored in the vector without resizing.
 */