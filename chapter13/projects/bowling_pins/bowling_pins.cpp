/**
 * @file bowling_pins.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int main(int argc, char **argv);
void displayPins(int n);
void displayBowlingPinPyramid(int n);
void centerBowlingPinsPyramidWithStars(int n);
void centerBowlingPinsPyramidWithStars(int n, int max_n);

int main(int argc, char **argv)
{
    int n;
    cout << "Enter the number of bowling pins: ";
    cin >> n;
    cout << endl;
    displayBowlingPinPyramid(n);
    cout << endl;
    centerBowlingPinsPyramidWithStars(n);
    cout << endl;
    return 0;
}

void displayPins(int n)
{
    if (n == 0)
    {
        cout << " ";
    }
    else
    {
        displayPins(n - 1);
        cout << "*";
    }
}

void displayBowlingPinPyramid(int n)
{
    if (n == 0)
    {
        cout << " ";
    }
    else
    {
        displayBowlingPinPyramid(n - 1);
        displayPins(n);
        cout << endl;
    }
}

void centerBowlingPinsPyramidWithStars(int n)
{
    centerBowlingPinsPyramidWithStars(n, n);
}

void centerBowlingPinsPyramidWithStars(int n, int max_n)
{
    if (n == 0)
    {
        cout << string(max_n, ' ') << "*";
    }
    else
    {
        centerBowlingPinsPyramidWithStars(n - 1, max_n);
        cout << string(max_n - n, ' ');
        displayPins(n);
        cout << endl;
    }
}
