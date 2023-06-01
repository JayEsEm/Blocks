#include "bl/canvas.hpp"

namespace bl
{
    canvas::canvas()
        : draw_color({ 0x00, 0x00, 0x00, 0xFF })
    {
    }

    bl::color canvas::get_draw_color() const
    {
        return draw_color;
    }

    void canvas::set_draw_color(bl::color color)
    {
        this->draw_color = color;
    }
}
