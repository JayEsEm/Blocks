#ifndef CF0C4C33_B050_4746_B503_715F7583BB81
#define CF0C4C33_B050_4746_B503_715F7583BB81

#include "bl/scene.hpp"

namespace bl::scns
{
    class null : public bl::scene
    {
        public:
            null(bl::game& game);

            virtual void init() override;
    };
}

#endif
