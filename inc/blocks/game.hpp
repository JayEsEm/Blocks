#ifndef B133379D_43D8_4FA8_BDBB_A986E0817331
#define B133379D_43D8_4FA8_BDBB_A986E0817331

#include <memory>

namespace blocks
{
    class display;
    class renderer;
    class scene;
}

namespace blocks
{
    class game final
    {
        public:
            game(blocks::display& display);
            ~game();

            void run();

        private:
            void init();
            void tick();

        private:
            blocks::display& display;
            std::unique_ptr<blocks::scene> scene;
    };
}

#endif
