#include "node_handler.h"

std::map<NODE_TYPE, std::string> NODE_TYPE_STRING = {
        {NODE, "NODE"},
        {SPRITE, "SPRITE"},
        {COLLISION_OBJECT, "COLLISION_OBJECT"},
        {KINEMATIC_BODY, "KINEMATIC_BODY"}
};


// CONSTRUCTOR & DESTRUCTOR //
NodeHandler::NodeHandler() : nodes(std::vector<Node*>()){
    std::cout << "NodeHandler created" << std::endl;
}

NodeHandler::~NodeHandler() {
    std::cout << "Destroying NodeHandler" << std::endl;

    if (this->nodes.size() > 0) {
        std::cout << "Destroying children" << std::endl;
        for (auto node : nodes) {
            if (node != nullptr) {
                this->deleteNode(node);
            }
        }
        std::cout << "Children destroyed " << std::endl;
    }

    std::cout << "NodeHandler destroyed" << std::endl;
}


// PUBLIC METHODS //
Node*& NodeHandler::createNode(NODE_TYPE type, std::string name) {
    std::string node_name = (name == "default_node") ? NODE_TYPE_STRING[type] : name;

    switch (type) {
        case NODE_TYPE::SPRITE:
            nodes.push_back(new Sprite(type, node_name, nodes.size()));
            break;
        case NODE_TYPE::KINEMATIC_BODY:
            nodes.push_back(new KinematicBody(type, node_name, nodes.size()));
            break;
        case NODE_TYPE::COLLISION_OBJECT:
            nodes.push_back(new CollisionShape(type, node_name, nodes.size()));
            break;
        default:
            nodes.push_back(new Node(type, node_name, nodes.size()));
            break;
    }

    return nodes[nodes.size() - 1];
}

Node* NodeHandler::getNode(const unsigned id) const {
    if (id >= nodes.size()) {
        throw std::invalid_argument("NodeHandler::getNode: id out of range");
    }
    return nodes[id];
}


// NODES DELETER //
void NodeHandler::deleteNode(Node* node) {
    if (node == nullptr) { return; }

    if (node->getParent() != nullptr) {
        node->getParent()->removeChild(node);
    }

    std::vector<Node*> children = node->getChildren();
    if (children.size() > 0) {
        for (unsigned i = 0; i < children.size(); i++) {
            if (children[i] != nullptr) {
                this->deleteNode(children[i]);
            }
        }
    }

    nodes[node->ID] = nullptr;
    delete node;
}