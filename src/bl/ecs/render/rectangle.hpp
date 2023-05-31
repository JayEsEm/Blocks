#ifndef EAB55DDC_3F17_4C32_A02C_B72866E2A2E7
#define EAB55DDC_3F17_4C32_A02C_B72866E2A2E7

#include "bl/color.hpp"

namespace bl::ecs
{
    struct rectangle final
    {
        public:
            float w;
            float h;

            bool filled;

            bl::color color;
    };
}

#endif
