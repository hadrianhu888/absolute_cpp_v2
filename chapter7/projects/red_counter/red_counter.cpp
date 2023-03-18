/**
 * @file red_counter.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Red_Counter
{
    private:
        int red;
    public:
        Red_Counter(int red);
        void increment1();
        void increment10();
        void increment100();
        void increment1000();
        void decrement1();
        void decrement10();
        void decrement100();
        void decrement1000();
        void reset();
        void overflow();
        void print();
        int getRed();
        void setRed(int red);
};

int main(int argc, char **argv); 

Red_Counter::Red_Counter(int red)
{
    this->red = red;
}

void Red_Counter::increment1()
{
    red++;
}

void Red_Counter::increment10()
{
    red += 10;
}

void Red_Counter::increment100()
{
    red += 100;
}

void Red_Counter::increment1000()
{
    red += 1000;
}

void Red_Counter::decrement1()
{
    red--;
}

void Red_Counter::decrement10()
{
    red -= 10;
}

void Red_Counter::decrement100()
{
    red -= 100;
}

void Red_Counter::decrement1000()
{
    red -= 1000;
}

void Red_Counter::reset()
{
    red = 0;
}

void Red_Counter::overflow()
{
    if (red > 9999)
    {
        red = 0;
    }
    else if (red < 0)
    {
        red = 9999;
    } else if (red == 0)
    {
        red = 0;
    }
    else
    {
        red = red;
    }
}

void Red_Counter::print()
{
    cout << "red = " << red << endl;
}

int Red_Counter::getRed()
{
    return red;
}

void Red_Counter::setRed(int red)
{
    this->red = red;
}

int main(int argc, char **argv) {
    Red_Counter r(0);
    r.print();
    r.increment1();
    r.print();
    r.increment10();
    r.print();
    r.increment100();
    r.print();
    r.decrement1();
    r.print();
    r.decrement10();
    r.print();
    r.decrement100();
    r.print();
    r.increment1000();
    r.increment1000();
    r.print();
    r.decrement1000();
    r.print();
    r.reset();
    r.print();
    r.overflow();
    r.print();
    return 0;
}



