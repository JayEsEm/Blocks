#ifndef B57AA69E_F8C5_433D_8391_5A25C3A7DA8B
#define B57AA69E_F8C5_433D_8391_5A25C3A7DA8B

#include <vector>

#include "bl/entt/fwd.hpp"

namespace bl::ecs::cmp
{
    struct children final
    {
        public:
            std::vector<entt::entity> entities;
    };
}

#endif
