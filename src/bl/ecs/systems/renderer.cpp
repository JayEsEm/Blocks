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
    world.system<bl::ecs::position, bl::ecs::box, bl::ecs::color>()
        .kind(flecs::OnStore)
        .with<bl::ecs::drawable>()
        .each(
            [&](bl::ecs::position& pos, bl::ecs::box& box, bl::ecs::color& col)
            {
                canvas.set_fill_color(col);
                canvas.draw_rect(pos.x, pos.y, box.w, box.h);
            }
        );
}
