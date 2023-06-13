#include "bl/ecs/sys/renderer.hpp"

#include "bl/canvas.hpp"
#include "bl/colors.hpp"
#include "bl/ecs/all.hpp"
#include "bl/entt/entt.hpp"

namespace bl::ecs::sys
{
    void renderer::render(entt::registry& world, bl::canvas& canvas)
    {
        using namespace bl::ecs::cmp;

        auto color = [](square square) -> bl::color
        {
            using namespace bl::ecs::cmp;
            using enum square::value;

            switch (square.state)
            {
                case n:
                {
                    return bl::colors::n;
                }
                case i:
                {
                    return bl::colors::i;
                }
                case j:
                {
                    return bl::colors::j;
                }
                case l:
                {
                    return bl::colors::l;
                }
                case o:
                {
                    return bl::colors::o;
                }
                case s:
                {
                    return bl::colors::s;
                }
                case t:
                {
                    return bl::colors::t;
                }
                case z:
                {
                    return bl::colors::z;
                }
                default:
                {
                    return bl::colors::n;
                }
            }
        };

        auto targets = world.view<gameboard, position, renderable>();

        for (auto target : targets)
        {
            auto const& board = targets.get<gameboard>(target);
            auto const& pos = targets.get<position>(target);

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
