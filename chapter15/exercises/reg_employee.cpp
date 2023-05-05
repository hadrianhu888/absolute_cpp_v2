/**
 * @file reg_employee.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "employee.h"
#include "reg_employee.h"

using namespace std;

RegEmployee::RegEmployee() : Employee(), salary(0) {}

RegEmployee::RegEmployee(string name, string ssn, double salary) : Employee(name, ssn), salary(salary) {}

string RegEmployee::get_name() const {
    return name;
}

void RegEmployee::set_name(string new_name) {
    name = new_name;
}

double RegEmployee::get_salary() const {
    return salary;
}

void RegEmployee::set_salary(double new_salary) {
    salary = new_salary;
}

double RegEmployee::get_net_pay() const {
    return net_pay;
}

void RegEmployee::set_net_pay(double new_net_pay) {
    net_pay = new_net_pay;
}

int RegEmployee::get_ssn() const {
    return ssn;
}

void RegEmployee::set_ssn(int new_ssn) {
    ssn = new_ssn;
}

void RegEmployee::print_check() {
    set_net_pay(salary);
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << get_name() << endl;
    cout << "The sum of " << get_net_pay() << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Salaried Employee. Regular Pay: " << salary << endl;
    cout << "_________________________________________________\n";
}
