#ifndef BE828CC2_F919_48C7_B56A_D137A2773308
#define BE828CC2_F919_48C7_B56A_D137A2773308

#include <vector>

namespace bl::ecs
{
    struct playfield final
    {
        public:
            enum class cell
            {
                n,
                i,
                j,
                l,
                o,
                s,
                t,
                z
            };

        public:
            playfield(unsigned int w, unsigned int h);

        public:
            std::vector<playfield::cell> cells;
    };
}

#endif
