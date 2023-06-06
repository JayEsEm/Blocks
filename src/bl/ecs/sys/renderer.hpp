#ifndef F9E89FE1_3D83_4FB5_8C63_6DB6333981FB
#define F9E89FE1_3D83_4FB5_8C63_6DB6333981FB

#include "bl/ecs/system.hpp"

namespace bl::ecs::sys
{
    class renderer final : public bl::ecs::system
    {
        public:
            void render(entt::registry& world, bl::canvas& canvas) override;
    };
}

#endif
