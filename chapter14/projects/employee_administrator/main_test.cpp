/**
 * @file main_test.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "administrator.cpp"
#include "employee.cpp"
#include "salaried_employee.cpp"

using namespace std;
using namespace emp;
using namespace sal_emp;
using namespace admin;

int main(int argc, char const *argv[])
{
    administrator admin1("John", "A", "Doe", 123456, 123456789, "123 Main St.", 100000, "CEO", "Everything", "No one");
    cout << admin1.getEmployee_ID() << endl;
    cout << admin1.getSIN() << endl;
    cout << admin1.getSalary() << endl;
    cout << admin1.getTitle() << endl;
    cout << admin1.getResponsibility() << endl;
    cout << admin1.getSupervisor() << endl;
    cout << admin1.getFirst_Name() << endl;
    cout << admin1.getMiddle_Name() << endl;
    cout << admin1.getLast_Name() << endl;
    cout << admin1.getAddress() << endl;
    return 0;
}
