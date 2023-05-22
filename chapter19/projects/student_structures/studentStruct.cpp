/**
 * @file studentStruct.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

typedef struct Student
{
    string name;
    int grade;
} Student;

vector<Student> students;
vector<string> student_names;
vector<int> student_grades;

int passing_grade = 60;
int failing_grade = 59;

vector<string> passing_students;
vector<string> failing_students;

int main(int argc, char **argv);
void printStudents(vector<Student> &students);
void sortStudents(vector<Student> &students);
void sortByNames(vector<Student> &students);
void sortByGrades(vector<Student> &students);
void findMaxGrade(vector<Student> &students);
void findMinGrade(vector<Student> &students);
void findAverageGrade(vector<Student> &students);
void generateRandomStudentVectorData(vector<Student> &students, int n);
vector<string> getStudentNames(vector<Student> &students);
vector<int> getStudentGrades(vector<Student> &students);
vector<string> getPassingGrades(vector<Student> &students);
vector<string> getFailingGrades(vector<Student> &students);
void emptyStudentVector (vector<Student> &students);

int main(int argc, char **argv)
{
    int n = 20;
    generateRandomStudentVectorData(students, n);
    printStudents(students);
    sortStudents(students);
    printStudents(students);
    sortByNames(students);
    printStudents(students);
    sortByGrades(students);
    printStudents(students);
    findMaxGrade(students);
    findMinGrade(students);
    findAverageGrade(students);
    cout << "Number of students: " << students.size() << endl;
    student_names = getStudentNames(students);
    cout << "Student names: " << endl;
    student_grades = getStudentGrades(students);
    cout<<  "Passing grade: " << passing_grade << endl;
    passing_students = getPassingGrades(students);
    cout<<  "Failing grade: " << failing_grade << endl;
    failing_students = getFailingGrades(students);
    emptyStudentVector(students);
}

void printStudents(vector<Student> &students)
{
    for (auto &student : students)
    {
        cout << student.name << " " << student.grade << endl;
    }
    cout << endl;
}

void sortStudents(vector<Student> &students)
{
    sort(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.grade < b.grade;
    });
}

void sortByNames(vector<Student> &students)
{
    sort(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.name < b.name;
    });
}

void sortByGrades(vector<Student> &students)
{
    sort(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.grade < b.grade;
    });
}

void findMaxGrade(vector<Student> &students)
{
    auto maxGrade = max_element(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.grade < b.grade;
    });
    cout << "Max grade: " << maxGrade->grade << endl;
}

void findMinGrade(vector<Student> &students)
{
    auto minGrade = min_element(students.begin(), students.end(), [](Student &a, Student &b) {
        return a.grade < b.grade;
    });
    cout << "Min grade: " << minGrade->grade << endl;
}

void findAverageGrade(vector<Student> &students)
{
    double sum = 0;
    for (auto &student : students)
    {
        sum += student.grade;
    }
    cout << "Average grade: " << sum / students.size() << endl;
}

void generateRandomStudentVectorData(vector<Student> &students, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        Student student;
        student.name = "Student" + to_string(i);
        student.grade = rand() % 100;
        students.push_back(student);
    }
}

vector<string> getStudentNames(vector<Student> &students)
{
    vector<string> student_names;
    for (auto &student : students)
    {
        student_names.push_back(student.name);
    }
    return student_names;
}

vector<int> getStudentGrades(vector<Student> &students)
{
    vector<int> student_grades;
    for (auto &student : students)
    {
        student_grades.push_back(student.grade);
    }
    return student_grades;
}

vector<string> getPassingGrades(vector<Student> &students)
{
    vector<string> passing_students;
    for (auto &student : students)
    {
        if (student.grade >= passing_grade)
        {
            passing_students.push_back(student.name);
        }
    }
    /**
     * @brief print students that passed the class
     *
     */
    for(auto &student : passing_students){
        cout << student << endl;
    }
    return passing_students;
}

vector<string> getFailingGrades(vector<Student> &students)
{
    vector<string> failing_students;
    for (auto &student : students)
    {
        if (student.grade <= failing_grade)
        {
            failing_students.push_back(student.name);
        }
    }
    for(auto &student : failing_students){
        cout << student << endl;
    }
    return failing_students;
}

void emptyStudentVector (vector<Student> &students)
{
    students.clear();
}
