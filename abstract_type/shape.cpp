#include "shape.h"

// SHAPE //
Shape::Shape() : transform(Transform()) {}

Shape::Shape(const Transform& tr) : transform(tr) {}

// RECT //
Rect::Rect() : Shape(), size(Vector2D()) {}

Rect::Rect(const Vector2D& sz) : Shape(), size(sz) {}