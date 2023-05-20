/**
 * @file exception_handling.cpp
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

template <class T>
class NoMilk
{
public:
    NoMilk() = default;
    NoMilk(int HowMany) : _data(HowMany)
    {
        try
        {
            if (_data <= 0)
            {
                throw _data;
            }
        }
        catch(int e)
        {
            cout << e << " donuts, and No milk!\n"
                << "Go buy some milk.\n";
        }
    }
    NoMilk(const T &data, int ) : _data(data)
    {
        try
        {
            if (_data <= 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << e << " donuts, and No milk!\n"
                << "Go buy some milk.\n";
        }
    }
    friend ostream &operator<<(ostream &os, const NoMilk &nm)
    {
        os << nm._data << " donuts, and No milk!\n"
            << "Go buy some milk.\n";
        return os;
    }
    int getCount() const
    {
        try
        {
            if (_data <= 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << e << " donuts, and No milk!\n"
                << "Go buy some milk.\n";
        }
        return _data;
    }
private:
    T _data;
};

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    int x = 0;
    int y = 0;
    int z = 0;

    cout << "Enter two integers: ";
    cin >> x >> y;

    try
    {
        if (y == 0)
        {
            throw y;
        }
        z = x / y;
        cout << "The quotient of " << x << " divided by " << y << " is " << z << endl;
    }
    catch (int)
    {
        cout << "Division by zero!" << endl;
    }

    int donuts = 0;
    int milk = 0;
    cout << "Enter number of donuts: ";
    cin >> donuts;
    cout << "Enter number of glasses of milk: ";
    cin >> milk;

    try
    {
        if (milk <= 0)
        {
            throw donuts;
        }
        if (donuts <= 0)
        {
            throw milk;
        }
        cout << donuts << " donuts.\n"
            << milk << " glasses of milk.\n"
            << "You have " << donuts / milk << " donuts for each glass of milk.\n";
    }
    catch (int e)
    {
        cout << e << " donuts, and No milk!\n"
            << "Go buy some milk.\n";
    }

    int waitTime = 46;
    try
    {
        if (waitTime > 30)
        {
            throw waitTime;
        }
        cout << "Wait time = " << waitTime << endl;
        if (waitTime > 0)
        {
            throw 99;
        }
    }
    catch (int e)
    {
        cout << "Too long to wait - error number " << e << endl;
    }
    cout << "End of program.\n";
    int newWaitTime = 12;
    try
    {
        if (newWaitTime > 30)
        {
            throw newWaitTime;
        }
        cout << "Wait time = " << newWaitTime << endl;
        if (newWaitTime > 0)
        {
            throw 99;
        }
    }
    catch (int e)
    {
        cout << "Too long to wait - error number " << e << endl;
    }
    /**
     * @brief The throw statement is used to signal an exception.
     * When a throw statement is executed, the program stops executing the current function and
     * returns to the calling function.
     * The try block from above is used to catch the exception.
     * The catch block is used to handle the exception.
     * The catch-block parameter from the above exercise is an int.
     */
    /**
     * test NoMilk class
    */
    NoMilk<int> nm(rand() % 10);
    cout << nm;
    cout << nm.getCount() << endl;
    return 0;
}
