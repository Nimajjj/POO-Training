#pragma once
#include "../node.h"

class PhysicsBody : public Node {
public:
    PhysicsBody(const NODE_TYPE type, const std::string name, const int id);

protected:
    int CollisionObject;
};