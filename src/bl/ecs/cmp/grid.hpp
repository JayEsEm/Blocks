#ifndef CEB97FA8_30B8_4F40_A25A_5693D2460186
#define CEB97FA8_30B8_4F40_A25A_5693D2460186

#include <array>

#include "bl/types.hpp"

namespace bl::ecs::cmp
{
    struct grid final
    {
        public:
            struct cell final
            {
                public:
                    uint x;
                    uint y;
            };

            enum class value
            {
                n,
                i,
                j,
                l,
                o,
                s,
                t,
                z
            };

        public:
            std::array<std::array<grid::value, 10>, 18> data;
    };
}

#endif
