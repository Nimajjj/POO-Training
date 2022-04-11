#pragma once
#include "vector2d.h"

// structure transform which contain the translation, rotation and scale
typedef struct Transform {
    // ATTRIBUTES //
    Vector2D translation;
    double rotation;
    Vector2D scale;


    // CONSTRUCTORS //
    Transform();
    Transform(const Transform& t);
    Transform(const Vector2D& tr, const double& rot, const Vector2D& sca);


    // DESTRUCTOR //
    ~Transform();
} Transform;
std::ostream& operator << (std::ostream& os, const Transform& t);