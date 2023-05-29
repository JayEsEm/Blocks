#include "bl/ecs/systems/renderer.hpp"

#include <flecs.h>

#include "bl/canvas.hpp"

bl::ecs::renderer::renderer(bl::canvas& canvas)
    : canvas(canvas)
{
}

void bl::ecs::renderer::install_on(flecs::world& world)
{
    world.system()
         .kind(flecs::OnStore)
         .iter([&](flecs::iter& iter) { this->render(iter); });
}

void bl::ecs::renderer::render(flecs::iter& iter)
{
    (void)(iter);
}
