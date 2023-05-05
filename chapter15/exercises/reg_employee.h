/**
 * @file reg_employee.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef REG_EMPLOYEE_H
#define REG_EMPLOYEE_H
#include "F:\\GitHubRepos\\absolute_cpp_v2\\common.hpp"
#include "employee.h"
#include "reg_employee.h"

using namespace std;

class RegEmployee : public Employee {
protected:
    double salary;
    int ssn;
    double net_pay;
    string name;
public:
    RegEmployee();
    RegEmployee(string the_name, string the_ssn, double the_weekly_salary);
    string get_name() const;
    void set_name(string new_name);
    double get_salary() const;
    void set_salary(double new_salary);
    double get_net_pay() const;
    void set_net_pay(double new_net_pay);
    int get_ssn() const;
    void set_ssn(int new_ssn);
    void print_check();
};
#endif // REG_EMPLOYEE_H
