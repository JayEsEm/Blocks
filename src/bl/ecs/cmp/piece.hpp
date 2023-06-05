#ifndef CD48EDEC_3249_4C4A_837E_FF24557A04C1
#define CD48EDEC_3249_4C4A_837E_FF24557A04C1

#include "bl/types.hpp"

namespace bl::ecs::cmp
{
    struct piece final
    {
        public:
            enum class type
            {
                i,
                j,
                l,
                o,
                s,
                t,
                z
            };

        public:
            uint rotation;
            piece::type type;
    };
}

#endif
