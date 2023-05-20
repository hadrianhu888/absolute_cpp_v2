/**
 * @file lists.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    list<int> container;
    for(int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }
    cout << "Here is what is in the container: " << endl;
    for(list<int>::iterator p = container.begin(); p != container.end(); p++)
    {
        cout << *p << " ";
    }
    list<int>::iterator p;
    for(p = container.begin(); p != container.end(); p++)
    {
        *p = 0;
    }
    cout << endl;
    cout << "Here is what is in the container: " << endl;
    for(p = container.begin(); p != container.end(); p++)
    {
        cout << *p << " ";
    }
    return 0;
}
