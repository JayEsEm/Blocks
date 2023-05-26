#ifndef F448CD5D_39FF_4698_A3EA_0976BFDB4A05
#define F448CD5D_39FF_4698_A3EA_0976BFDB4A05

#include <flecs.h>

namespace blocks
{
    class game;
}

namespace blocks
{
    class scene
    {
        public:
            scene(blocks::game& owner);

            virtual void init() = 0;

            void process(float dt);

        protected:
            blocks::game& owner;
            flecs::world world;
    };
}

#endif
