#include "bl/ecs/sys/renderer.hpp"

#include <entt.hpp>

#include "bl/canvas.hpp"
#include "bl/ecs/all.hpp"
#include "bl/macros.hpp"

namespace bl::ecs::sys
{
    void renderer::render(entt::registry& world, bl::canvas& canvas)
    {
        UNUSED_ARG(world);
        UNUSED_ARG(canvas);
    }
}
