#include "bl/ecs/system.hpp"

#include "bl/macros.hpp"

namespace bl::ecs
{
    void system::update(entt::registry& world, float dt)
    {
        UNUSED_ARG(world);
        UNUSED_ARG(dt);
    }

    void system::render(entt::registry& world, bl::canvas& canvas)
    {
        UNUSED_ARG(world);
        UNUSED_ARG(canvas);
    }
}
