#include "kinematic_body.h"

KinematicBody::KinematicBody(const NODE_TYPE type, const std::string name, const int id) : PhysicsBody(type, name, id) {}

const Vector2D& KinematicBody::moveAndSlide(const Vector2D& velocity) {
    this->transform.translation += velocity;
    return this->transform.translation;
}