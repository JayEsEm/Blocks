#include "bl/ecs/ent/block.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"

namespace bl::ecs::ent
{
    namespace block
    {
        void add_to(entt::registry& world)
        {
            auto const ent = world.create();

            world.emplace<cmp::piece>(ent, 0u, cmp::piece::type::o);
        }
    }
}
