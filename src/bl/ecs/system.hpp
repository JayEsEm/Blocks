#ifndef FA78845F_1B74_4323_99C5_02B98C8DA5B5
#define FA78845F_1B74_4323_99C5_02B98C8DA5B5

#include <entt/fwd.hpp>

namespace bl
{
    class canvas;
}

namespace bl::ecs
{
    class system
    {
        protected:
            system() = default;

        public:
            virtual void update(entt::registry& world, float dt);
            virtual void render(entt::registry& world, bl::canvas& canvas);
    };
}

#endif
