#pragma once
#include <iostream>
#include "fraction.h"

class Point {
private:
    Fraction
            x,
            y;

public:
    explicit Point(Fraction _x = Fraction(), Fraction _y = Fraction());
    ~Point() = default;

    Point operator + (Point b);
    Point operator - (Point b);
    Fraction operator * (Point b);      //Cross Product
    Point operator * (Fraction rhs);    //Scaling product
    Point& operator = (Point b);

    bool operator == (Point b);
    bool operator != (Point b);

    Point& operator = (Fraction rhs);

    bool operator < (Point rhs);


    Fraction getX() const { return x; }
    Fraction getY() const { return y; }



};

std::istream& operator >> (std::istream& is, Point& p);
std::ostream& operator << (std::ostream& os, Point p);





