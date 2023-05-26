#include "bl/display.hpp"

#include <raylib.hpp>

bl::display::display(raylib::Window& window)
    : window(window)
{
}

bool bl::display::should_close() const
{
    return window.ShouldClose();
}

void bl::display::render_begin()
{
    window.BeginDrawing();
    window.ClearBackground(raylib::Color::RayWhite());
}

void bl::display::render_end()
{
    window.EndDrawing();
}
