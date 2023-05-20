/**
 * @file self_tests.cpp
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
void sampleFunctions(double test) throw(int);

void sampleFunctions(double test) throw(int)
{
    try
    {
        if (test < 0)
        {
            throw test;
        }
    }
    catch (int e)
    {
        cout << "Caught an exception: " << e << endl;
    }
}

int main(int argc,char **argv)
{
    double test = 0.0;
    cout << "Enter a number: ";
    cin >> test;
    try
    {
        sampleFunctions(test);
    }
    catch(int e)
    {
        cout << "Caught an exception: " << e << endl;
    }
    try
    {
        if (argc < 2)
        {
            throw argc;
        }
    }
    catch (int e)
    {
        cout << "Caught an exception: " << e << endl;
    }
    return 0;
}

/**
 * @brief
 * If an exception is never caught, the program will terminate.
 * A try block can be nested inside another try block. If an exception is thrown
 *  in the inner try block, the program will look for a catch block in the inner
 * try block. If it is not found, the program will look for a catch block in
 * the outer try block. If it is not found, the program will look for a catch
 * block in the function that contains the outer try block. If it is not found,
 * the program will look for a catch block in the function that contains the
 * function that contains the outer try block. If it is not found, the program
 * will look for a catch block in the function that contains the function that
 * contains the outer try block. If it is not found, the program will look for a
 *  catch block in the function that contains the function that contains the
 * function that contains the outer try block.
 *
 *
 */
