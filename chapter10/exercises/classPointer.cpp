/**
 * @file classPointer.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

class Point
{
private:
    double x;
    double y;
    double z;
    public:
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
    double get_z()
    {
        return z;
    }
    void set_x(double x)
    {
        this->x = x;
    }
    void set_y(double y)
    {
        this->y = y;
    }
    void set_z(double z)
    {
        this->z = z;
    }
    double distance(Point *p)
    {
        return sqrt(pow(p->get_x() - x, 2) + pow(p->get_y() - y, 2));
    }
    double three_d_distance(Point *p)
    {
        return sqrt(pow(p->get_x() - x, 2) + pow(p->get_y() - y, 2 + pow(p->get_z()-z,2)));
    }
    double distance(Point p)
    {
        return sqrt(pow(p.get_x() - x, 2) + pow(p.get_y() - y + pow(p.get_z()-z,2), 2));
    }
};

int main(int argc, char **argv)
{
    Point p1(0, 0);
    Point p2(3, 4);
    Point *p3 = new Point(5, 12);
    cout << "Distance between p1 and p2: " << p1.distance(&p2) << endl;
    cout << "Distance between p1 and p3: " << p1.distance(p3) << endl;
    Point *p_array[10] = {(new Point(0, 0)), (new Point(1, 1)), (new Point(2, 2)), (new Point(3, 3)), (new Point(4, 4)), (new Point(5, 5)), (new Point(6, 6)), (new Point(7, 7)), (new Point(8, 8)), (new Point(9, 9))};
    for (int i = 0; i < 10; i++)
    {
        cout << "Distance between p1 and p_array[" << i << "]: " << p1.distance(p_array[i]) << endl;
    }
    Point q1(0, 1, 2);
    Point q2(3, 4, 5);
    Point *q3 = new Point(6, 7, 8);
    cout << "Distance between q1 and q2: " << q1.distance(&q2) << endl;
    cout << "Distance between q1 and q3: " << q1.distance(q3) << endl;
    Point *q_array[10] = {(new Point(0, 1, 2)), (new Point(3, 4, 5)), (new Point(6, 7, 8)), (new Point(9, 10, 11)), (new Point(12, 13, 14)), (new Point(15, 16, 17)), (new Point(18, 19, 20)), (new Point(21, 22, 23)), (new Point(24, 25, 26)), (new Point(27, 28, 29))};
    for (int j = 0; j < 10; j++)
    {
        cout << "Distance between q1 and q_array[" << j << "]: " << q1.three_d_distance(q_array[j]) << endl;
    }
    return 0;
}
