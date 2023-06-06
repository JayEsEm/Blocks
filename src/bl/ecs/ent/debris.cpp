#include "bl/ecs/ent/debris.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"

namespace bl::ecs::ent
{
    entt::entity debris::add_to(entt::registry& world)
    {
        auto ent = world.create();

        return ent;
    }
}
