#include "bl/main.hpp"

#include <raylib.hpp>

#include "bl/display.hpp"
#include "bl/time.hpp"

#include "bl/game.hpp"

namespace bl
{
    void main()
    {
        raylib::Window window(800, 450, "Blocks!");
        {
            window.SetTargetFPS(60);

            bl::display display(window);
            bl::time time(window);
            {
                bl::game game(display, time);
                {
                    game.run();
                }
            }
        }
    }
}
