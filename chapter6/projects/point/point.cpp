/**
 * @file point.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Point {
    public:
        void setX(int newX);
        void setY(int newY);
        int getX();
        int getY();
        int setXY(int newX, int newY);
        int getXY(int &x, int &y);
        float distance(int x, int y);
        float distance(Point &p);
        float normalize();
        void print();
    private:
        int x;
        int y;
        float line_distance; // distance from origin
};

int main(int argc,char **argv);

/**
 * @brief function definitions for class Point
 * 
 */

void Point::setX(int newX) { x = newX; }
void Point::setY(int newY) { y = newY; }
int Point::getX() { return x; }
int Point::getY() { return y; }
int Point::setXY(int newX, int newY) {
    x = newX;
    y = newY;
}
int Point::getXY(int &x, int &y) {
    x = this->x;
    y = this->y;
}
float Point::distance(int x, int y) {
    line_distance = sqrt(pow((this->x - x), 2) + pow((this->y - y), 2));
    return line_distance;
}
float Point::distance(Point &p) {
    line_distance = sqrt(pow((this->x - p.x), 2) + pow((this->y - p.y), 2));
    return line_distance;
}
float Point::normalize() {
    line_distance = sqrt(pow(this->x, 2) + pow(this->y, 2));
    return line_distance;
}
void Point::print() { cout << "(" << x << ", " << y << ")" << endl; }

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc,char **argv)
{
    /**
     * @brief Test point class
     * 
     */
    Point p1;
    Point p2;
    p1.setXY(3, 4);
    p2.setXY(5, 12);
    cout << "p1: ";
    p1.print();
    cout << "p2: ";
    p2.print();
    cout << "Distance between p1 and p2: " << p1.distance(p2) << endl;
    cout << "Distance between p1 and (5, 12): " << p1.distance(5, 12) << endl;
    cout << "Distance between p2 and (3, 4): " << p2.distance(3, 4) << endl;
    cout << "Distance between p1 and (0, 0): " << p1.distance(0, 0) << endl;
    cout << "Distance between p2 and (0, 0): " << p2.distance(0, 0) << endl;
    cout << "Distance between p1 and p2: " << p1.distance(p2) << endl;
    cout << "Distance between p1 and (5, 12): " << p1.distance(5, 12) << endl;
    cout << "Distance between p2 and (3, 4): " << p2.distance(3, 4) << endl;
    cout << "Distance between p1 and (0, 0): " << p1.distance(0, 0) << endl;
    cout << "Distance between p2 and (0, 0): " << p2.distance(0, 0) << endl;
    cout << "Distance between p1 and p2: " << p1.distance(p2) << endl;
    cout << "Distance between p1 and (5, 12): " << p1.distance(5, 12) << endl;
    cout << "Distance between p2 and (3, 4): " << p2.distance(3, 4) << endl;
    cout << "Distance between p1 and (0, 0): " << p1.distance(0, 0) << endl;
    cout << "Distance between p2 and (0, 0): " << p2.distance(0, 0) << endl;
    cout << "Distance between p1 and p2: " << p1.distance(p2) << endl;
    cout << "Distance between p1 and (5, 12): " << p1.distance(5, 12) << endl;
    cout << "Distance between p2 and (3, 4): " << p2.distance(3, 4) << endl;
    cout << "Distance between p1 and (0, 0): " << p1.distance(0, 0) << endl;
    cout << "Distance between p2 and (0, 0): " << p2.distance(0, 0) << endl;
    return 0;
}