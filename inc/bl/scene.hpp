#ifndef F448CD5D_39FF_4698_A3EA_0976BFDB4A05
#define F448CD5D_39FF_4698_A3EA_0976BFDB4A05

#include <flecs.h>

namespace bl
{
    class game;
}

namespace bl
{
    class scene
    {
        public:
            scene(bl::game& owner);

            virtual void init() = 0;

            void process(float dt);

        protected:
            bl::game& owner;
            flecs::world world;
    };
}

#endif
