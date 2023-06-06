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

            return ent;
        }
    }
}
