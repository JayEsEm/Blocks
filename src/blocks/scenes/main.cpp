#include "blocks/scenes/main.hpp"

#include "blocks/ecs/all.hpp"

blocks::scenes::main::main(blocks::game& game)
    : null(game)
{
}

void blocks::scenes::main::init()
{
    {
        flecs::entity block = world.entity();

        block.add<blocks::ecs::renderable>();
        block.set<blocks::ecs::position>({ 0, 0 });
        block.set<blocks::ecs::box>({ 64, 64 });
        block.set<blocks::ecs::color>({ 0xFF, 0x00, 0x00, 0xFF });
    }
}
