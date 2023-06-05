#include "bl/ecs/sys/printer.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"
#include "bl/macros.hpp"

namespace bl::ecs::sys
{
    void printer::update(entt::registry& world, float dt)
    {
        UNUSED_ARG(dt);

        auto fields = world.view<cmp::grid, cmp::playfield>();
        auto blocks = world.view<cmp::block, cmp::grid::cell>();

        for (auto field : fields)
        {
            auto& grid = fields.get<cmp::grid>(field);
            auto& target = fields.get<cmp::playfield>(field).active_block;

            if (target == entt::null)
            {
                continue;
            }

            for (auto block : blocks)
            {
                if (block != target)
                {
                    continue;
                }

                auto const& info = blocks.get<cmp::block>(block);
                auto const& cell = blocks.get<cmp::grid::cell>(block);

                {
                    auto imprint = get_imprint_for(info.type);

                    for (size_t i = 0; i < imprint.size(); i++)
                    {
                        for (size_t j = 0; j < imprint.size(); j++)
                        {
                            grid.data[cell.x + j][cell.y + i] = imprint[i][j];
                        }
                    }
                }
            }
        }
    }

    void printer::render(entt::registry& world, bl::canvas& canvas)
    {
        UNUSED_ARG(world);
        UNUSED_ARG(canvas);
    }

    printer::imprint printer::get_imprint_for(cmp::block::shape shape)
    {
        using enum bl::ecs::cmp::grid::value;

        UNUSED_ARG(shape);

        // clang-format off
        return
        {
            {
                { n, n, n, n },
                { n, o, o, n },
                { n, o, o, n },
                { n, n, n, n },
            }
        };
        // clang-format on
    }
}
