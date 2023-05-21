/**
 * @file stacks.cpp
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
    stack<int> container;
    for(int i = 0; i < 10; i++)
    {
        container.push(i);
    }
    cout << "Here is what is in the container: " << endl;
    while(!container.empty())
    {
        cout << container.top() << " ";
        container.pop();
    }
    cout << endl;
    stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    cout << "Here is what is in the container: " << endl;
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
/*     stack<int>::iterator p;
    for(p = container.begin(); p != container.end(); p++)
    {
        *p = 0;
    }
    cout << endl;
    cout << "Here is what is in the container: " << endl;
    for(p = container.begin(); p != container.end(); p++)
    {
        cout << *p << " ";
    } */
    return 0;
}
