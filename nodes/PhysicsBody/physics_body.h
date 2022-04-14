#pragma once
#include "../node.h"
#include "../CollisionShape/collision_shape.h"

class PhysicsBody : public Node {
public:
    PhysicsBody(const NODE_TYPE type, const std::string name, const int id);

    void addChild(Node* node);
    void removeChild(Node* node);

    friend std::ostream& operator << (std::ostream& os, PhysicsBody& node);
protected:
    std::vector<Node*> collisionObjects;
};