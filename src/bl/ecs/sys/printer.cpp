#include "bl/ecs/sys/printer.hpp"

#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"
#include "bl/macros.hpp"

namespace bl::ecs::sys
{
    void printer::update(entt::registry& world, float dt)
    {
        UNUSED_ARG(dt);

        print_blocks(world);
        print_debris(world);
    }

    void printer::print_blocks(entt::registry& world)
    {
        auto as_grid = [&](cmp::block block) -> cmp::board<4, 4>
        {
            auto result = cmp::board<4, 4>();

            switch (block.type)
            {
                case cmp::block::shape::i:
                {
                    break;
                }
                case cmp::block::shape::j:
                {
                    break;
                }
                case cmp::block::shape::l:
                {
                    if (block.rotation % 2 == 0)
                    {
                        result.squares[0][1].state = cmp::square::value::l;
                        result.squares[1][1].state = cmp::square::value::l;
                        result.squares[2][1].state = cmp::square::value::l;
                        result.squares[3][1].state = cmp::square::value::l;
                    }
                    else
                    {
                        result.squares[1][0].state = cmp::square::value::l;
                        result.squares[1][1].state = cmp::square::value::l;
                        result.squares[1][2].state = cmp::square::value::l;
                        result.squares[1][3].state = cmp::square::value::l;
                    }

                    break;
                }
                case cmp::block::shape::o:
                {
                    break;
                }
                case cmp::block::shape::s:
                {
                    break;
                }
                case cmp::block::shape::t:
                {
                    break;
                }
                case cmp::block::shape::z:
                {
                    break;
                }
            }

            return result;
        };

        auto as_board = [&](cmp::block block) -> cmp::gameboard
        {
            auto result = cmp::gameboard();
            {
                auto source = as_grid(block);

                for (size_t i = 0; i < source.squares.size(); i++)
                {
                    for (size_t j = 0; j < source.squares[i].size(); j++)
                    {
                        auto square = source.squares[i][j];

                        if (square.state == cmp::square::value::n)
                        {
                            continue;
                        }

                        result.squares[i][j].state = square.state;
                    }
                }
            }
            return result;
        };

        auto targets = world.view<cmp::gameboard, cmp::children>();
        auto sources = world.view<cmp::block>();

        for (auto target : targets)
        {
            auto candidates = targets.get<cmp::children>(target).entities;

            for (auto candidate : candidates)
            {
                if (sources.contains(candidate) == false)
                {
                    continue;
                }

                auto source = candidate;

                merge(
                    as_board(sources.get<cmp::block>(source)),
                    targets.get<cmp::gameboard>(target)
                );
            }
        }
    }

    void printer::print_debris(entt::registry& world)
    {
        auto targets = world.view<cmp::gameboard, cmp::children>();
        auto sources = world.view<cmp::gameboard>();

        for (auto target : targets)
        {
            auto candidates = targets.get<cmp::children>(target).entities;

            for (auto candidate : candidates)
            {
                if (sources.contains(candidate) == false)
                {
                    continue;
                }

                auto source = candidate;

                merge(
                    sources.get<cmp::gameboard>(source),
                    targets.get<cmp::gameboard>(target)
                );
            }
        }
    }

    void printer::merge(cmp::gameboard const& source, cmp::gameboard& target)
    {
        for (size_t i = 0; i < source.squares.size(); i++)
        {
            for (size_t j = 0; j < source.squares[i].size(); j++)
            {
                auto candidate = source.squares[i][j];

                if (candidate.state == cmp::square::value::n)
                {
                    continue;
                }

                target.squares[i][j].state = candidate.state;
            }
        }
    }
}
