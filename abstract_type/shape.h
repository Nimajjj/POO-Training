#pragma once
#include "transform.h"
#include "vector2d.h"

struct Shape {
    Shape();
    Shape(const Transform& tr);
    virtual ~Shape() = default;

    Transform transform;
};


struct Rect : public Shape {
    Rect();
    ~Rect() = default;
    Rect(const Vector2D& sz = Vector2D());

    Vector2D size;
};