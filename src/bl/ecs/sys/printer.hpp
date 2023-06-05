#ifndef AE8E02D7_A902_4BEC_A253_ECF18806ECB5
#define AE8E02D7_A902_4BEC_A253_ECF18806ECB5

#include <array>

#include "bl/ecs/cmp/grid.hpp"
#include "bl/ecs/cmp/piece.hpp"
#include "bl/ecs/system.hpp"

namespace bl::ecs::sys
{
    class printer final : public bl::ecs::system
    {
        private:
            using imprint = std::array<std::array<cmp::grid::value, 4>, 4>;

        public:
            void update(entt::registry& world, float dt) override;
            void render(entt::registry& world, bl::canvas& canvas) override;

        private:
            printer::imprint get_imprint_for(cmp::piece::shape shape);
    };
}

#endif
