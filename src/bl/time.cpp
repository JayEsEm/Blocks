#include "bl/time.hpp"

#include <raylib.hpp>

bl::time::time(raylib::Window& window)
    : window(window)
{
}

float bl::time::get_frame_time() const
{
    return window.GetFrameTime();
}
