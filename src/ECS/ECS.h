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
class IComponent
{
protected:
    static int componentId;
};

class Component: public IComponent
{
public:
    int GetId() const
    {
        static const int id = ++componentId;
        return id;
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

    int GetId() const { return this->id; }
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