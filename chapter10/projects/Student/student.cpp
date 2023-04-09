/**
 * @file student.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int id;
    double gpa;
    int numClasses;
    string **classList;
public:
    Student();
    Student(string name, int id, double gpa, int numClasses, string **classList);
    Student CopyData(string name, int id, double gpa, int numClasses, string **classList);
    Student Reset();
    Student getInputs();
    Student getOutputs();
    ~Student();
    void print();
};

Student::Student()
{
    name = "";
    id = 0;
    gpa = 0.0;
    numClasses = 0;
    classList = NULL;
}

Student::Student(string name, int id, double gpa, int numClasses, string **classList)
{
    this->name = name;
    this->id = id;
    this->gpa = gpa;
    this->numClasses = numClasses;
    this->classList = classList;
}

Student Student::CopyData(string name, int id, double gpa, int numClasses, string **classList)
{
    this->name = name;
    this->id = id;
    this->gpa = gpa;
    this->numClasses = numClasses;
    this->classList = classList;
    return *this;
}

Student Student::Reset()
{
    name = "";
    id = 0;
    gpa = 0.0;
    numClasses = 0;
    classList = NULL;
    return *this;
}

Student Student::getInputs()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter GPA: ";
    cin >> gpa;
    cout << "Enter number of classes: ";
    cin >> numClasses;
    classList = new string*[numClasses];
    for (int i = 0; i < numClasses; i++)
    {
        classList[i] = new string[2];
        cout << "Enter class name: ";
        cin >> classList[i][0];
        cout << "Enter class grade: ";
        cin >> classList[i][1];
    }
    return *this;
}

Student Student::getOutputs()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Classes: " << endl;
    for (int i = 0; i < numClasses; i++)
    {
        cout << "\t" << classList[i][0] << " " << classList[i][1] << endl;
    }
    return *this;
}

Student::~Student()
{
    for (int i = 0; i < numClasses; i++)
    {
        delete classList[i];
    }
    delete classList;
}

void Student::print()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Classes: " << endl;
    for (int i = 0; i < numClasses; i++)
    {
        cout << "\t" << classList[i][0] << " " << classList[i][1] << endl;
    }
}

int main(int argc, char **argv)
{
    Student student;
    student.getInputs();
    student.getOutputs();
    return 0;
}
