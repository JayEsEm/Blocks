#ifndef B5334400_3257_47AD_87D7_5C84A4F403D4
#define B5334400_3257_47AD_87D7_5C84A4F403D4

#include "bl/types.hpp"

namespace bl::ecs::cmp
{
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
            uint pixels = 20;
            square::value state;
    };
}

#endif
