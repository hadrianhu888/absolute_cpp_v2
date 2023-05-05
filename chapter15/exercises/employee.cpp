/**
 * @file Employee.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Employee.h"
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

// Default constructor
Employee::Employee()
{
    name = "";
    description = "";
    salary = 0.0;
}

// Parameterized constructor
Employee::Employee(string name, string description, double salary)
{
    this->name = name;
    this->description = description;
    this->salary = salary;
}

// Getter for name
string Employee::getName() const
{
    return name;
}

// Setter for name
void Employee::setName(string name)
{
    this->name = name;
}

// Getter for description
string Employee::getDescription() const
{
    return description;
}

// Setter for description
void Employee::setDescription(string description)
{
    this->description = description;
}
