/**
 * @file employee.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

namespace emp
{
    class employee
    {
        private:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
        public:
            employee();
            employee(string first_name,
                     string middle_name,
                     string last_name,
                     long int employee_id,
                     long int sin,
                     string address);
            string setFirst_Name(string first_name);
            string getFirst_Name() const;
            string setMiddle_Name(string middle_name);
            string getMiddle_Name() const;
            string setLast_Name(string last_name);
            string getLast_Name() const;
            long int setEmployee_ID(long int employee_id);
            long int getEmployee_ID() const;
            long int setSIN(long int sin);
            long int getSIN() const;
            string setAddress(string address);
            string getAddress() const;
            long double setSalary(long double salary);
            long double getSalary() const;
            employee getEmployee() const;
            employee copy();
            employee saveToFile(string filename);
            employee deleteFromFile(string filename);
            employee searchEmployee(string employee_id, string address);
            employee updateEmployee(string employee_id, string address);
            ~employee();
    };
}

#endif /* EMPLOYEE_H */
