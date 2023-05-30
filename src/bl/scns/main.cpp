#include "bl/scns/main.hpp"

#include "bl/colors.hpp"
#include "bl/ecs/all.hpp"
#include "bl/game.hpp"

bl::scns::main::main(bl::game& game)
    : null(game)
{
}

void bl::scns::main::init()
{
    {
        flecs::entity r = world.entity();

        r.add<bl::ecs::renderable>();

        r.set<bl::ecs::position>({ 0.f, 0.f });
        r.set<bl::ecs::rectangle>({ 64.f, 64.f, true, bl::colors::white });
    }

    {
        add_render_system<bl::ecs::renderer>();
    }
}
