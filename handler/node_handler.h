#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../nodes/node.h"
#include "../nodes/sprite/sprite.h"
#include "../nodes/PhysicsBody/KinematicBody/kinematic_body.h"

class NodeHandler {
public:
    NodeHandler();
    ~NodeHandler();

    Node*& createNode(const NODE_TYPE type, const std::string name = "default_node");
    Node* getNode(const unsigned id) const;
    void deleteNode(Node* node);

private:
    std::vector<Node*> nodes;
};