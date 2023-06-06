#ifndef B1CFFAD0_A196_4F7A_B381_DBADCA45DAA3
#define B1CFFAD0_A196_4F7A_B381_DBADCA45DAA3

#include <array>

namespace bl::ecs::cmp
{
    template <unsigned rows, unsigned cols>
    struct board
    {
        public:
            struct square final
            {
                public:
                    enum class value
                    {
                        n,
                        i,
                        j,
                        l,
                        o,
                        s,
                        t,
                        z,
                    };

                public:
                    square::value value;
            };

            using table = std::array<std::array<board::square, cols>, rows>;

        public:
            board::table squares;
    };
}

#endif
