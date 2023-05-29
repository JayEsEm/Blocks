#include "bl/canvas.hpp"

bl::canvas::canvas()
    : fcolor({ 0x00, 0x00, 0x00, 0xFF })
{
}

bl::color bl::canvas::get_fill_color() const
{
    return fcolor;
}

void bl::canvas::set_fill_color(bl::color color)
{
    this->fcolor = color;
}
