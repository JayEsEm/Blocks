#ifndef CEB97FA8_30B8_4F40_A25A_5693D2460186
#define CEB97FA8_30B8_4F40_A25A_5693D2460186

#include <array>

#include "bl/ecs/cell.hpp"

namespace bl::ecs
{
    struct grid final
    {
        public:
            std::array<std::array<bl::ecs::cell, 10>, 18> data;
    };
}

#endif
