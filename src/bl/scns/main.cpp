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
        bl::ecs::playground::add_to(world);
    }

    {
        add_system<bl::ecs::renderer>();
    }
}
