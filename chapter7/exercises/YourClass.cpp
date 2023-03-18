/**
 * @file YourClass.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class YourClass
{
    private:
        int yourVariable;
        char yourOtherVariable;
    public:
        YourClass();
        void doStuff();
        YourClass creator();
        YourClass destructor();
};

int main(int argc, char **argv);

YourClass::YourClass()
{
    yourVariable = 0;
    yourOtherVariable = 'a';
}

void YourClass::doStuff()
{
    cout << "YourClass::doStuff() called" << endl;
}

YourClass creator()
{
    return YourClass();
}

YourClass destructor()
{
    return YourClass();
}



int main(int argc, char **argv) {
    YourClass yourClass;
    yourClass.doStuff();
    return 0;
} 

//A Default Constructor is a constructor that takes no arguments. It is used to initialize the object to a default state.
//A Copy Constructor is a constructor that takes an object of the same class as an argument. It is used to initialize the object to the state of the argument object.
//A Destructor is a special member function that is called when an object is destroyed. It is used to release any resources that the object may have acquired during its lifetime.
//A Constructor is a special member function that is called when an object is created. It is used to initialize the object to a specific state.
//A Member Function is a function that is a member of a class. It is used to perform operations on the object.
//A Member Variable is a variable that is a member of a class. It is used to store information about the object.



