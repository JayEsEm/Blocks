#include "bl/ecs/systems/renderer.hpp"

#include <flecs.h>

#include "bl/canvas.hpp"
#include "bl/ecs/all.hpp"

bl::ecs::renderer::renderer(bl::canvas& canvas)
    : canvas(canvas)
{
}

void bl::ecs::renderer::install_on(flecs::world& world)
{
}
