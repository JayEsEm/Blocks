#include "bl/scns/main.hpp"

#include "bl/ecs/all.hpp"
#include "bl/game.hpp"

bl::scns::main::main(bl::game& game)
    : null(game)
{
}

void bl::scns::main::init()
{
    {
        flecs::entity background = world.entity();

        background.add<bl::ecs::drawable>();
        background.add<bl::ecs::filled>();

        background.set<bl::ecs::position>({ 0.f, 0.f });
        background.set<bl::ecs::box>({ 190.f, 342.f });
        background.set<bl::ecs::color>({ 0xDE, 0xDE, 0xDE, 0xFF });
    }

    {
        for (unsigned int i = 0; i < 18; i++)
        {
            for (unsigned int j = 0; j < 10; j++)
            {
                flecs::entity cell = world.entity();

                cell.add<bl::ecs::drawable>();
                cell.add<bl::ecs::hollow>();

                cell.set<bl::ecs::position>({ 19.f * (float)(j), 19.f * (float)(i)});
                cell.set<bl::ecs::box>({ 20.f, 20.f });
                cell.set<bl::ecs::color>({ 0xFF, 0xFF, 0xFF, 0xFF });
            }
        }
    }

    {
        add_render_system<bl::ecs::renderer>(owner.get_canvas());
    }
}
