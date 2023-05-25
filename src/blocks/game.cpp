#include "blocks/game.hpp"

#include "blocks/display.hpp"

blocks::game::game(blocks::display& display) : display(display)
{
}

void blocks::game::run()
{
    while (display.should_close() == false)
    {
        tick();
    }
}

void blocks::game::tick()
{
    update();
    render();
}

void blocks::game::update()
{
}

void blocks::game::render()
{
    display.render_begin();
    {
    }
    display.render_end();
}
