#include "blocks/display.hpp"

#include <raylib.hpp>

blocks::display::display(raylib::Window& window)
    : window(window)
{
}

bool blocks::display::should_close() const
{
    return window.ShouldClose();
}

void blocks::display::render_begin()
{
    window.BeginDrawing();
    window.ClearBackground(raylib::Color::RayWhite());
}

void blocks::display::render_end()
{
    window.EndDrawing();
}
