#pragma once
#include <iostream>

typedef struct Vector2D {
    // ATTRIBUTES //
    double x;
    double y;


    // CONSTRUCTORS //
    Vector2D();
    Vector2D(const Vector2D& v);
    Vector2D(const double& x, const double& y);


    // DESTRUCTOR //
    ~Vector2D();

    // OPERATORS //
    Vector2D operator + (const Vector2D& v) const;
    Vector2D operator + (const double& xy) const;
    void operator += (const Vector2D& v2);
    void operator += (const double& xy);

    Vector2D operator - (const Vector2D& v) const;
    Vector2D operator - (const double& xy) const;
    void operator -= (const Vector2D& v2);
    void operator -= (const double& xy);

    Vector2D operator * (const Vector2D& v) const;
    Vector2D operator * (const double& xy) const;
    void operator *= (const Vector2D& v2);
    void operator *= (const double& xy);

    Vector2D operator / (const Vector2D& v) const;
    Vector2D operator / (const double& xy) const;
    void operator /= (const Vector2D& v2);
    void operator /= (const double& xy);
} Vector2D;

// MISC OPERATORS //
std::ostream& operator << (std::ostream& os, const Vector2D& v);
