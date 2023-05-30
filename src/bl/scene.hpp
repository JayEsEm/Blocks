#ifndef F448CD5D_39FF_4698_A3EA_0976BFDB4A05
#define F448CD5D_39FF_4698_A3EA_0976BFDB4A05

#include <memory>
#include <vector>

#include <flecs.h>

#include "bl/ecs/system.hpp"
#include "bl/game.hpp"

namespace bl
{
    class canvas;
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
            template <typename T>
            void add_system();

        protected:
            bl::game& owner;
            flecs::world world;

        private:
            std::vector<std::unique_ptr<bl::ecs::system>> systems;
    };

    template <typename T>
    inline void scene::add_system()
    {
        auto system = std::make_unique<T>(owner.get_canvas());
        {
            system->install_on(world);
        }
        systems.push_back(std::move(system));
    }
}

#endif
