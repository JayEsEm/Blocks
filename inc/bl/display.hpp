#ifndef D2FADE0E_0E31_471B_BC6B_FE818D0FB94F
#define D2FADE0E_0E31_471B_BC6B_FE818D0FB94F

#include "bl/renderer.hpp"

namespace raylib
{
    class Window;
}

namespace bl
{
    class display final : public bl::renderer
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
