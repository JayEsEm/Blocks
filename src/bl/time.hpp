#ifndef A3086B75_5D31_442E_B474_C6FF3AF663C9
#define A3086B75_5D31_442E_B474_C6FF3AF663C9

namespace raylib
{
    class Window;
}

namespace bl
{
    class time final
    {
        public:
            time(raylib::Window& window);

            float get_frame_time() const;

        private:
            raylib::Window& window;
    };
}

#endif
