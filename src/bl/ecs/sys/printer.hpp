#ifndef B257C446_5609_4B17_9C5E_A515E7C1D9B8
#define B257C446_5609_4B17_9C5E_A515E7C1D9B8

#include "bl/ecs/cmp/gameboard.hpp"
#include "bl/ecs/system.hpp"

namespace bl::ecs::sys
{
    class printer final : public bl::ecs::system
    {
        public:
            void update(entt::registry& world, float dt) override;

        private:
            void merge(cmp::gameboard const& source, cmp::gameboard& target);
    };
}

#endif
