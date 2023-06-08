#ifndef F448CD5D_39FF_4698_A3EA_0976BFDB4A05
#define F448CD5D_39FF_4698_A3EA_0976BFDB4A05

#include <memory>
#include <vector>

#include "bl/ecs/system.hpp"
#include "bl/entt/entt.hpp"
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

            void update(float dt);
            void render(bl::canvas& canvas);

        protected:
            template <typename T>
            void add_system();

        protected:
            bl::game& owner;
            entt::registry world;

        private:
            std::vector<std::unique_ptr<bl::ecs::system>> systems;
    };

    template <typename T>
    inline void scene::add_system()
    {
        auto system = std::make_unique<T>();
        {
        }
        systems.push_back(std::move(system));
    }
}

#endif
