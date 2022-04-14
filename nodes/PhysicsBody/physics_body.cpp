#include "physics_body.h"

PhysicsBody::PhysicsBody(const NODE_TYPE type, const std::string name, const int id) : Node(type, name, id), CollisionObject(0) {}