#include "node.h"


// CONSTRUCTOR & DESTRUCTOR //
Node::Node(const NODE_TYPE type, const std::string name, const int id) : type(type), name(name), ID(id), parent(nullptr) {}

Node::~Node() {
    std::cout << "\tNode(" << this->ID << ") : " << this->name << " destroyed" << std::endl;
}


// GETTERS //
std::vector<Node*> Node::getChildren() const {
    return this->children;
}

Node* Node::getParent() const {
    return this->parent;
}

std::string Node::getName() const {
    return this->name;
}


// SETTERS //
void Node::addChild(Node* node) {
    this->children.push_back(node);
    node->setParent(this);
}

void Node::setParent(Node* node) {
    this->removeParent();
    this->parent = node;
}

void Node::removeChild(Node* node) {
    for (unsigned i = 0; i < children.size(); i++) {
        if (this->children[i] == node) {
            this->children[i] = nullptr;
            return;
        }
    }
    throw std::runtime_error("Node not found");
}

void Node::removeParent() {
    this->parent = nullptr;
}


// MISC OPERATORS //
std::ostream& operator << (std::ostream& os, Node& node) {
    os << "(";
    os << "id: " << node.ID << ", name: " << node.name << ", type: " << node.type;
    if (node.parent != nullptr) { os << ", parent: " << node.parent->ID; }
    else { os << ", parent: null"; }
    os << ", children: ";
    if (node.children.size() > 0) {
        for (auto& child : node.children) { os << child->ID << ", "; }
    }
    else { os << "null"; }
    os << ")";
    return os;
}