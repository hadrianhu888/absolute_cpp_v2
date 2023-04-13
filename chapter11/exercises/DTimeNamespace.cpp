/**
 * @file DTimeNamespace.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>

using namespace std;

namespace DTimeNamespace
{
    class DTime
    {
    private:
        int hour;
        int minute;
        int second;
    public:
        DTime(int h, int m, int s);
        void display();
    };
}

DTimeNamespace::DTime::DTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void DTimeNamespace::DTime::display()
{
    cout << hour << ":" << minute << ":" << second << endl;
}

int main(int argc, char **argv)
{
    DTimeNamespace::DTime dt(12, 34, 56);
    dt.display();
    return 0;
}
