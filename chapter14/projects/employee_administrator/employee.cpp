/**
 * @file employee.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "employee.h"
#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;
using namespace emp;

employee::employee()
{
    first_name = "";
    last_name = "";
    middle_name = "";
    address = "";
    employee_id = 0;
    sin = 0;
    salary = 0.0;
}

employee::employee(string first_name,
                   string middle_name,
                   string last_name,
                   long int employee_id,
                   long int sin,
                   string address)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
}

string employee::setFirst_Name(string first_name)
{
    this->first_name = first_name;
}

string employee::getFirst_Name() const
{
    return first_name;
}

string employee::setMiddle_Name(string middle_name)
{
    this->middle_name = middle_name;
}

string employee::getMiddle_Name() const
{
    return middle_name;
}

string employee::setLast_Name(string last_name)
{
    this->last_name = last_name;
}

string employee::getLast_Name() const
{
    return last_name;
}

long int employee::setEmployee_ID(long int employee_id)
{
    this->employee_id = employee_id;
}

long int employee::getEmployee_ID() const
{
    return employee_id;
}

long int employee::setSIN(long int sin)
{
    this->sin = sin;
}

long int employee::getSIN() const
{
    return sin;
}

string employee::setAddress(string address)
{
    this->address = address;
}

string employee::getAddress() const
{
    cout << address << endl;
}

long double employee::setSalary(long double salary)
{
    this->salary = salary;
}

long double employee::getSalary() const
{
    return salary;
}

employee employee::getEmployee() const
{
    return *this;
}

employee employee::copy()
{
    employee copy;
    copy.first_name = first_name;
    copy.middle_name = middle_name;
    copy.last_name = last_name;
    copy.employee_id = employee_id;
    copy.sin = sin;
    copy.address = address;
    copy.salary = salary;
    return copy;
}

employee employee::saveToFile(string filename)
{
    ofstream out_file;
    out_file.open(filename, ios::app);
    out_file << first_name << endl;
    out_file << middle_name << endl;
    out_file << last_name << endl;
    out_file << employee_id << endl;
    out_file << sin << endl;
    out_file << address << endl;
    out_file << salary << endl;
    out_file.close();
    return *this;
}

employee employee::deleteFromFile(string filename)
{
    ofstream out_file;
    out_file.open(filename, ios::app);
    out_file << first_name << endl;
    out_file << middle_name << endl;
    out_file << last_name << endl;
    out_file << employee_id << endl;
    out_file << sin << endl;
    out_file << address << endl;
    out_file << salary << endl;
    out_file.close();
    return *this;
}

employee employee::searchEmployee(string employee_id, string address)
{
    ifstream in_file;
    in_file.open("employee.txt");
    string line;
    while (getline(in_file, line))
    {
        if (line == employee_id)
        {
            cout << "Employee ID: " << line << endl;
            getline(in_file, line);
            cout << "First Name: " << line << endl;
            getline(in_file, line);
            cout << "Middle Name: " << line << endl;
            getline(in_file, line);
            cout << "Last Name: " << line << endl;
            getline(in_file, line);
            cout << "SIN: " << line << endl;
            getline(in_file, line);
            cout << "Address: " << line << endl;
            getline(in_file, line);
            cout << "Salary: " << line << endl;
        }
        else if (line == address)
        {
            cout << "Employee ID: " << line << endl;
            getline(in_file, line);
            cout << "First Name: " << line << endl;
            getline(in_file, line);
            cout << "Middle Name: " << line << endl;
            getline(in_file, line);
            cout << "Last Name: " << line << endl;
            getline(in_file, line);
            cout << "SIN: " << line << endl;
            getline(in_file, line);
            cout << "Address: " << line << endl;
            getline(in_file, line);
            cout << "Salary: " << line << endl;
        }
    }
    in_file.close();
    return *this;
}

employee employee::updateEmployee(string employee_id, string address)
{
    ifstream in_file;
    in_file.open("employee.txt");
    string line;
    while (getline(in_file, line))
    {
        if (line == employee_id)
        {
            cout << "Employee ID: " << line << endl;
            getline(in_file, line);
            cout << "First Name: " << line << endl;
            getline(in_file, line);
            cout << "Middle Name: " << line << endl;
            getline(in_file, line);
            cout << "Last Name: " << line << endl;
            getline(in_file, line);
            cout << "SIN: " << line << endl;
            getline(in_file, line);
            cout << "Address: " << line << endl;
            getline(in_file, line);
            cout << "Salary: " << line << endl;
        }
        else if (line == address)
        {
            cout << "Employee ID: " << line << endl;
            getline(in_file, line);
            cout << "First Name: " << line << endl;
            getline(in_file, line);
            cout << "Middle Name: " << line << endl;
            getline(in_file, line);
            cout << "Last Name: " << line << endl;
            getline(in_file, line);
            cout << "SIN: " << line << endl;
            getline(in_file, line);
            cout << "Address: " << line << endl;
            getline(in_file, line);
            cout << "Salary: " << line << endl;
        }
    }
    in_file.close();
    return *this;
}

employee::~employee()
{
    cout << "Destructor called" << endl;
}
