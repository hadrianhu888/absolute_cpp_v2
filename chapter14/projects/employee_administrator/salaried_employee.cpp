/**
 * @file salaried_employee.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "salaried_employee.h"
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;
using namespace emp;
using namespace sal_emp;

salaried_employee::salaried_employee()
{
    salary = 0.0;
}

salaried_employee::salaried_employee(string first_name,
                                     string middle_name,
                                     string last_name,
                                     long int employee_id,
                                     long int sin,
                                     string address,
                                     long double salary)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
    this->salary = salary;
}

long double salaried_employee::setSalary(long double salary)
{
    this->salary = salary;
}

long double salaried_employee::getSalary() const
{
    return salary;
}

salaried_employee salaried_employee::getEmployee() const
{
    return *this;
}

salaried_employee salaried_employee::copy()
{
    salaried_employee copy = *this;
    return copy;
}

salaried_employee salaried_employee::deleteFromFile(string filename)
{
    ifstream in_file;
    ofstream out_file;
    string line;
    string employee_id;
    string address;
    in_file.open(filename);
    out_file.open("temp.txt");
    cout << "Enter the employee id: ";
    cin >> employee_id;
    cout << "Enter the address: ";
    cin >> address;
    while (getline(in_file, line))
    {
        if (line.find(employee_id) != string::npos && line.find(address) != string::npos)
        {
            continue;
        }
        else
        {
            out_file << line << endl;
        }
    }
    in_file.close();
    out_file.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

salaried_employee salaried_employee::searchEmployee(string employee_id, string address)
{
    ifstream in_file;
    string line;
    in_file.open("salaried_employees.txt");
    while (getline(in_file, line))
    {
        if (line.find(employee_id) != string::npos && line.find(address) != string::npos)
        {
            cout << line << endl;
        }
    }
    in_file.close();
}

salaried_employee salaried_employee::updateEmployee(string employee_id, string address)
{
    ifstream in_file;
    ofstream out_file;
    string line;
    string new_line;
    string new_first_name;
    string new_middle_name;
    string new_last_name;
    long int new_employee_id;
    long int new_sin;
    string new_address;
    long double new_salary;
    in_file.open("salaried_employees.txt");
    out_file.open("temp.txt");
    cout << "Enter the employee id: ";
    cin >> employee_id;
    cout << "Enter the address: ";
    cin >> address;
    cout << "Enter the new first name: ";
    cin >> new_first_name;
    cout << "Enter the new middle name: ";
    cin >> new_middle_name;
    cout << "Enter the new last name: ";
    cin >> new_last_name;
    cout << "Enter the new employee id: ";
    cin >> new_employee_id;
    cout << "Enter the new sin: ";
    cin >> new_sin;
    cout << "Enter the new address: ";
    cin >> new_address;
    cout << "Enter the new salary: ";
    cin >> new_salary;
    while (getline(in_file, line))
    {
        if (line.find(employee_id) != string::npos && line.find(address) != string::npos)
        {
            new_line = new_first_name + " " + new_middle_name + " " + new_last_name + " " + to_string(new_employee_id) + " " + to_string(new_sin) + " " + new_address + " " + to_string(new_salary);
            out_file << new_line << endl;
        }
        else
        {
            out_file << line << endl;
        }
    }
    in_file.close();
    out_file.close();
    remove("salaried_employees.txt");
    rename("temp.txt", "salaried_employees.txt");
}

salaried_employee salaried_employee::displayAllEmployees()
{
    ifstream in_file;
    string line;
    in_file.open("salaried_employees.txt");
    while (getline(in_file, line))
    {
        cout << line << endl;
    }
    in_file.close();
}

salaried_employee::~salaried_employee()
{
    cout << "Destructor called for salaried_employee" << endl;
}
