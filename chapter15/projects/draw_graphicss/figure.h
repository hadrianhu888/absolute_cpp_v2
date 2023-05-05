/**
 * @file figure.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FIGURE_H
#define FIGURE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include "figure.h"

using namespace std;

class Figure
{
    protected:
        double x;
        double y;
    public:
        Figure();
        Figure(double x, double y);
        double getX() const;
        void setX(double x);
        double getY() const;
        void setY(double y);
        virtual void draw() const = 0;
        virtual ~Figure();
};

#endif // FIGURE_H
