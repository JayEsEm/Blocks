#ifndef DDA3D1BB_E198_43A1_97FD_9DC509578496
#define DDA3D1BB_E198_43A1_97FD_9DC509578496

#include "blocks/scenes/null.hpp"

namespace blocks::scenes
{
    class main final : public blocks::scenes::null
    {
        public:
            main(blocks::game& game);

            void init() override;
    };
}

#endif
