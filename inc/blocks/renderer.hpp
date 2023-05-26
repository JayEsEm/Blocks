#ifndef A2DB55D6_D87D_4DED_AEC2_9A4BC1D7EC84
#define A2DB55D6_D87D_4DED_AEC2_9A4BC1D7EC84

namespace blocks
{
    class renderer
    {
        public:
            virtual void render_begin() = 0;
            virtual void render_end() = 0;
    };
}

#endif
