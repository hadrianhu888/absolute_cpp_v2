/**
 * @file grades.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class Grades_Bar_Graph
{
    private:
        int A;
        int B;
        int C;
        int D;
        int F;
    public:
        Grades_Bar_Graph(int A, int B, int C, int D, int F);
        void print();
        int getA();
        void setA(int A);
        int getB();
        void setB(int B);
        int getC();
        void setC(int C);
        int getD();
        void setD(int D);
        int getF();
        void setF(int F);
        void calculateA();
        void calculateA(int A);
        void calculateB();
        void calculateB(int B);
        void calculateC();
        void calculateC(int C);
        void calculateD();
        void calculateD(int D);
        void calculateF();
        void calculateF(int F);
        void drawGraph();
        void drawGraph(int A, int B, int C, int D, int F);
        void drawBar(int num);
        void drawBar(int num, char c);
};

Grades_Bar_Graph::Grades_Bar_Graph(int A, int B, int C, int D, int F)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->F = F;
}

void Grades_Bar_Graph::print()
{
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "F = " << F << endl;
}

int Grades_Bar_Graph::getA()
{
    return A;
}

void Grades_Bar_Graph::setA(int A)
{
    this->A = A;
}

int Grades_Bar_Graph::getB()
{
    return B;
}

void Grades_Bar_Graph::setB(int B)
{
    this->B = B;
}

int Grades_Bar_Graph::getC()
{
    return C;
}

void Grades_Bar_Graph::setC(int C)
{
    this->C = C;
}

int Grades_Bar_Graph::getD()
{
    return D;
}

void Grades_Bar_Graph::setD(int D)
{
    this->D = D;
}

int Grades_Bar_Graph::getF()
{
    return F;
}

void Grades_Bar_Graph::setF(int F)
{
    this->F = F;
}

void Grades_Bar_Graph::calculateA()
{
    A = A + 1;
}

void Grades_Bar_Graph::calculateA(int A)
{
    this->A = A + 1;
}

void Grades_Bar_Graph::calculateB()
{
    B = B + 1;
}

void Grades_Bar_Graph::calculateB(int B)
{
    this->B = B + 1;
}

void Grades_Bar_Graph::calculateC()
{
    C = C + 1;
}

void Grades_Bar_Graph::calculateC(int C)
{
    this->C = C + 1;
}

void Grades_Bar_Graph::calculateD()
{
    D = D + 1;
}

void Grades_Bar_Graph::calculateD(int D)
{
    this->D = D + 1;
}

void Grades_Bar_Graph::calculateF()
{
    F = F + 1;
}

void Grades_Bar_Graph::calculateF(int F)
{
    this->F = F + 1;
} 

void Grades_Bar_Graph::drawGraph()
{
    cout << "A: ";
    drawBar(A);
    cout << "B: ";
    drawBar(B);
    cout << "C: ";
    drawBar(C);
    cout << "D: ";
    drawBar(D);
    cout << "F: ";
    drawBar(F);
}

void Grades_Bar_Graph::drawGraph(int A, int B, int C, int D, int F)
{
    cout << "A: ";
    drawBar(A);
    cout << "B: ";
    drawBar(B);
    cout << "C: ";
    drawBar(C);
    cout << "D: ";
    drawBar(D);
    cout << "F: ";
    drawBar(F);
}

void Grades_Bar_Graph::drawBar(int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "*";
    }
    cout << endl;
}

void Grades_Bar_Graph::drawBar(int num, char c)
{
    for (int i = 0; i < num; i++)
    {
        cout << c;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Grades_Bar_Graph grades(0,0,0,0,0);
    char grade;
    cout << "Enter a grade (A, B, C, D, or F): ";
    cin >> grade;
    while (grade != 'Q' && grade != 'q')
    {
        switch (grade)
        {
            case 'A':
            case 'a':
                grades.calculateA();
                break;
            case 'B':
            case 'b':
                grades.calculateB();
                break;
            case 'C':
            case 'c':
                grades.calculateC();
                break;
            case 'D':
            case 'd':
                grades.calculateD();
                break;
            case 'F':
            case 'f':
                grades.calculateF();
                break;
            default:
                cout << "Invalid grade entered." << endl;
                break;
        }
        cout << "Enter a grade (A, B, C, D, or F): ";
        cin >> grade;
    }
    grades.drawGraph();
    return 0;
}