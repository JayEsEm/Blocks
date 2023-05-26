#include "bl/scene.hpp"

bl::scene::scene(bl::game& owner)
    : owner(owner)
{
}

void bl::scene::process(float dt)
{
    world.progress(dt);
}
