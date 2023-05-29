#ifndef A2DB55D6_D87D_4DED_AEC2_9A4BC1D7EC84
#define A2DB55D6_D87D_4DED_AEC2_9A4BC1D7EC84

#include "bl/color.hpp"

namespace bl
{
    class canvas
    {
        public:
            canvas();

            virtual void begin_drawing() = 0;
            virtual void end_drawing() = 0;

            virtual void draw_rect(float x, float y, float w, float h) = 0;

            bl::color get_fill_color() const;

            void set_fill_color(bl::color color);

        protected:
            bl::color fcolor;
    };
}

#endif
