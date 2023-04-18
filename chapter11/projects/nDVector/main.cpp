/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "nDVector.cpp"
#include <cassert>
#include <iostream>
using namespace nv;
using namespace std;

void assert_nD(const nDVector<int> &a, const vector<int> &indices, int expected)
{
    assert(a[indices] == expected);
    assert(a[{indices}] == expected);
}

void test1DVector()
{
    nDVector<int> a({3});
    assert(a.getDimensions().size() == 1);
    assert(a.getDimensions()[0] == 3);

    a[{1}] = 42;
    assert_nD(a, {1}, 42);
}

void test2DVector()
{
    nDVector<int> a({2, 3});
    assert(a.getDimensions().size() == 2);
    assert(a.getDimensions()[0] == 2);
    assert(a.getDimensions()[1] == 3);

    a[{1, 2}] = 42;
    assert_nD(a, {1, 2}, 42);
}

void test3DVector()
{
    nDVector<int> a({2, 3, 4});
    assert(a.getDimensions().size() == 3);
    assert(a.getDimensions()[0] == 2);
    assert(a.getDimensions()[1] == 3);
    assert(a.getDimensions()[2] == 4);

    a[{1, 2, 3}] = 42;
    assert_nD(a, {1, 2, 3}, 42);
}

int main()
{
    cout << "Testing nDVector" << endl;
    test1DVector();
    cout << "1D test passed" << endl;
    test2DVector();
    cout << "2D test passed" << endl;
    test3DVector();
    cout << "3D test passed" << endl;
    cout << "\nAll tests passed!\n";
    return 0;
}
