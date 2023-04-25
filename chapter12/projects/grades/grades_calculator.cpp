/**
 * @file grades_calculator.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class student
{
    private:
        string firstName;
        string lastName;
        vector<float> grades;
    public :
        student();
        student(string firstName, string lastName);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void addGrade(float grade);
        string getFirstName();
        string getLastName();
        float getGrade(int index);
        float getAverage();
        void getMinMax(float &min, float &max);
        void displayMinMaxGrades();
        int getNumberOfGrades();
};

student::student()
{
    firstName = "";
    lastName = "";
}

student::student(string firstName, string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
}

void student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void student::addGrade(float grade)
{
    grades.push_back(grade);
}

string student::getFirstName()
{
    return firstName;
}

string student::getLastName()
{
    return lastName;
}

float student::getGrade(int index)
{
    return grades[index];
}

float student::getAverage()
{
    float sum = 0;
    for (int i = 0; i < grades.size(); i++)
    {
        sum += grades[i];
    }
    return sum / grades.size();
}

void student::getMinMax(float &min, float &max)
{
    min = grades[0];
    max = grades[0];
    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i] < min)
        {
            min = grades[i];
        }
        if (grades[i] > max)
        {
            max = grades[i];
        }
    }
}

void student::displayMinMaxGrades()
{
    float min, max;
    getMinMax(min, max);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

int student::getNumberOfGrades()
{
    return grades.size();
}

void openFile(ifstream& file);
void displayFileContents(ifstream& file);
void displayStudentInfo(student& student);
void displayStudentGrades(student& student);
void displayStudentAverage(student& student);

void openFile(ifstream& file)
{
    string fileName;
    cout << "Enter the name of the file: ";
    cin >> fileName;
    file.open(fileName.c_str());
    if (file.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

void displayFileContents(ifstream& file)
{
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
}

void displayStudentInfo(student& student)
{
    cout << "Student: " << student.getFirstName() << " " << student.getLastName() << endl;
}

void displayStudentGrades(student& student)
{
    cout << "Grades: ";
    for (int i = 0; i < student.getNumberOfGrades(); i++)
    {
        cout << student.getGrade(i) << " ";
    }
    cout << endl;
}

void displayStudentAverage(student& student)
{
    cout << "Average: " << student.getAverage() << endl;
}

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    ifstream file;
    openFile(file);
    displayFileContents(file);
    file.close();
    file.open("grades.txt");
    string firstName, lastName;
    float grade;
    vector<student> students;

    while (file >> firstName >> lastName)
    {
        student s(firstName, lastName);
        for (int i = 0; i < 10; i++)
        {
            file >> grade;
            s.addGrade(grade);
        }
        students.push_back(s);
    }

    for (student &s : students)
    {
        displayStudentInfo(s);
        displayStudentGrades(s);
        displayStudentAverage(s);
        s.displayMinMaxGrades();
    }
    return 0;
}
