#include "blocks/main.hpp"

#include "blocks/raylib.hpp"

void blocks::main()
{
    raylib::Window window(800, 450, "Blocks!");
    {
        window.SetTargetFPS(60);

        while (window.ShouldClose() == false)
        {
            window.BeginDrawing();
            {
                window.ClearBackground(raylib::Color::RayWhite());
            }
            window.EndDrawing();
        }
    }
}
