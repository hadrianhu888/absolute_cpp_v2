/**
 * @file rose.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int rose(int n);
int main(int argc, char **argv);

//Function rose takes an integer n as an argument
int rose(int n)
{
    //If n is less than or equal to 1, return 0
    if (n <= 1)
    {
        return 0;
    }
    //Otherwise, return rose(n-1) * n
    else
    {
        return rose(n-1) * n;
    }
}

int main(int argc, char **argv)
{
    //Print out the result of calling rose(4)
    cout << rose(4) << endl;
    //Print out the result of calling rose() for each integer from 0 to 10
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << rose(i) << endl;
    }
    //Return 0
    return 0;
}
/**
 * @brief
 * This code is a recursive function that computes the factorial of a given number. The function "rose" takes an integer "n" as an argument and checks if it is less than or equal to 1. If the value of "n" is less than or equal to one, the function returns a 0, otherwise the function calls the same function with a reduced value of "n-1" and returns the factorial of "n" by multiplying it with the result of the recursive call. In the main function, the rose function is called with the value 4 and the output of this is printed. Then, a for loop is used to output the factorial of each number from 0 to 9 by calling the rose function.
 *
 */
