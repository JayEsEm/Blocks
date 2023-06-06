#include "bl/ecs/ent/block.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"

namespace bl::ecs::ent
{
    namespace block
    {
        entt::entity add_to(entt::registry& world)
        {
            auto ent = world.create();

            world.emplace<cmp::block>(ent, 0U, cmp::block::shape::o);
            world.emplace<cmp::grid::cell>(ent, 0U, 0U);

            return ent;
        }
    }
}