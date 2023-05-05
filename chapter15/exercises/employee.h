/**
 * @file Employee.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include "Employee.h"

using namespace std;

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

#endif // EMPLOYEE_H
