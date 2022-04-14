#include <iostream>
#include <string>
#include "debug/debug.h"
#include "abstract_type/abstract_type.h"
#include "handler/node_handler.h"


void test() {
    NodeHandler* master = new NodeHandler;

    KinematicBody* player = dynamic_cast<KinematicBody *>(master->createNode(NODE_TYPE::KINEMATIC_BODY, "Player"));
    Sprite* sprite = dynamic_cast<Sprite *>(master->createNode(NODE_TYPE::SPRITE, "Sprite"));
    CollisionShape* collision = dynamic_cast<CollisionShape *>(master->createNode(NODE_TYPE::COLLISION_OBJECT, "Collision"));

    player->addChild(collision);
    player->addChild(sprite);

    std::cout << "Player: " << *player << std::endl;
    std::cout << "Sprite: " << *sprite << std::endl;
    std::cout << "Collision: " << *collision << std::endl;

    std::cout << std::endl;
    delete master;
}


int main() {
    std::cout << "==NODES TEST==" << std::endl;
    test();
    std::cout << "====FINISH====" << std::endl;
    return 0;
}
