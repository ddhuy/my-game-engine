#ifndef __TRANSFORM_COMPONENT_H__
#define __TRANSFORM_COMPONENT_H__

#include <glm/glm.hpp>


class TransformComponent
{
public:
    glm::vec2 position;
    glm::vec2 scale;
    double rotation;
};

#endif // __TRANSFORM_COMPONENT_H__