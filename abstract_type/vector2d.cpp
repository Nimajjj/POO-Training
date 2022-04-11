#include "vector2d.h"

// CONSTRUCTOR //
Vector2D::Vector2D() : x(.0), y(.0) {}
Vector2D::Vector2D(const Vector2D& v) = default;
Vector2D::Vector2D(const double& x, const double& y) : x(x), y(y) {}


// DESTRUCTOR //
Vector2D::~Vector2D() = default;


// + OPERATOR /////////////////////////////////////////////////////////////////
Vector2D Vector2D::operator + (const Vector2D& v) const {
    return {x + v.x, y + v.y};
}

Vector2D Vector2D::operator + (const double& xy) const {
    return {x + xy, y + xy};
}


// += OPERATOR /////////////////////////////////////////////////////////////////
void Vector2D::operator += (const Vector2D& v){
    x += v.x;
    y += v.y;
}

void Vector2D::operator += (const double& xy){
    x += xy;
    y += xy;
}


// - OPERATOR /////////////////////////////////////////////////////////////////
Vector2D Vector2D::operator - (const Vector2D& v) const {
    return {x - v.x, y - v.y};
}

Vector2D Vector2D::operator - (const double& xy) const {
    return {x - xy, y - xy};
}


// -= OPERATOR /////////////////////////////////////////////////////////////////
void Vector2D::operator -= (const Vector2D& v){
    x -= v.x;
    y -= v.y;
}

void Vector2D::operator -= (const double& xy){
    x -= xy;
    y -= xy;
}


// * OPERATOR /////////////////////////////////////////////////////////////////
Vector2D Vector2D::operator * (const Vector2D& v) const {
    return {x * v.x, y * v.y};
}

Vector2D Vector2D::operator * (const double& xy) const {
    return {x * xy, y * xy};
}


// *= OPERATOR /////////////////////////////////////////////////////////////////
void Vector2D::operator *= (const Vector2D& v){
    x *= v.x;
    y *= v.y;
}

void Vector2D::operator *= (const double& xy){
    x *= xy;
    y *= xy;
}


// / OPERATOR /////////////////////////////////////////////////////////////////
Vector2D Vector2D::operator / (const Vector2D& v) const {
    if (v.x == 0 || v.y == 0) { throw std::invalid_argument("Division by zero"); }
    return {x / v.x, y / v.y};
}

Vector2D Vector2D::operator / (const double& xy) const {
    if (xy == 0) { throw std::invalid_argument("Division by zero"); }
    return {x / xy, y / xy};
}


// /= OPERATOR /////////////////////////////////////////////////////////////////
void Vector2D::operator /= (const Vector2D& v){
    if (v.x == 0 || v.y == 0) { throw std::invalid_argument("Division by zero"); }
    x /= v.x;
    y /= v.y;
}

void Vector2D::operator /= (const double& xy){
    if (xy == 0) { throw std::invalid_argument("Division by zero"); }
    x /= xy;
    y /= xy;
}


// MISC OPERATOR ///////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& os, const Vector2D& v){
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
