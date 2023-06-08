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
        bl::ecs::ent::board::add_to(world);

        add_system<bl::ecs::sys::renderer>();
    }
}
