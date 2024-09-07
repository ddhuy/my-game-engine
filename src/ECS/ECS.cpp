#include <algorithm>
#include "ECS.h"


// TODO: Implement all the functions from ECS.h

void System::AddEntityToSystem(Entity entity)
{
    this->entities.push_back(entity);    
}

void System::RemoveEntityFromSystem(Entity entity)
{
    this->entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity &other) {
        return entity == other;
    }), entities.end());
}

std::vector<Entity> System::GetSystemEntities() const
{
    return this->entities;
}

Signature System::GetComponentSignature() const
{
    return this->componentSignature;
}
