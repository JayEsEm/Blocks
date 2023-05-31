#include "bl/ecs/logic/playground.hpp"

#include <flecs.h>

#include "bl/colors.hpp"
#include "bl/ecs/all.hpp"

void bl::ecs::playground::add_to(flecs::world& world)
{
    flecs::entity playground = world.entity();

    for (auto i = 0; i < 18; i++)
    {
        for (auto j = 0; j < 10; j++)
        {
            flecs::entity cell = world.entity();

            flecs::entity bg = world.entity();
            flecs::entity fg = world.entity();

            float x = static_cast<float>(19 * j);
            float y = static_cast<float>(19 * i);

            bg.set<bl::ecs::position>({ x, y });
            fg.set<bl::ecs::position>({ x, y });

            bg.add<bl::ecs::renderable>();
            fg.add<bl::ecs::renderable>();

            bg.set<bl::ecs::rectangle>({ 20, 20, true, bl::colors::gray });
            fg.set<bl::ecs::rectangle>({ 20, 20, false, bl::colors::white });

            bg.child_of(cell);
            fg.child_of(cell);

            cell.child_of(playground);
        }
    }
}
