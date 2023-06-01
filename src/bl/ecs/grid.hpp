#ifndef CEB97FA8_30B8_4F40_A25A_5693D2460186
#define CEB97FA8_30B8_4F40_A25A_5693D2460186

#include <array>

namespace bl::ecs
{
    template <unsigned rows, unsigned cols>
    struct grid final
    {
        public:
            enum class cell
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
            std::array<std::array<grid::cell, cols>, rows> data;
    };
}

#endif
