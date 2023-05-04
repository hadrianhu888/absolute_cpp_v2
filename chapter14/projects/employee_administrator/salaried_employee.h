/**
 * @file salaried_employee.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "employee.cpp"

using namespace std;
using namespace emp;

namespace sal_emp
{
    class salaried_employee: public emp::employee
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            salaried_employee();
            salaried_employee(string first_name,
                              string middle_name,
                              string last_name,
                              long int employee_id,
                              long int sin,
                              string address,
                              long double salary);
            long double setSalary(long double salary);
            long double getSalary() const;
            salaried_employee getEmployee() const;
            salaried_employee copy();
            salaried_employee deleteFromFile(string filename);
            salaried_employee searchEmployee(string employee_id, string address);
            salaried_employee updateEmployee(string employee_id, string address);
            salaried_employee displayAllEmployees();
            ~salaried_employee();
    };
} // namespace sal_emp


#endif // !SALARIED_EMPLOYEE_H
