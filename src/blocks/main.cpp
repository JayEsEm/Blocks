#include "blocks/main.hpp"

#include <raylib.hpp>

#include "blocks/display.hpp"
#include "blocks/time.hpp"

#include "blocks/game.hpp"

void blocks::main()
{
    raylib::Window window(800, 450, "Blocks!");
    {
        window.SetTargetFPS(60);

        blocks::display display(window);
        blocks::time time(window);
        {
            blocks::game game(display, time);
            {
                game.run();
            }
        }
    }
}
