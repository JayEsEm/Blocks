#ifndef B1CFFAD0_A196_4F7A_B381_DBADCA45DAA3
#define B1CFFAD0_A196_4F7A_B381_DBADCA45DAA3

#include <array>

#include "bl/ecs/cmp/square.hpp"

namespace bl::ecs::cmp
{
    template <unsigned rows, unsigned cols>
    struct board
    {
        public:
            using table = std::array<std::array<square, cols>, rows>;

        public:
            board::table squares;
    };
}

#endif
