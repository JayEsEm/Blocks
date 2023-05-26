#ifndef CF0C4C33_B050_4746_B503_715F7583BB81
#define CF0C4C33_B050_4746_B503_715F7583BB81

#include "blocks/scene.hpp"

namespace blocks::scenes
{
    class null : public blocks::scene
    {
        public:
            null(blocks::game& game);

            virtual void init() override;
    };
}

#endif
