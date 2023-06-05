#ifndef C121318A_8A7D_41E4_8EF9_82FF3838AC8E
#define C121318A_8A7D_41E4_8EF9_82FF3838AC8E

#include <entt/fwd.hpp>

namespace bl::ecs::cmp
{
    struct playfield final
    {
        public:
            entt::entity block;
            entt::entity debris;
    };
}

#endif
