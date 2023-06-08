#include "bl/ecs/ent/debris.hpp"

#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"

namespace bl::ecs::ent
{
    entt::entity debris::add_to(entt::registry& world)
    {
        using namespace bl::ecs::cmp;

        auto ent = world.create();

        world.emplace<gameboard>(ent);

        return ent;
    }
}
