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
        flecs::entity block = world.entity();

        block.add<bl::ecs::drawable>();

        block.set<bl::ecs::position>({ 0, 0 });
        block.set<bl::ecs::box>({ 64, 64 });
        block.set<bl::ecs::color>({ 0xFF, 0x00, 0x00, 0xFF });
    }

    {
        this->add_render_system<bl::ecs::renderer>(this->owner.get_canvas());
    }
}
