#include "bl/display.hpp"

#include <raylib.hpp>

#include "bl/colors.hpp"

bl::display::display(raylib::Window& window)
    : window(window)
{
}

bool bl::display::should_close() const
{
    return window.ShouldClose();
}

void bl::display::begin_drawing()
{
    window.BeginDrawing();
    window.ClearBackground(bl::colors::bg.to_raylib());
}

void bl::display::end_drawing()
{
    window.EndDrawing();
}

void bl::display::draw_rect(float x, float y, float w, float h)
{
    raylib::Color color = get_draw_color().to_raylib();
    raylib::Rectangle rect(x, y, w, h);

    rect.DrawLines(color);
}

void bl::display::fill_rect(float x, float y, float w, float h)
{
    raylib::Color color = get_draw_color().to_raylib();
    raylib::Rectangle rect(x, y, w, h);

    rect.Draw(color);
}
