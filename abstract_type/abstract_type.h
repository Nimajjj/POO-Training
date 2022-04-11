#pragma once

#include <map>
#include "vector2d.h"
#include "transform.h"

enum NODE_TYPE{
    NODE = 0,
    SPRITE,
    COLLISION_SHAPE,
    KINEMATIC_BODY
};