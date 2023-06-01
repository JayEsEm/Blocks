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
                    float y = pos.y + (h * static_cast<float>(i));

                    bl::color color = get_color_for(grd.data[i][j]);

                    canvas.set_draw_color(color);
                    canvas.fill_rect(x + 1, y + 1, w - 1, h - 1);
                }
            }
        }
    }

    bl::color renderer::get_color_for(bl::ecs::cmp::grid::cell cell) const
    {
        switch (cell)
        {
            case cmp::grid::cell::n:
            {
                return bl::colors::n;
            }
            case cmp::grid::cell::i:
            {
                return bl::colors::i;
            }
            case cmp::grid::cell::j:
            {
                return bl::colors::j;
            }
            case cmp::grid::cell::l:
            {
                return bl::colors::l;
            }
            case cmp::grid::cell::o:
            {
                return bl::colors::o;
            }
            case cmp::grid::cell::s:
            {
                return bl::colors::s;
            }
            case cmp::grid::cell::t:
            {
                return bl::colors::t;
            }
            case cmp::grid::cell::z:
            {
                return bl::colors::z;
            }
            default:
            {
                return bl::colors::n;
            }
        }
    }
}
