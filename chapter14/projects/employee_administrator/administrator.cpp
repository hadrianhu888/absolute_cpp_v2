/**
 * @file administrator.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "administrator.h"
#include "employee.cpp"
#include "salaried_employee.cpp"

using namespace std;
using namespace emp;
using namespace sal_emp;
using namespace admin;

administrator::administrator()
{
    first_name = "";
    middle_name = "";
    last_name = "";
    employee_id = 0;
    sin = 0;
    address = "";
    salary = 0.0;
    title = "";
    responsibility = "";
    supervisor = "";
}

administrator::administrator(string first_name,
                             string middle_name,
                             string last_name,
                             long int employee_id,
                             long int sin,
                             string address,
                             long double salary,
                             string title,
                             string responsibility,
                             string supervisor)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
    this->salary = salary;
    this->title = title;
    this->responsibility = responsibility;
    this->supervisor = supervisor;
}

string administrator::setTitle(string title)
{
    this->title = title;
}

string administrator::getTitle() const
{
    return title;
}

string administrator::setResponsibility(string )
{
    this->responsibility = responsibility;
}

string administrator::getResponsibility() const
{
    return responsibility;
}

string administrator::setSupervisor(string supervisor)
{
    this->supervisor = supervisor;
}

string administrator::getSupervisor() const
{
    return supervisor;
}

administrator administrator::getAdministrator() const
{
    return *this;
}

administrator administrator::copy()
{
    return *this;
}

administrator administrator::deleteFromFile(string filename)
{
    return *this;
}

administrator administrator::searchEmployee(string employee_id, string address)
{
    return *this;
}

administrator administrator::updateEmployee(string employee_id, string address)
{
    return *this;
}

administrator administrator::displayAllEmployees()
{
    return *this;
}

administrator::~administrator()
{
    cout << "Destructor called for administrator" << endl;
}

double administrator::setAnnual_Salary(double salary)
{
    this->salary = salary;
}

double administrator::getAnnual_Salary() const
{
    return salary;
}
