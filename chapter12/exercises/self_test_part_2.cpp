/**
 * @file self_test_part_2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    cout << "#";
    cout.width(5);
    cout << 123 << "*" << 123 << "*"<< endl;
    cout << "*" << setw(5)<<  123 <<  "*"<<  endl;

    cout<< "*" << setw(5)<<  123 <<endl;
    cout << setw(ios::left);
    cout << "*" << setw(5)<<  123 <<  "*"<<  endl;
    cout.setf(ios::right);
    cout << "*" << setw(5)<<  123 <<  "*"<<  endl;

    cout << "*" << setw(5)<<  123 <<  "*"<<  123 << "*" <<  endl;
    cout << setw(ios::showpos);
    cout << "*" << setw(5)<<  123 <<  "*"<<  123 << "*" <<  endl;
    cout << setw(ios::showpoint);
    cout << "*" << setw(5)<<  123 <<  "*"<<  123 << "*" <<  endl;

    ofstream fout;
    fout.open("stuff.txt");
    fout << "Hello" << endl;
    fout << "World" << endl;
    fout.setf(ios::showpos);
    fout << 123 << endl;
    fout << 123.456 << endl;
    fout.unsetf(ios::showpos);
    fout.setf(ios::left);
    fout << "*" << 123 << "*" << endl;
    fout << "*"<< 123.456 << "*" << endl;
    fout.close();

    fout.open("stuff.txt");
    fout << "*" << setw(5)<<  123 <<  "*"<<  123 << "*" <<  endl;
    fout.close();
    return 0;
}
