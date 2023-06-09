#ifndef D2FADE0E_0E31_471B_BC6B_FE818D0FB94F
#define D2FADE0E_0E31_471B_BC6B_FE818D0FB94F

#include "bl/canvas.hpp"

namespace raylib
{
    class Window;
}

namespace bl
{
    class display final : public bl::canvas
    {
        public:
            display(raylib::Window& window);

            bool should_close() const;

            void begin_drawing() override;
            void end_drawing() override;

            void draw_rect(float x, float y, float w, float h) override;
            void fill_rect(float x, float y, float w, float h) override;

        private:
            raylib::Window& window;
    };
}

#endif
