/**
 * @file figure.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class Figure
{
public:
    Figure(int x, int y);
    void move(int newX, int newY);
    virtual void draw() const = 0;
    virtual ~Figure();
protected:
    int xLL, yLL;
};

Figure::Figure(int x, int y) : xLL(x), yLL(y)
{
    cout << "Figure constructor called" << endl;
}

void Figure::move(int newX, int newY)
{
    xLL = newX;
    yLL = newY;
}

Figure::~Figure()
{
    cout << "Figure destructor called" << endl;
}

class Circle : public Figure
{
public:
    Circle(int x, int y, int r);
    void draw() const;
    ~Circle();
private:
    int radius;
};

Circle::Circle(int x, int y, int r) : Figure(x, y), radius(r)
{
    cout << "Circle constructor called" << endl;
}

void Circle::draw() const
{
    cout << "Drawing a Circle at:(" << xLL << ", " << yLL << "), radius " << radius << endl;
    for (int i = 0; i < 2 * radius; i++)
    {
        for (int j = 0; j < 2 * radius; j++)
        {
            if ((i - radius) * (i - radius) + (j - radius) * (j - radius) < radius * radius)
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
    cout << "Circle destructor called" << endl;
}

class Rectangle : public Figure
{
public:
    Rectangle(int x, int y, int xLen, int yLen);
    void draw() const;
    ~Rectangle();
private:
    int xLen, yLen;
};

Rectangle::Rectangle(int x, int y, int xLen, int yLen) : Figure(x, y), xLen(xLen), yLen(yLen)
{
    cout << "Rectangle constructor called" << endl;
}

void Rectangle::draw() const
{
    cout << "Drawing a Rectangle at:(" << xLL << ", " << yLL << "), xLen " << xLen << ", yLen " << yLen << endl;
    for(int i = 0; i < yLen; i++)
    {
        for(int j = 0; j < xLen; j++)
        {
            if(i == 0 || i == yLen - 1 || j == 0 || j == xLen - 1)
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

Rectangle::~Rectangle()
{
    cout << "Rectangle destructor called" << endl;
}

class Triangle : public Figure
{
public:
    Triangle(int x, int y, int xLen, int yLen);
    void draw() const;
    ~Triangle();
private:
    int xLen, yLen;
};

Triangle::Triangle(int x, int y, int xLen, int yLen) : Figure(x, y), xLen(xLen), yLen(yLen)
{
    cout << "Triangle constructor called" << endl;
}

void Triangle::draw() const
{
    cout << "Drawing a Triangle at:(" << xLL << ", " << yLL << "), xLen " << xLen << ", yLen " << yLen << endl;
    for(int i = 0; i < yLen; i++)
    {
        for(int j = 0; j < xLen; j++)
        {
            if(i == 0 || i == yLen - 1 || j == 0 || j == i)
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
    cout << "Triangle destructor called" << endl;
}

class Line : public Figure
{
public:
    Line(int x, int y, int xLen, int yLen);
    void draw() const;
    ~Line();
private:
    int xLen, yLen;
};

Line::Line(int x, int y, int xLen, int yLen) : Figure(x, y), xLen(xLen), yLen(yLen)
{
    cout << "Line constructor called" << endl;
}

void Line::draw() const
{
    cout << "Drawing a Line at:(" << xLL << ", " << yLL << "), xLen " << xLen << ", yLen " << yLen << endl;
    for(int i = 0; i < yLen; i++)
    {
        for(int j = 0; j < xLen; j++)
        {
            if(i == 0 || i == yLen - 1 || j == 0 || j == i)
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

Line::~Line()
{
    cout << "Line destructor called" << endl;
}

class Ellipse : public Figure
{
public:
    Ellipse(int x, int y, int xLen, int yLen);
    void draw() const;
    ~Ellipse();
private:
    int xLen, yLen;
};

Ellipse::Ellipse(int x, int y, int xLen, int yLen) : Figure(x, y), xLen(xLen), yLen(yLen)
{
    cout << "Ellipse constructor called" << endl;
}

void Ellipse::draw() const
{
    cout << "Drawing a Ellipse at:(" << xLL << ", " << yLL << "), xLen " << xLen << ", yLen " << yLen << endl;
    for(int i = 0; i < yLen; i++)
    {
        for(int j = 0; j < xLen; j++)
        {
            if(i == 0 || i == yLen - 1 || j == 0 || j == i)
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

Ellipse::~Ellipse()
{
    cout << "Ellipse destructor called" << endl;
}

int main(int argc, char **argv)
{
    Figure* figArray[5];
    figArray[0] = new Circle(2, 3, 5);
    figArray[1] = new Rectangle(2, 3, 5, 7);
    figArray[2] = new Triangle(2, 3, 5, 7);
    figArray[3] = new Line(2, 3, 5, 7);
    figArray[4] = new Ellipse(2, 3, 5, 7);
    /**
     * @brief draw graphically
     *
     */

    for (int i = 0; i < 5; i++)
    {
        figArray[i]->draw();
    }

    for (int i = 0; i < 5; i++)
    {
        delete figArray[i];
    }

    return 0;
}
