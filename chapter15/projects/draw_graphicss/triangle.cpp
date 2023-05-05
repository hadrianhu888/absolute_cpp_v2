/**
 * @file triangle.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include "figure.h"
#include "triangle.h"

using namespace std;

Triangle::Triangle()
{
    base = 0;
    height = 0;
}

Triangle::Triangle(double x, double y, double base, double height): Figure(x, y)
{
    this->base = base;
    this->height = height;
}

double Triangle::getBase() const
{
    return base;
}

void Triangle::setBase(double base)
{
    this->base = base;
}

double Triangle::getHeight() const
{
    return height;
}

void Triangle::setHeight(double height)
{
    this->height = height;
}

void Triangle::draw() const
{
    cout << "Drawing a Triangle at:(" << getX() << ", " << getY() << "), base " << base << ", height " << height << endl;
}

string Triangle::drawTriangleGraphically(const string& vertex) const
{
    return "Drawing a Triangle at:(" + to_string(getX()) + ", " + to_string(getY()) + "), base " + to_string(base) + ", height " + to_string(height) + "\n" + vertex + "\n";
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < base; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < base; j++)
        {
            if(i == height - 1)
            {
                cout << "*";
            }
            else if(j == 0 || j == base - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

Triangle::~Triangle()
{
}

/**
 * @file rectangle.h
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 */
