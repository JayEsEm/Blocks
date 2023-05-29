#ifndef A28D31EE_674E_4469_8C3F_2612530A8472
#define A28D31EE_674E_4469_8C3F_2612530A8472

#include <raylib.hpp>

namespace bl
{
    struct color
    {
        public:
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;

        public:
            raylib::Color to_raylib()
            {
                return raylib::Color(r, g, b, a);
            }
    };
}

#endif
