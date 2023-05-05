/**
 * @file circle.cpp
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
#include "circle.h"

using namespace std;

Circle::Circle()
{
    radius = 0;
}

Circle::Circle(double x, double y, double radius): Figure(x, y)
{
    this->radius = radius;
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}

void Circle::draw() const
{
    cout << "Drawing a circle at: (" << getX() << ", " << getY() << "), radius " << radius << endl;
}

string Circle:: drawCircleGraphically() const
{
    return "Drawing a circle at: (" + to_string(getX()) + ", " + to_string(getY()) + "), radius " + to_string(radius);
    for(int i = 0; i < radius; i++)
    {
        for(int j = 0; j < radius; j++)
        {
            if((i - radius) * (i - radius) + (j - radius) * (j - radius) <= radius * radius)
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

Circle::~Circle()
{
}

/**
 * @file rectangle.h
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 */
