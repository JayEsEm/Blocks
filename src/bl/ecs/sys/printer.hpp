#ifndef AE8E02D7_A902_4BEC_A253_ECF18806ECB5
#define AE8E02D7_A902_4BEC_A253_ECF18806ECB5

#include <array>

#include "bl/ecs/cmp/block.hpp"
#include "bl/ecs/cmp/grid.hpp"
#include "bl/ecs/system.hpp"

namespace bl::ecs::sys
{
    class printer final : public bl::ecs::system
    {
        public:
            void update(entt::registry& world, float dt) override;

        private:
            void print_block(entt::registry& world);
            void print_debris(entt::registry& world);

            void merge(cmp::grid const& source, cmp::grid& target);
    };
}

#endif
