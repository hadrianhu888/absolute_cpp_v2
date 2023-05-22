/**
 * @file sort_iterators.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 10, 8};
    int n = sizeof(a) / sizeof(int);

    cout << "a: ";
    copy(a, a + n, ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(a, a + n);

    cout << "a: ";
    copy(a, a + n, ostream_iterator<int>(cout, " "));
    cout << endl;

    /**
     * @brief use doubles
     *
     */

    double b[] = {1.1, 3.3, 5.5, 7.7, 9.9, 2.2, 4.4, 6.6, 10.10, 8.8};
    n = sizeof(b) / sizeof(double);

    cout << "b: ";
    copy(b, b + n, ostream_iterator<double>(cout, " "));
    cout << endl;

    sort(b, b + n);

    cout << "b: ";
    copy(b, b + n, ostream_iterator<double>(cout, " "));
    cout << endl;

    list<double> lst = {1.1, 3.3, 5.5, 7.7, 9.9, 2.2, 4.4, 6.6, 10.10, 8.8};
    vector<double> vec = {1.1, 3.3, 5.5, 7.7, 9.9, 2.2, 4.4, 6.6, 10.10, 8.8};

    cout << "lst: ";
    copy(lst.begin(), lst.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    cout << "vec: ";
    copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    lst.sort();
    sort(vec.begin(), vec.end());

    cout << "lst: ";
    copy(lst.begin(), lst.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    cout << "vec: ";
    copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    /**
     * @brief remove all items in the iterators - list and vector, respectively
     *
    */

    lst.erase(lst.begin(), lst.end());
    vec.erase(vec.begin(), vec.end());

    cout << "lst: ";
    copy(lst.begin(), lst.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    cout << "vec: ";
    copy(vec.begin(), vec.end(), ostream_iterator<double>(cout, " "));

    return 0;
}
