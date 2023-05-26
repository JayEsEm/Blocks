#include "blocks/time.hpp"

#include <raylib.hpp>

blocks::time::time(raylib::Window& window)
    : window(window)
{
}

float blocks::time::get_frame_time() const
{
    return window.GetFrameTime();
}
