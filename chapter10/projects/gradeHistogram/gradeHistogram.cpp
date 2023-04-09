/**
 * @file gradeHistogram.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(int argc, char **argv);

class gradeHistogram
{
private:
    vector<int> grades;
    int grade;
    int bins;
    array<int, 11> histogram;
public:
    gradeHistogram();
    void getGrades();
    void getBins();
    void printHistogram();
    ~gradeHistogram();
};

gradeHistogram::gradeHistogram()
{
    this->bins = 0;
    this->grade = 0;
    this->histogram = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

void gradeHistogram::getGrades()
{
    cout << "Enter grades (-1 to quit): ";
    while (grade != -1)
    {
        cin >> grade;
        if (grade != -1)
        {
            grades.push_back(grade);
        }
    }
}

void gradeHistogram::getBins()
{
    cout << "Enter number of bins: ";
    cin >> bins;
}

void gradeHistogram::printHistogram()
{
    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i] >= 0 && grades[i] <= 10)
        {
            histogram[0]++;
        }
        else if (grades[i] >= 11 && grades[i] <= 20)
        {
            histogram[1]++;
        }
        else if (grades[i] >= 21 && grades[i] <= 30)
        {
            histogram[2]++;
        }
        else if (grades[i] >= 31 && grades[i] <= 40)
        {
            histogram[3]++;
        }
        else if (grades[i] >= 41 && grades[i] <= 50)
        {
            histogram[4]++;
        }
        else if (grades[i] >= 51 && grades[i] <= 60)
        {
            histogram[5]++;
        }
        else if (grades[i] >= 61 && grades[i] <= 70)
        {
            histogram[6]++;
        }
        else if (grades[i] >= 71 && grades[i] <= 80)
        {
            histogram[7]++;
        }
        else if (grades[i] >= 81 && grades[i] <= 90)
        {
            histogram[8]++;
        }
        else if (grades[i] >= 91 && grades[i] <= 100)
        {
            histogram[9]++;
        }
        else
        {
            histogram[10]++;
        }
    }
    cout << "Histogram:" << endl;
    for (int i = 0; i < histogram.size(); i++)
    {
        cout << i * 10 << "-" << (i * 10) + 9 << ": ";
        for (int j = 0; j < histogram[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

gradeHistogram::~gradeHistogram()
{
}

int main(int argc, char **argv)
{
    gradeHistogram grades;
    grades.getGrades();
    grades.getBins();
    grades.printHistogram();
    return 0;
}
