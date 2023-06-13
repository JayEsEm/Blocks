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
        auto debris = bl::ecs::ent::debris::add_to(world);
        auto board = bl::ecs::ent::board::add_to(world);

        world.get<ecs::cmp::gameboard>(debris).squares[5][5].state = ecs::cmp::square::value::l;
        world.get<ecs::cmp::children>(board).entities.push_back(debris);

        add_system<bl::ecs::sys::printer>();
        add_system<bl::ecs::sys::renderer>();
    }
}
