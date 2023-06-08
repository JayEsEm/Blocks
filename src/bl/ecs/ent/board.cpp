#include "bl/ecs/ent/board.hpp"

#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"

namespace bl::ecs::ent
{
    namespace board
    {
        entt::entity add_to(entt::registry& world)
        {
            auto ent = world.create();

            world.emplace<cmp::main::board>(ent);
            world.emplace<cmp::position>(ent, 0.f, 0.f);

            world.emplace<cmp::renderable>(ent);

            return ent;
        }
    }
}
