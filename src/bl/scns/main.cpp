#include "bl/scns/main.hpp"

#include "bl/colors.hpp"
#include "bl/ecs/all.hpp"
#include "bl/game.hpp"

namespace bl::scns
{
    main::main(bl::game& game)
        : null(game)
    {
    }

    void main::init()
    {
        auto block = bl::ecs::ent::block::add_to(world);
        auto field = bl::ecs::ent::playfield::add_to(world);

        world.replace<bl::ecs::cmp::playfield>(field, block);

        add_system<bl::ecs::sys::printer>();
        add_system<bl::ecs::sys::renderer>();
    }
}
