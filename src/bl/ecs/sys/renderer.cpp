#include "bl/ecs/sys/renderer.hpp"

#include "bl/canvas.hpp"
#include "bl/colors.hpp"
#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"

namespace bl::ecs::sys
{
    void renderer::render(entt::registry& world, bl::canvas& canvas)
    {
        auto color = [](cmp::square square) -> bl::color
        {
            switch (square.state)
            {
                case cmp::square::value::n:
                {
                    return bl::colors::n;
                }
                case cmp::square::value::i:
                {
                    return bl::colors::i;
                }
                case cmp::square::value::j:
                {
                    return bl::colors::j;
                }
                case cmp::square::value::l:
                {
                    return bl::colors::l;
                }
                case cmp::square::value::o:
                {
                    return bl::colors::o;
                }
                case cmp::square::value::s:
                {
                    return bl::colors::s;
                }
                case cmp::square::value::t:
                {
                    return bl::colors::t;
                }
                case cmp::square::value::z:
                {
                    return bl::colors::z;
                }
                default:
                {
                    return bl::colors::n;
                }
            }
        };

        auto targets = world.view<
            cmp::gameboard,
            cmp::position,
            cmp::renderable
        >();

        for (auto target : targets)
        {
            auto const& board = targets.get<cmp::gameboard>(target);
            auto const& pos = targets.get<cmp::position>(target);

            for (size_t i = 0; i < board.squares.size(); i++)
            {
                for (size_t j = 0; j < board.squares[i].size(); j++)
                {
                    auto square = board.squares[i][j];

                    float x = pos.x + static_cast<float>(square.pixels * j);
                    float y = pos.y + static_cast<float>(square.pixels * i);
                    float w = static_cast<float>(square.pixels);
                    float h = static_cast<float>(square.pixels);

                    canvas.set_draw_color(color(square));
                    canvas.fill_rect(x + 1, y + 1, w - 1, h - 1);
                }
            }
        }
    }
}
