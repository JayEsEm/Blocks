#include "bl/ecs/render/renderer.hpp"

#include <flecs.h>

#include "bl/canvas.hpp"
#include "bl/ecs/all.hpp"

bl::ecs::renderer::renderer(bl::canvas& canvas)
    : system(canvas)
{
}

void bl::ecs::renderer::install_on(flecs::world& world)
{
    world.system<bl::ecs::position, bl::ecs::rectangle>("Renderer")
        .with<bl::ecs::renderable>()
        .kind(flecs::OnStore)
        .each(
            [&](bl::ecs::position& pos, bl::ecs::rectangle& rect)
            {
                canvas.set_draw_color(rect.color);

                if (rect.filled == true)
                {
                    canvas.fill_rect(pos.x, pos.y, rect.w, rect.h);
                }
                else
                {
                    canvas.draw_rect(pos.x, pos.y, rect.w, rect.h);
                }
            }
        );
}
