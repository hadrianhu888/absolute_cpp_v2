/**
 * @file set.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include <set>

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    set<int> container;
    for(int i = 0; i < 10; i++)
    {
        container.insert(i);
    }
    cout << "Here is what is in the container: " << endl;
    set<int>::iterator p;
    for(p = container.begin(); p != container.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    cout << "Here is what is in the container: " << endl;
    for(p = container.begin(); p != container.end(); p++)
    {
        cout << *p << " ";
    }
    set<string> container2;
    container2.insert("hello");
    container2.insert("world");
    container2.insert("hello");
    container2.insert("again");
    cout << endl;
    cout << "Here is what is in the container: " << endl;
    set<string>::iterator p2;
    for(p2 = container2.begin(); p2 != container2.end(); p2++)
    {
        cout << *p2 << " ";
    }
    return 0;
}
