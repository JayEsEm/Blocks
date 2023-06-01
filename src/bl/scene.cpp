#include "bl/scene.hpp"

namespace bl
{
    scene::scene(bl::game& owner)
        : owner(owner)
    {
    }

    void scene::update(float dt)
    {
        for (auto&& system : systems)
        {
            system->update(world, dt);
        }
    }

    void scene::render(bl::canvas& canvas)
    {
        for (auto&& system : systems)
        {
            system->render(world, canvas);
        }
    }
}
