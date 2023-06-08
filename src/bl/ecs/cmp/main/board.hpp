#ifndef B8A9952A_4D81_4D2C_99A8_BCD419AD64F8
#define B8A9952A_4D81_4D2C_99A8_BCD419AD64F8

#include "bl/ecs/cmp/board.hpp"

namespace bl::ecs::cmp
{
    namespace main
    {
        struct board final : public bl::ecs::cmp::board<18, 10>
        {
        };
    }
}

#endif
