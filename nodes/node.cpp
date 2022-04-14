#include "node.h"


// CONSTRUCTOR & DESTRUCTOR //
Node::Node(const Node* node, const unsigned id) :
    ID(id),
    type(node->type),
    name(node->name),
    parent(node->parent)
{}

Node::Node(const NODE_TYPE type, const std::string name, const int id) :
    type(type),
    name(name),
    ID(id),
    parent(nullptr),
    transform(Transform())
{}

Node::~Node() {
    std::cout << "\tNode(" << this->ID << ") : " << this->name << " destroyed" << std::endl;
}


// GETTERS //
std::vector<Node*> Node::getChildren() const {
    return this->children;
}

const Node* Node::getParent() const {
    return this->parent;
}

Node*& Node::getParent() {
    return this->parent;
}

std::string Node::getName() const {
    return this->name;
}


// SETTERS //
void Node::addChild(Node* node) {
    if (node == this) { throw std::runtime_error("Cannot add self as child"); }
    this->children.push_back(node);
    node->setParent(this);
}

void Node::setParent(Node* node) {
    if (node == this) { throw std::runtime_error("Cannot add self as parent"); }
    this->removeParent();
    this->parent = node;
}

void Node::removeChild(Node* node) {
    for (unsigned i = 0; i < this->children.size(); i++) {
        if (this->children[i] == node) {
            children[i]->removeParent();
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
    if (node.getChildren().size() > 0) {
        os << "( ";
        for (auto& child : node.getChildren()) {
            if (child == nullptr) { continue; }
            os << child->ID << " ";
        }
        os << ")";
    }
    else { os << "null"; }
    os << ")";
    return os;
}