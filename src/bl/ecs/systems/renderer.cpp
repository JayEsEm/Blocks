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
    world.system()
        .kind(flecs::OnStore)
        .with<bl::ecs::drawable>()
        .iter([&](flecs::iter& iter) { render(iter); });
}

void bl::ecs::renderer::render(flecs::iter& iter)
{
    (void)(iter);
}
