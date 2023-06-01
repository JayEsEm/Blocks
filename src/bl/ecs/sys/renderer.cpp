#include "bl/ecs/sys/renderer.hpp"

#include <entt.hpp>

#include "bl/canvas.hpp"
#include "bl/colors.hpp"
#include "bl/ecs/all.hpp"
#include "bl/macros.hpp"

namespace bl::ecs::sys
{
    void renderer::update(entt::registry& world, float dt)
    {
        UNUSED_ARG(world);
        UNUSED_ARG(dt);
    }

    void renderer::render(entt::registry& world, bl::canvas& canvas)
    {
        auto view = world.view<cmp::grid, cmp::position, cmp::renderable>();

        for (auto entity : view)
        {
            auto& grd = view.get<cmp::grid>(entity);
            auto& pos = view.get<cmp::position>(entity);

            for (uint i = 0; i < grd.data.size(); i++)
            {
                for (uint j = 0; j < grd.data[i].size(); j++)
                {
                    float w = 20.f;
                    float h = 20.f;

                    float x = pos.x + (w * static_cast<float>(j));
                    float y = pos.y = (h * static_cast<float>(i));

                    canvas.set_draw_color(bl::colors::l);
                    canvas.fill_rect(x, y, w, h);
                }
            }
        }
    }
}
