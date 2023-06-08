#include "bl/ecs/ent/board.hpp"

#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"

namespace bl::ecs::ent
{
    namespace board
    {
        entt::entity add_to(entt::registry& world)
        {
            using namespace bl::ecs::cmp;

            auto ent = world.create();

            world.emplace<gameboard>(ent);
            world.emplace<position>(ent, 0.f, 0.f);
            world.emplace<renderable>(ent);

            return ent;
        }
    }
}
