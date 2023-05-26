#ifndef B133379D_43D8_4FA8_BDBB_A986E0817331
#define B133379D_43D8_4FA8_BDBB_A986E0817331

namespace blocks
{
    class display;
    class renderer;
}

namespace blocks
{
    class game final
    {
        public:
            game(blocks::display& display);

            void run();
            void tick();

        private:
            blocks::display& display;
    };
}

#endif
