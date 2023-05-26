#include "bl/game.hpp"

#include "bl/display.hpp"
#include "bl/time.hpp"

#include "bl/scns/all.hpp"

bl::game::game(bl::display& display, bl::time& time)
    : display(display)
    , time(time)
    , scene(std::make_unique<bl::scns::main>(*this))
{
}

bl::game::~game()
{
}

void bl::game::run()
{
    this->init();

    while (display.should_close() == false)
    {
        this->tick();
    }
}

void bl::game::init()
{
    scene->init();
}

void bl::game::tick()
{
    float dt = time.get_frame_time();

    display.render_begin();
    {
        scene->process(dt);
    }
    display.render_end();
}
