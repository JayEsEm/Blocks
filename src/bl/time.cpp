#include "bl/time.hpp"

#include "bl/raylib.hpp"

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
