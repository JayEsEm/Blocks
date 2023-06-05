#include "bl/ecs/ent/block.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"

namespace bl::ecs::ent
{
    namespace block
    {
        entt::entity add_to(entt::registry& world)
        {
            auto const ent = world.create();

            world.emplace<cmp::grid::cell>(ent, 0U, 0U);
            world.emplace<cmp::piece>(ent, 0U, cmp::piece::shape::o);

            return ent;
        }
    }
}
