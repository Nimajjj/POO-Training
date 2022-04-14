#include "collision_shape.h"

CollisionShape::CollisionShape(const NODE_TYPE type, const std::string name, const int id) : Node(type, name, id), shape(nullptr) {
    this->collisionLayer[0] = true;
    this->collisionMask[0] = true;
}

void CollisionShape::setShape(Shape*& shp) {
    this->shape = shp;
}


const Shape* CollisionShape::getShape() const {
    return this->shape;
}


Shape*& CollisionShape::getShape() {
    return this->shape;
}