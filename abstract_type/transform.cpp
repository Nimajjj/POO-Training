#include "transform.h"

// CONSTRUCTOR //
Transform::Transform() :
    translation(Vector2D(.0, .0)), rotation(.0), scale(Vector2D(1.0, 1.0)) {}
Transform::Transform(const Transform& t) = default;
Transform::Transform(const Vector2D& tr, const double& rot, const Vector2D& sca) :
    translation(tr), rotation(rot), scale(sca) {}


// DESTRUCTOR //
Transform::~Transform() = default;


// MISC OPERATOR ///////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& os, const Transform& t) {
    os << "[(" << t.translation.x << ", " << t.translation.y << "), "
       << t.rotation << ", " << "(" << t.scale.x << ", " << t.scale.y << ")]";
    return os;
}