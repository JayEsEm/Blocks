#include "blocks/scene.hpp"

blocks::scene::scene(blocks::game& owner)
    : owner(owner)
{
}

void blocks::scene::process(float dt)
{
    world.progress(dt);
}
