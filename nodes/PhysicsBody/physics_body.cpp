#include "physics_body.h"

PhysicsBody::PhysicsBody(const NODE_TYPE type, const std::string name, const int id) : Node(type, name, id), collisionObjects(std::vector<Node*>{}) {}


void PhysicsBody::addChild(Node* node) {
    if (node == this) { throw std::runtime_error("Cannot add self as child"); }
    if (node->type == NODE_TYPE::COLLISION_OBJECT) {
        this->collisionObjects.push_back(node);
    }
    this->children.push_back(node);
    node->setParent(this);
}


void PhysicsBody::removeChild(Node* node) {
    for (unsigned i = 0; i < this->children.size(); i++) {
        if (this->children[i] == node) {
            children[i]->removeParent();
            this->children[i] = nullptr;
            if (node->type == NODE_TYPE::COLLISION_OBJECT) {
                for (unsigned j = 0; i < this->collisionObjects.size(); j++) {
                    if (this->collisionObjects[j] == node) {
                        this->collisionObjects[j] = nullptr;
                        return;
                    }
                }
                throw std::runtime_error("CollisionObject not found");
            }
            return;
        }
    }
    throw std::runtime_error("Node x not found");
}

std::ostream& operator << (std::ostream& os, PhysicsBody& node) {
    os << "(";
    os << "id: " << node.ID << ", name: " << node.getName() << ", type: " << node.type;
    if (node.getParent() != nullptr) { os << ", parent: " << node.getParent()->ID; }
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

    if (node.collisionObjects.size() > 0) {
        os << ", collisionObjects: ( ";
        for (auto& collisionObject : node.collisionObjects) {
            if (collisionObject == nullptr) { continue; }
            os << collisionObject->ID << " ";
        }
        os << ")";
    }
    else { os << ", collisionObjects: null"; }


    os << ")";
    return os;
}