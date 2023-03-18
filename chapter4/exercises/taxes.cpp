/**
 * @file taxes.cpp
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
int addTax(int taxRate, int cost);

int addTax(int taxRate, int cost) {
    return cost + (cost * taxRate / 100);
}

int main(int argc, char const *argv[])
{
    int cost = 100;
    int taxRate = 6;
    int totalCost = addTax(taxRate, cost);
    cout << "cost = " << cost << ", taxRate = " << taxRate << ", totalCost = " << totalCost << endl;
    return 0;
}

