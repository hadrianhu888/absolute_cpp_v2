/**
 * @file graphics_main.cpp
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
#include "rectangle.h"
#include "triangle.h"

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    Figure* figArray[3];
    figArray[0] = new Circle(2, 3, 5);
    figArray[1] = new Rectangle(2, 3, 5, 7);
    figArray[2] = new Triangle(2, 3, 5, 7);
    /**
     * @brief draw graphically
     *
     */

    for (int i = 0; i < 3; i++)
    {
        figArray[i]->draw();
    }

    for (int i = 0; i < 3; i++)
    {
        delete figArray[i];
    }

    return 0;
}
