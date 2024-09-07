#ifndef __ECS_H__
#define __ECS_H__

#include <bitset>
#include <vector>


#define MAX_COMPONENTS 32

///////////////////////////////////////////////////////////////////////////////
// Signature
///////////////////////////////////////////////////////////////////////////////
// We use the bitset (1s and 0s) to keep track of which components an entity
// has, and also helps keep track of which entities a system is interested in)
///////////////////////////////////////////////////////////////////////////////
typedef std::bitset<MAX_COMPONENTS> Signature;


///////////////////////////////////////////////////////////////////////////////
// 
///////////////////////////////////////////////////////////////////////////////
template <typename T>
class Component
{
private:
    static int componentId;

public:
    // Return the unique id of Component<T>
    static int GetId()
    {
        static auto id = ++componentId;
        return id;
    }

    bool operator==(const Component &component)
    {
        return GetId() == component.GetId();
    }

    bool operator!=(const Component &component)
    {
        return GetId() != component.GetId();
    }

    bool operator>(const Component &component)
    {
        return GetId() > component.GetId();
    }

    bool operator<(const Component &component)
    {
        return GetId() < component.GetId();
    }
};

///////////////////////////////////////////////////////////////////////////////
// 
///////////////////////////////////////////////////////////////////////////////
class Entity
{
private:
    int id;

public:
    Entity(const int id): id(id) {};

    Entity(const Entity &entity) = default;

    int GetId() const { return this->id; }

    Entity& operator=(const Entity &entity) = default;

    bool operator==(const Entity &entity)
    {
        return this->GetId() == entity.GetId();
    }

    bool operator!=(const Entity &entity)
    {
        return this->GetId() != entity.GetId();
    }

    bool operator>(const Entity &entity)
    {
        return this->GetId() > entity.GetId();
    }

    bool operator<(const Entity &entity)
    {
        return this->GetId() < entity.GetId();
    }
};

///////////////////////////////////////////////////////////////////////////////
// System
///////////////////////////////////////////////////////////////////////////////
// The system processes entities that contain a specific signature
///////////////////////////////////////////////////////////////////////////////
class System
{
private:
    // Which components an entity must have for the system to consider the entity
    Signature componentSignature;
    // List of all entities that the system is interested in
    std::vector<Entity> entities;

public:
    System() = default;
    ~System() = default;

    void AddEntityToSystem(Entity entity);
    void RemoveEntityFromSystem(Entity entity);
    std::vector<Entity> GetSystemEntities() const;
    Signature GetComponentSignature() const;
};

class Registry
{};

#endif // __ECS_H__