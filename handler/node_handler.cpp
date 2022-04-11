#include "node_handler.h"

std::map<NODE_TYPE, std::string> NODE_TYPE_STRING = {
        {NODE, "NODE"},
        {SPRITE, "SPRITE"},
        {COLLISION_SHAPE, "COLLISION_SHAPE"},
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
Node* NodeHandler::createNode(NODE_TYPE type, std::string name) {
    std::string node_name = (name == "default_node") ? NODE_TYPE_STRING[type] : name;
    nodes.push_back(new Node(type, node_name, nodes.size()));
    return nodes[nodes.size() - 1];
}

Node* NodeHandler::getNode(const unsigned id) const {
    if (id >= nodes.size()) {
        throw std::invalid_argument("NodeHandler::getNode: id out of range");
    }
    return nodes[id];
}


// NODES DELETERS //
void NodeHandler::deleteNode(const int id) {
    if (id >= nodes.size()) { throw std::invalid_argument("NodeHandler::deleteNode: id out of range"); }
    if (nodes[id] == nullptr) { return; }

    if (this->nodes[id]->getParent() != nullptr) {
        this->nodes[id]->getParent()->removeChild(this->nodes[id]);
    }

    std::vector<Node*> children = this->getNode(id)->getChildren();
    if (children.size() > 0) {
        for (unsigned i = 0; i < children.size(); i++) {
            if (children[i] != nullptr) {
                this->deleteNode(children[i]->ID);
            }
        }
    }

    delete nodes[id];
    nodes[id] = nullptr;
}

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