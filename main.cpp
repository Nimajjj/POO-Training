#include <iostream>
#include <string>
#include "../src/debug/debug.h"
#include "abstract_type/abstract_type.h"
#include "handler/node_handler.h"


void test() {
    NodeHandler* master = new NodeHandler;

    Node* player = master->createNode(NODE_TYPE::KINEMATIC_BODY, "Player");
    Node* sprite = master->createNode(NODE_TYPE::SPRITE, "Sprite");

    player->addChild(sprite);

    delete master;
}


int main() {
    std::cout << "==NODES TEST==" << std::endl;
    test();
    std::cout << "====FINISH====" << std::endl;
    return 0;
}
