#include "bl/ecs/playfield.hpp"

bl::ecs::playfield::playfield(unsigned int w, unsigned int h)
    : cells(w * h)
{
    std::fill(cells.begin(), cells.end(), bl::ecs::playfield::cell::n);
}
