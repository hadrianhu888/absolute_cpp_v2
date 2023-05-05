/**
 * @file figure.cpp
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

using namespace std;

Figure::Figure()
{
    x = 0;
    y = 0;
}

Figure::Figure(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Figure::getX() const
{
    return x;
}

void Figure::setX(double x)
{
    this->x = x;
}

double Figure::getY() const
{
    return y;
}

void Figure::setY(double y)
{
    this->y = y;
}

Figure::~Figure()
{
}

/**
 * @file rectangle.cpp
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 */
