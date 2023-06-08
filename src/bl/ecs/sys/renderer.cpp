#include "bl/ecs/sys/renderer.hpp"

#include "bl/canvas.hpp"
#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"

namespace bl::ecs::sys
{
    void renderer::render(entt::registry& world, bl::canvas& canvas)
    {
        using namespace bl::ecs::cmp;

        auto view = world.view<main::board, position, renderer>();

        for (auto ent : view)
        {
            auto const& board = view.get<main::board>(ent);
            auto const& pos = view.get<position>(ent);

            for (size_t i = 0; i < board.squares.size(); i++)
            {
                for (size_t j = 0; j < board.squares[i].size(); j++)
                {
                    auto square = board.squares[i][j];

                    float x = pos.x + static_cast<float>(square.pixels * j);
                    float y = pos.y + static_cast<float>(square.pixels * i);
                }
            }
        }
    }
}
