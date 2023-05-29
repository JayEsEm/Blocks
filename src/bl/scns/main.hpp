#ifndef DDA3D1BB_E198_43A1_97FD_9DC509578496
#define DDA3D1BB_E198_43A1_97FD_9DC509578496

#include "bl/scns/null.hpp"

namespace bl::scns
{
    class main final : public bl::scns::null
    {
        public:
            main(bl::game& game);

            void init() override;
    };
}

#endif
