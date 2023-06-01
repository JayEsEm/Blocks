#include "bl/scene.hpp"

bl::scene::scene(bl::game& owner)
    : owner(owner)
{
}

void bl::scene::update(float dt)
{
    for (auto&& system : systems)
    {
        system->update(world, dt);
    }
}

void bl::scene::render(bl::canvas& canvas)
{
    for (auto&& system : systems)
    {
        system->render(world, canvas);
    }
}
