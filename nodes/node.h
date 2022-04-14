#pragma once
#include <string>
#include <vector>
#include "../abstract_type/abstract_type.h"

class Node {
public:
    // PUBLIC ATTRIBUTES //
    const NODE_TYPE type;
    const int ID;

    // CONSTRUCTOR & DESTRUCTOR //
    Node(const NODE_TYPE type, const std::string name, const int id);
    Node(const Node* node, const unsigned id);

    ~Node();

    // SETTERS //
    void addChild(Node* node);
    void removeChild(Node* node);

    // GETTERS //
    std::vector<Node*> getChildren() const;
    Node* getParent() const;
    std::string getName() const;

    // MISC OPERATORS //
    friend std::ostream& operator << (std::ostream& os, Node& node);

protected:
    // PROTECTED ATTRIBUTES //
    std::string name;
    Node* parent;
    std::vector<Node*> children;
    Transform transform;

    // PROTECTED METHODS //
    void setParent(Node* node);
    void removeParent();
};

