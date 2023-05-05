/**
 * @file exercise_answers.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

int main(int argc, char **argv);

class Employee
{
    protected:
        string name;
        string description;
        double salary;
    public:
        Employee();
        Employee(string name, string description, double salary);
        string getName() const;
        void setName(string name);
        string getDescription() const;
        void setDescription(string description);
        virtual double getSalary() const;
        virtual void setSalary(double salary);
};

class HourlyEmployee: public Employee
{
    private:
        double hourlyRate;
    public:
        HourlyEmployee();
        HourlyEmployee(string name, string description, double salary, double hourlyRate);
        double getSalary() const;
        void setSalary(double salary);
        bool isBossOf(const Employee& e) const;
};

Employee::Employee()
{
    name = "";
    description = "";
    salary = 0.0;
}

Employee::Employee(string name, string description, double salary)
{
    this->name = name;
    this->description = description;
    this->salary = salary;
}

string Employee::getName() const
{
    return name;
}

void Employee::setName(string name)
{
    this->name = name;
}

string Employee::getDescription() const
{
    return description;
}

void Employee::setDescription(string description)
{
    this->description = description;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

HourlyEmployee::HourlyEmployee()
{
    hourlyRate = 0.0;
}

HourlyEmployee::HourlyEmployee(string name, string description, double salary, double hourlyRate)
{
    this->name = name;
    this->description = description;
    this->salary = salary;
    this->hourlyRate = hourlyRate;
}

double HourlyEmployee::getSalary() const
{
    return salary;
}

void HourlyEmployee::setSalary(double salary)
{
    this->salary = salary;
}

bool HourlyEmployee::isBossOf(const Employee& e) const
{
    return true;
}

int main(int argc, char **argv)
{
    cout << "The difference among the terms virtual function, late binding and dynamic binding is " << endl;
    cout << "That virtual functions is a function that is defined later in the prgoram." << endl;
    cout << "Late binding is a function that is defined later in the program." << endl;
    cout << "Dynamic binding means that the function is dynamically bound." << endl;

    /**
     * @brief test classes from below
     *
     */
    Employee joe("Joe Brown", "123 Main St.", 80000.00);
    HourlyEmployee mary("Mary Smith", "456 Main St.", 15.00, 40.00);
    joe.setSalary(90000.00);
    mary.setSalary(50.00);
    cout << "Joe's salary is " << joe.getSalary() << endl;
    cout << "Mary's salary is " << mary.getSalary() << endl;
    cout << "Mary is boss of Joe: " << mary.isBossOf(joe) << endl;

    /**if we remove the keyword virtual from the class Sale in the constructor, then
     * the virtual function will be removed. */

    /**
     * @brief It is legal to have a pure virtual function in a class.
     *
     *
     */

    /**
     * @brief Employee joe("Joe Brown", "123 Main St.", 80000.00) is legal because
     * the constructor is not a virtual function.
     */
}
