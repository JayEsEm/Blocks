#include "bl/ecs/sys/printer.hpp"

#include "bl/macros.hpp"

namespace bl::ecs::sys
{
    void printer::update(entt::registry& world, float dt)
    {
        UNUSED_ARG(world);
        UNUSED_ARG(dt);
    }

    void printer::render(entt::registry& world, bl::canvas& canvas)
    {
        UNUSED_ARG(world);
        UNUSED_ARG(canvas);
    }

    printer::imprint printer::get_imprint_for(cmp::block::shape shape)
    {
        UNUSED_ARG(shape);

        return {};
    }
}
