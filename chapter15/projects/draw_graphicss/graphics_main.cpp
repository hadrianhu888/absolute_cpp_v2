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

#include "figure.cpp"
#include "circle.cpp"
#include "rectangle.cpp"
#include "triangle.cpp"

using namespace std;

int main(int argc, char **argv);

void drawFigures(Figure* figArray[], int size);

void drawFigures(Figure* figArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        figArray[i]->draw();
    }
}

string drawCircleObject(Circle* circle)
{
    return circle->drawCircleGraphically();
}

string drawRectangleObject(Rectangle* rectangle)
{
    return rectangle->drawRectangleGraphically();
}

string drawTriangleObject(Triangle* triangle)
{
    return triangle->drawTriangleGraphically("*");
}

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

    /**
     * @brief draw graphically
     *
     */

    Circle circle(2, 3, 5);
    Rectangle rectangle(2, 3, 5, 7);
    Triangle triangle(2, 3, 5, 7);

    cout << circle.drawCircleGraphically() << endl;
    cout << rectangle.drawRectangleGraphically() << endl;
    cout << triangle.drawTriangleGraphically(" * ") << endl;

    return 0;
}
