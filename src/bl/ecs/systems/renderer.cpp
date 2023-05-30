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
    using namespace bl::ecs;

    world.system<position, box, color>("Render - Filled")
        .kind(flecs::OnStore)
        .with<drawable>()
        .with<filled>()
        .each(
            [&](position& pos, box& box, color& col)
            {
                canvas.set_draw_color(col);
                canvas.fill_rect(pos.x, pos.y, box.w, box.h);
            }
        );

    world.system<position, box, color>("Render - Hollow")
        .kind(flecs::OnStore)
        .with<drawable>()
        .with<hollow>()
        .each(
            [&](position& pos, box& box, color& col)
            {
                canvas.set_draw_color(col);
                canvas.draw_rect(pos.x, pos.y, box.w, box.h);
            }
        );
}
