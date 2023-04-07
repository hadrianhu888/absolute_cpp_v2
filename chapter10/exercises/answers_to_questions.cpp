/**
 * @file answers_to_questions.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief A  pointer in C++ is a variable that stores the address of another variable.
 * The * operator has three uses: 1) to declare a pointer, 2) to dereference a pointer, and 3) to declare a pointer to a member.
 *
 *
 */

#include <iostream>
using namespace std;

class NumberPointer
{
    private:
        double *ptr;
    public:
        NumberPointer(double *p = NULL)
        {
            ptr = p;
        }
};

int main(int argc,char  **argv)
{
    int *p1, *p2;
    p1 = new int;
    p2 = new int;
    *p1 = 5;
    *p2 = 10;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    p1 = p2;
    cout << "p1 = " << p1 << endl;
    *p1 = 30;
    cout << "p1 = " << p1 << endl;
    *p2 = 30;
    cout << "p2 = " << p2 << endl;
    *p1  = *p2;
    cout << "p1 = " << p1 << endl;
    delete p1;
    delete p2;
    cout << "p1 and p2 are deleted" << endl;
    int *intPtr1, intPtr2;
    /**
     * @brief the following above is confusing because intPtr1 is a  pointer,and  intPtr2 is a variable.
     * The new operator is used to allocate memory dynamically.
     */
    intPtr1 = new int;
    *intPtr1 = 5;
    cout << "intPtr1 = " << intPtr1 << endl;
    char *p;
    p = new char[10];
    cout << "p = " << p << endl;
    delete p;
    cout << "p is deleted" << endl;
    NumberPointer np1;
    NumberPointer np2;
    cout << "np1 = " << &np1 << endl;
    cout << "np2 = " << &np2 << endl;
    np1 = np2;
    cout << "np1 = " << &np1 << endl;
    return 0;
}
