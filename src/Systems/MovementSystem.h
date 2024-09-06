#ifndef __MOVEMENT_SYSTEM_H__
#define __MOVEMENT_SYSTEM_H__

class MovementSystem: public System
{
public:
    MovementSystem()
    {
        // TODO:
        // RequireComponent<TransformComponent>();
        // RequireComponent<...>();
    }

    ~MovementSystem()
    {}

    void Update()
    {
        // TODO:
        // Loop all the entities that the system is interested in
        // for (auto entity: GetEntities())
        // {
            // TODO: Update entity position based on its velociy
            // every frame of the game loop
        // }
    }
};

#endif // __MOVEMENT_SYSTEM_H__