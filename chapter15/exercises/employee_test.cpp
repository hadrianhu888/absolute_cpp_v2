/**
 * @file employee_test.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */


#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "employee.cpp"
#include  "reg_employee.cpp"

using namespace std;

int main(int argc, char **argv)
{
    RegEmployee employee("John", "123-45-6789", 1000);
    employee.print_check();
    return 0;
}
