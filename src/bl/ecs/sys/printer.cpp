#include "bl/ecs/sys/printer.hpp"

#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"
#include "bl/macros.hpp"

namespace bl::ecs::sys
{
    void printer::update(entt::registry& world, float dt)
    {
        UNUSED_ARG(dt);

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
