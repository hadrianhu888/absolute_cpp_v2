/**
 * @file triangle.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include "figure.h"
#include "triangle.h"

using namespace std;

class Triangle: public Figure
{
    private:
        double base;
        double height;
    public:
        Triangle();
        Triangle(double x, double y, double base, double height);
        double getBase() const;
        void setBase(double base);
        double getHeight() const;
        void setHeight(double height);
        void draw() const;
        string drawTriangleGraphically(const string& vertex) const; // This is the new functions
        virtual ~Triangle();
};

#endif // TRIANGLE_H
