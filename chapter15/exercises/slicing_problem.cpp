/**
 * @file slicing_problem.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
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
        virtual ~Employee();
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
        virtual ~HourlyEmployee();
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

Employee::~Employee()
{
    cout << "Employee destructor called" << endl;
}

HourlyEmployee::HourlyEmployee()
{
    hourlyRate = 0.0;
}

HourlyEmployee::HourlyEmployee(string name, string description, double salary, double hourlyRate): Employee(name, description, salary)
{
    this->hourlyRate = hourlyRate;
}

double HourlyEmployee::getSalary() const
{
    return hourlyRate * 40 * 52;
}

void HourlyEmployee::setSalary(double salary)
{
    hourlyRate = salary / (40 * 52);
}

bool HourlyEmployee::isBossOf(const Employee& e) const
{
    return false;
}

HourlyEmployee::~HourlyEmployee()
{
    cout << "HourlyEmployee destructor called" << endl;
}

int main(int argc, char **argv)
{
    HourlyEmployee* he = new HourlyEmployee("John", "Manager", 100000, 50);
    Employee* e = he;
    cout << e->getSalary() << endl;
    delete e;
    return 0;
}

/**
 * @brief The slicing problem occurs when a derived class object is assigned to a base class object.
 * The base class object will only contain the base class part of the derived class object.
 * The derived class part of the derived class object will be sliced off.
 * This is because the base class object does not have the derived class part.
 * The derived class part is not copied to the base class object.
 * The derived class part is sliced off.
 * The derived class part is lost.
 *
 */

/**
 * @brief The problem with legal assignment of a derived class object to a base class object is that
 *  the derived class part of the derived class object is sliced off.
 */

/**
 * @brief IF the derived class and base class have the same signature for a function, then the derived class function will be called.
 *
 */
