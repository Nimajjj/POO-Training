#pragma once
#include "../node.h"
#include "../../abstract_type/abstract_type.h"

class CollisionShape : public Node {
public:
    CollisionShape(const NODE_TYPE type, const std::string name, const int id);

    // SETTERS //
    void setShape(Shape*& shp);

    // GETTERS //
    const Shape* getShape() const;
    Shape*& getShape();

protected:
    Shape* shape;
    bool collisionLayer[10]{false};
    bool collisionMask[10]{false};
};
