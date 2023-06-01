#include "bl/time.hpp"

#include <raylib.hpp>

namespace bl
{
    time::time(raylib::Window& window)
        : window(window)
    {
    }

    float time::get_frame_time() const
    {
        return window.GetFrameTime();
    }
}
