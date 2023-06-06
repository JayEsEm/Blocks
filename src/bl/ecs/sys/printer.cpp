#include "bl/ecs/sys/printer.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"
#include "bl/macros.hpp"

namespace bl::ecs::sys
{
    void printer::update(entt::registry& world, float dt)
    {
        UNUSED_ARG(dt);

        print_block(world);
        print_debris(world);
    }

    void printer::print_block(entt::registry& world)
    {
        auto fields = world.view<cmp::grid, cmp::playfield>();
        auto blocks = world.view<cmp::block, cmp::grid::cell>();

        for (auto field : fields)
        {
            auto& grid = fields.get<cmp::grid>(field);
            auto& target = fields.get<cmp::playfield>(field).block;

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
            }
        }
    }

    void printer::print_debris(entt::registry& world)
    {
        UNUSED_ARG(world);
    }

    void printer::merge(cmp::grid const& source, cmp::grid& target)
    {
        using enum cmp::grid::value;

        for (size_t i = 0; i < source.data.size(); i++)
        {
            for (size_t j = 0; j < source.data[i].size(); j++)
            {
                auto value = source.data[i][j];

                if (value == n)
                {
                    continue;
                }

                target.data[i][j] = value;
            }
        }
    }
}
