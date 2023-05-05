/**
 * @file circle.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include "figure.h"
#include "circle.h"

using namespace std;

class Circle: public Figure
{
    private:
        double radius;
    public:
        Circle();
        Circle(double x, double y, double radius);
        double getRadius() const;
        void setRadius(double radius);
        void draw() const;
        string drawCircleGraphically() const; // This is the new functions
        virtual ~Circle();
};

#endif // CIRCLE_H
