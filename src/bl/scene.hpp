#ifndef F448CD5D_39FF_4698_A3EA_0976BFDB4A05
#define F448CD5D_39FF_4698_A3EA_0976BFDB4A05

#include <memory>
#include <vector>

#include <flecs.h>

#include "bl/ecs/system.hpp"

namespace bl
{
    class canvas;
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
            template <typename T>
            void add_logic_system();

            template <typename T>
            void add_render_system(bl::canvas& canvas);

        protected:
            bl::game& owner;
            flecs::world world;

        private:
            std::vector<std::unique_ptr<bl::ecs::system>> systems;
    };

    template <typename T>
    inline void scene::add_logic_system()
    {
        auto system = std::make_unique<T>();
        {
            system->install_on(world);
        }
        systems.push_back(std::move(system));
    }

    template <typename T>
    inline void scene::add_render_system(bl::canvas& canvas)
    {
        auto system = std::make_unique<T>(canvas);
        {
            system->install_on(world);
        }
        systems.push_back(std::move(system));
    }
}

#endif
