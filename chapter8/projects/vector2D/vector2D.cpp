/**
 * @file vector2D.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class Vector2D
{
    private:
        double x;
        double y;
    public:
        Vector2D();
        Vector2D(double x, double y);
        void set_x(double x);
        void set_y(double y);
        double get_x();
        double get_y();
        double get_magnitude();
        double get_angle();
        double get_norm();
        double get_angle_between(Vector2D v);
        double dot_product(Vector2D v);
        double cross_product(Vector2D v);
        void set_magnitude(double magnitude);
        void set_angle(double angle);
        void add(Vector2D v);
        void subtract(Vector2D v);
        void scale(double scalar);
        void rotate(double angle);
        void print();
        friend Vector2D operator+(Vector2D v1, Vector2D v2);
        friend Vector2D operator-(Vector2D v1, Vector2D v2);
        friend Vector2D operator*(Vector2D v, double scalar);
        friend Vector2D operator*(double scalar, Vector2D v);
        friend Vector2D operator/(Vector2D v, double scalar);
        friend bool operator==(Vector2D v1, Vector2D v2);
        friend bool operator!=(Vector2D v1, Vector2D v2);
        friend bool operator<(Vector2D v1, Vector2D v2);
        friend bool operator<=(Vector2D v1, Vector2D v2);
        friend bool operator>(Vector2D v1, Vector2D v2);
        friend bool operator>=(Vector2D v1, Vector2D v2);
        friend ostream& operator<<(ostream& out, Vector2D v);
        friend istream& operator>>(istream& in, Vector2D& v);
};

Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Vector2D::set_x(double x)
{
    this->x = x;
}

void Vector2D::set_y(double y)
{
    this->y = y;
}

double Vector2D::get_x()
{
    return x;
}

double Vector2D::get_y()
{
    return y;
}

double Vector2D::get_magnitude()
{
    return sqrt(x*x + y*y);
}

double Vector2D::get_angle()
{
    return atan2(y, x);
}

double Vector2D::get_norm()
{
    return sqrt(x*x + y*y);
}

double Vector2D::get_angle_between(Vector2D v)
{
    return acos(dot_product(v) / (get_norm() * v.get_norm()));
}

double Vector2D::dot_product(Vector2D v)
{
    return x*v.x + y*v.y;
}

double Vector2D::cross_product(Vector2D v)
{
    return x*v.y - y*v.x;
}

void Vector2D::set_magnitude(double magnitude)
{
    double angle = get_angle();
    x = magnitude * cos(angle);
    y = magnitude * sin(angle);
}

void Vector2D::set_angle(double angle)
{
    double magnitude = get_magnitude();
    x = magnitude * cos(angle);
    y = magnitude * sin(angle);
}

void Vector2D::add(Vector2D v)
{
    x += v.x;
    y += v.y;
}

void Vector2D::subtract(Vector2D v)
{
    x -= v.x;
    y -= v.y;
}

void Vector2D::scale(double scalar)
{
    x *= scalar;
    y *= scalar;
}

void Vector2D::rotate(double angle)
{
    double magnitude = get_magnitude();
    double current_angle = get_angle();
    x = magnitude * cos(current_angle + angle);
    y = magnitude * sin(current_angle + angle);
}

void Vector2D::print()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

Vector2D operator+(Vector2D v1, Vector2D v2)
{
    return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

Vector2D operator-(Vector2D v1, Vector2D v2)
{
    return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

Vector2D operator*(Vector2D v, double scalar)
{
    return Vector2D(v.x * scalar, v.y * scalar);
}

Vector2D operator*(double scalar, Vector2D v)
{
    return Vector2D(v.x * scalar, v.y * scalar);
}

Vector2D operator/(Vector2D v, double scalar)
{
    return Vector2D(v.x / scalar, v.y / scalar);
}

bool operator==(Vector2D v1, Vector2D v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

bool operator!=(Vector2D v1, Vector2D v2)
{
    return !(v1 == v2);
}

bool operator<(Vector2D v1, Vector2D v2)
{
    return v1.get_norm() < v2.get_norm();
}

bool operator<=(Vector2D v1, Vector2D v2)
{
    return v1.get_norm() <= v2.get_norm();
}

bool operator>(Vector2D v1, Vector2D v2)
{
    return v1.get_norm() > v2.get_norm();
}

bool operator>=(Vector2D v1, Vector2D v2)
{
    return v1.get_norm() >= v2.get_norm();
}

int main(int argc, char **argv)
{
    Vector2D v1(3, 4);
    Vector2D v2(5, 12);
    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
    Vector2D v5 = v1 * 2;
    Vector2D v6 = 2 * v1;
    Vector2D v7 = v1 / 2;
    bool b1 = v1 == v2;
    bool b2 = v1 != v2;
    bool b3 = v1 < v2;
    bool b4 = v1 <= v2;
    bool b5 = v1 > v2;
    bool b6 = v1 >= v2;
    v1.print();
    v2.print();
    v3.print();
    v4.print();
    v5.print();
    v6.print();
    v7.print();
    cout << b1 << endl;
    cout << b2 << endl;
    cout << b3 << endl;
    cout << b4 << endl;
    cout << b5 << endl;
    cout << b6 << endl;
    return 0;
}