#include "blocks/game.hpp"

#include "blocks/display.hpp"
#include "blocks/scenes/null.hpp"

blocks::game::game(blocks::display& display)
    : display(display)
    , scene(std::make_unique<blocks::scenes::null>(*this))
{
}

blocks::game::~game()
{
}

void blocks::game::run()
{
    this->init();

    while (display.should_close() == false)
    {
        this->tick();
    }
}

void blocks::game::init()
{
    scene->init();
}

void blocks::game::tick()
{
    display.render_begin();
    {
        scene->process(0.f);
    }
    display.render_end();
}
