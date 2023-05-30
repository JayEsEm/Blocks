#ifndef FA78845F_1B74_4323_99C5_02B98C8DA5B5
#define FA78845F_1B74_4323_99C5_02B98C8DA5B5

namespace bl
{
    class canvas;
}

namespace flecs
{
    class world;
}

namespace bl::ecs
{
    class system
    {
        public:
            system(bl::canvas& canvas);

            virtual void install_on(flecs::world& world) = 0;

        protected:
            bl::canvas& canvas;
    };
}

#endif
