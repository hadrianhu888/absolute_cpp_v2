/**
 * @file overloading.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]); // function prototype
int ave(int x, int y);
int ave(int x, int y, int z);

int ave(int x, int y) {
    return (x + y) / 2;
}

int ave(int x, int y, int z) {
    return (x + y + z) / 3;
}

int main(int argc, char const *argv[])
{
    int x = 10, y = 20, z = 30;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << "ave(x, y) = " << ave(x, y) << endl;
    cout << "ave(x, y, z) = " << ave(x, y, z) << endl;
    return 0;
}

