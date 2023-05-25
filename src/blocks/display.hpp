#ifndef D2FADE0E_0E31_471B_BC6B_FE818D0FB94F
#define D2FADE0E_0E31_471B_BC6B_FE818D0FB94F

#include "blocks/renderer.hpp"

namespace raylib
{
    class Window;
}

namespace blocks
{
    class display final : public blocks::renderer
    {
        public:
            display(raylib::Window& window);

            bool should_close() const;

            void render_begin() override;
            void render_end() override;

        private:
            raylib::Window& window;
    };
}

#endif
