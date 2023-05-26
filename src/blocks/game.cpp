#include "blocks/game.hpp"

#include "blocks/display.hpp"
#include "blocks/time.hpp"

#include "blocks/scenes/all.hpp"

blocks::game::game(blocks::display& display, blocks::time& time)
    : display(display)
    , time(time)
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
    float dt = time.get_frame_time();

    display.render_begin();
    {
        scene->process(dt);
    }
    display.render_end();
}
