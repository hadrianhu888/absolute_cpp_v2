/**
 * @file rectangle.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include "figure.h"
#include "rectangle.h"

using namespace std;

class Rectangle: public Figure
{
    private:
        double width;
        double height;
    public:
        Rectangle();
        Rectangle(double x, double y, double width, double height);
        double getWidth() const;
        void setWidth(double width);
        double getHeight() const;
        void setHeight(double height);
        void draw() const;
        string drawRectangleGraphically() const; // This is the new functions
        virtual ~Rectangle();
};

#endif // RECTANGLE_H
