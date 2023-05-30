#ifndef ECEE15DE_A021_4B7C_92B9_839B0D743CA6
#define ECEE15DE_A021_4B7C_92B9_839B0D743CA6

#include "bl/ecs/system.hpp"

namespace bl
{
    class canvas;
}

namespace flecs
{
    class iter;
}

namespace bl::ecs
{
    class renderer final : public bl::ecs::system
    {
        public:
            renderer(bl::canvas& canvas);

            void install_on(flecs::world& world) override;
    };
}

#endif
