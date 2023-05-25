#include "blocks/main.hpp"

#include "blocks/display.hpp"
#include "blocks/game.hpp"
#include "blocks/raylib.hpp"

void blocks::main()
{
    raylib::Window window(800, 450, "Blocks!");
    {
        window.SetTargetFPS(60);

        blocks::display display(window);
        {
            blocks::game game(display);
            {
                game.run();
            }
        }
    }
}
