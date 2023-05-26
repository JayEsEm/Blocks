#ifndef B133379D_43D8_4FA8_BDBB_A986E0817331
#define B133379D_43D8_4FA8_BDBB_A986E0817331

#include <memory>

namespace bl
{
    class display;
    class renderer;
    class scene;
    class time;
}

namespace bl
{
    class game final
    {
        public:
            game(bl::display& display, bl::time& time);
            ~game();

            void run();

        private:
            void init();
            void tick();

        private:
            bl::display& display;
            bl::time& time;

            std::unique_ptr<bl::scene> scene;
    };
}

#endif
