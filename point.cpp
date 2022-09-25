//
// Created by Nicolas Ott on 9/23/22.
//
#include "point.h"
#include "fraction.h"

Point::Point(Fraction _x, Fraction _y) {              //Sets x and y coordinates in a single point
    x = _x;
    y = _y;

}

Point Point::operator + (Point b) {
    return  Point(x + b.x, y + b.y);
}

Point Point::operator - (Point b) {
    return  Point(x - b.x, y - b.y);
}

Fraction Point::operator * (Point b) {     //cross product;
    return x * b.y - y * b.x;
}

Point Point::operator * (Fraction rhs) {   //Scaling point by a fraction by multiplication (not the same as cross product)
    return Point(x * rhs, y * rhs);
}
Point& Point::operator = (Point b) {
    x = b.x;
    y = b.y;
    return *this;
}
bool Point::operator == (Point b) {

    return x == b.x && y == b.y;    //Returns true if point a is the same as point b
}

bool Point::operator != (Point b) {

    return x != b.x || y != b.y;    //Returns true if point a is different from point b
}

bool Point::operator < (Point rhs) {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
}

Point& Point::operator = (Fraction rhs) {
    x = rhs;
    y = 1;
    return *this;
}


std::istream& operator >> (std::istream& is, Point& p) {
    Fraction
            x, y;
    char
            lPar, comma, rPar;

    is >> lPar >> x >> comma >> y >> rPar;

    p = Point(x, y);

    return is;
}

std::ostream& operator << (std::ostream& os, Point p) {

    os << "(" << p.getX() << ", " << p.getY() << ") ";

    return os;
}
