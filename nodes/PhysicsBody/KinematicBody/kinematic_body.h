#pragma once
#include "../physics_body.h"

class KinematicBody : public PhysicsBody {
public:
    KinematicBody(const NODE_TYPE type, const std::string name, const int id);

    const Vector2D& moveAndSlide(const Vector2D& velocity);
protected:
};