/**
 * @file adminstrator.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "employee.cpp"
#include "salaried_employee.cpp"

using namespace std;

namespace admin
{
    class administrator: public sal_emp::salaried_employee
    {
        private:
            string title;
        protected:
            double annual_salary;
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            string supervisor;
            string responsibility;
            administrator();
            administrator(string first_name,
                             string middle_name,
                             string last_name,
                             long int employee_id,
                             long int sin,
                             string address,
                             long double salary,
                             string title,
                             string responsibility,
                             string supervisor)
            long double setSalary(long double salary);
            long double getSalary() const;
            string setTitle(string title);
            string getTitle() const;
            string setSupervisor(string supervisor);
            string getSupervisor() const;
            administrator getEmployee() const;
            administrator copy();
            administrator saveToFile(string filename);
            administrator deleteFromFile(string filename);
            administrator searchEmployee(string employee_id, string address);
            administrator updateEmployee(string employee_id, string address);
            administrator displayAllEmployees();
            administrator getAdministrator() const;
            string setResponsibility(string responsibility);
            string getResponsibility() const;
            void printCheque();
            double setAnnual_Salary(double annual_salary);
            double getAnnual_Salary() const;
            ~administrator();
    };
} // namespace admin

#endif // !ADMINISTRATOR_H
