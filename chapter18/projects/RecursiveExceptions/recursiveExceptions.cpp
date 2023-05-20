/**
 * @file recursiveExceptions.cpp
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

int recursive_mutex_create(int depth, int max_depth) throw(int);

int recursive_mutex_create(int depth, int max_depth) throw(int)
{
    int recursiveException;
    try
    {
        if (depth > max_depth)
        {
            throw depth;
            recursiveException = recursive_mutex_create(depth + 1, max_depth);
            cout << recursiveException << endl;
        }
    }
    catch (int e)
    {
        cout << "Caught an exception: " << e << endl;
        recursiveException = recursive_mutex_create(depth + 1, max_depth);
        cout << recursiveException << endl;
    }
    return depth;
}

int main(int argc, char **argv)
{
    int depth = 0;
    int max_depth = 0;
    try
    {
        cout << "Enter a depth: ";
        cin >> depth;
        cout << "Enter a max depth: ";
        cin >> max_depth;
        if (depth < 0 || max_depth < 0)
        {
            throw depth;
        }
        if (max_depth < depth)
        {
            throw max_depth;
        }
        if (depth == max_depth)
        {
            throw depth;
        }
    }
    catch (int e)
    {
        cout << "Caught an exception: " << e << endl;
    }
    try
    {
        recursive_mutex_create(depth, max_depth);
    }
    catch (int e)
    {
        cout << "Caught an exception: " << e << endl;
    }
    return 0;
}
