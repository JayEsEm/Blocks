#include "bl/ecs/ent/playfield.hpp"

#include <entt.hpp>

#include "bl/ecs/all.hpp"

void bl::ecs::playfield::add_to(entt::registry& world)
{
    auto const ent = world.create();

    world.emplace<bl::ecs::grid>(ent);
    world.emplace<bl::ecs::position>(ent, 0.f, 0.f);
}
