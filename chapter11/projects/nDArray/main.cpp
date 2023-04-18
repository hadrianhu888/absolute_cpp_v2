#include "nDArray.cpp"
#include <cassert>
#include <iostream>
using namespace nd;
using namespace std;

void assert_nD(const nDArray<int> &a, const vector<int> &indices, int expected)
{
    assert(a[indices] == expected);
    assert(a[{indices}] == expected);
}

void test1DArray()
{
    nd::nDArray<int> a({5});
    assert(a.getDimensions().size() == 1);
    assert(a.getDimensions()[0] == 5);

    a[{2}] = 42;
    assert(a[{2}] == 42);
}

void test2DArray()
{
    nd::nDArray<int> a({3, 4});
    assert(a.getDimensions().size() == 2);
    assert(a.getDimensions()[0] == 3);
    assert(a.getDimensions()[1] == 4);

    a[{1, 2}] = 42;
    assert_nD(a, {1, 2}, 42);
}

void test3DArray()
{
    nd::nDArray<int> a({2, 3, 4});
    assert(a.getDimensions().size() == 3);
    assert(a.getDimensions()[0] == 2);
    assert(a.getDimensions()[1] == 3);
    assert(a.getDimensions()[2] == 4);

    a[{1, 2, 3}] = 42;
    assert_nD(a, {1, 2, 3}, 42);
}

int main()
{
    std::cout << "Running tests...\n\n";

    test1DArray();
    std::cout << "1D Array tests passed.\n";

    test2DArray();
    std::cout << "2D Array tests passed.\n";

    test3DArray();
    std::cout << "3D Array tests passed.\n";

    std::cout << "\nAll tests passed!\n";

    return 0;
}
