#pragma once

#include <map>
#include "vector2d.h"
#include "transform.h"
#include "shape.h"

enum NODE_TYPE{
    NODE = 0,
    SPRITE,
    COLLISION_OBJECT,
    KINEMATIC_BODY
};

