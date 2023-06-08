#ifndef A28D31EE_674E_4469_8C3F_2612530A8472
#define A28D31EE_674E_4469_8C3F_2612530A8472

#include "bl/raylib.hpp"
#include "bl/types.hpp"

namespace bl
{
    struct color
    {
        public:
            ubyte r;
            ubyte g;
            ubyte b;
            ubyte a;

        public:
            raylib::Color to_raylib() const
            {
                return raylib::Color(r, g, b, a);
            }
    };
}

#endif
