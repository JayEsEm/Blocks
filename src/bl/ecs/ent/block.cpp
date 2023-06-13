#include "bl/ecs/ent/block.hpp"

#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"

namespace bl::ecs::ent
{
    namespace block
    {
        entt::entity add_to(entt::registry& world)
        {
            auto ent = world.create();

            world.emplace<cmp::block>(ent);

            return ent;
        }
    }
}
