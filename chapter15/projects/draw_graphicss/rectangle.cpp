/**
 * @file rectangle.cpp
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
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle()
{
    width = 0;
    height = 0;
}

Rectangle::Rectangle(double x, double y, double width, double height): Figure(x, y)
{
    this->width = width;
    this->height = height;
}

double Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setWidth(double width)
{
    this->width = width;
}

double Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setHeight(double height)
{
    this->height = height;
}

void Rectangle::draw() const
{
    cout << "Drawing a Rectangle at:(" << getX() << ", " << getY() << "), width " << width << ", height " << height << endl;
}

string Rectangle::drawRectangleGraphically() const
{
    return "Drawing a Rectangle at:(" + to_string(getX()) + ", " + to_string(getY()) + "), width " + to_string(width) + ", height " + to_string(height) + "\n";
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            cout << "*";
        cout << endl;
    }
}

Rectangle::~Rectangle()
{
}
