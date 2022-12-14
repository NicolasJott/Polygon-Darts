#pragma once
#include <iostream>
#include <cstdint> 					// Definitions for data type that prof likes to use. (Size)

//#ifndef _FRACTION_H 				// If not defined, compiler will see everything between if & endif
//#define _FRACTION_H				// If defined, we will see nothing inside



class Fraction {

private:
    int32_t
            numerator,
            denominator;

public:
    explicit Fraction(int32_t _numerator = 0, int32_t _denominator = 1);			// Constructor
    ~Fraction() = default;	 											// Destructor. Purpose is to free memory space / cleanup

    Fraction operator + (Fraction rhs);
    Fraction operator += (Fraction rhs);
    Fraction operator - (Fraction rhs);
    Fraction operator * (Fraction rhs);
    Fraction operator / (Fraction rhs);
    Fraction& operator = (Fraction rhs);

    bool operator == (Fraction rhs);
    bool operator != (Fraction rhs);
    bool operator <= (Fraction rhs);
    bool operator >= (Fraction rhs);
    bool operator < (Fraction rhs);
    bool operator > (Fraction rhs);

    Fraction operator + (int32_t rhs);
    Fraction operator - (int32_t rhs);
    Fraction operator * (int32_t rhs);
    Fraction operator / (int32_t rhs);
    Fraction& operator = (int32_t rhs);

    bool operator != (int32_t rhs);
    bool operator < (int32_t rhs);
    bool operator > (int32_t rhs);
    bool operator <= (int32_t rhs);
    bool operator >= (int32_t rhs);
    bool operator == (int32_t rhs);


    double getNum() const { return numerator; }
    double getDen() const { return denominator; }



};

std::istream& operator >> (std::istream& is, Fraction& f);
std::ostream& operator << (std::ostream& os, Fraction f);

//#endif

