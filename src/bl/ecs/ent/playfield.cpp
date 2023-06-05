#include "bl/ecs/ent/playfield.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"

namespace bl::ecs::ent
{
    namespace playfield
    {
        entt::entity add_to(entt::registry& world)
        {
            auto const ent = world.create();

            world.emplace<cmp::grid>(ent);
            world.emplace<cmp::position>(ent, 0.f, 0.f);
            world.emplace<cmp::renderable>(ent);

            return ent;
        }
    }
}
