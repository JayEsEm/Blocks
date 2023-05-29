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
    init();

    while (display.should_close() == false)
    {
        tick();
    }
}

bl::canvas& bl::game::get_canvas() const
{
    return get_display();
}

bl::display& bl::game::get_display() const
{
    return display;
}

bl::time& bl::game::get_time() const
{
    return time;
}

void bl::game::init()
{
    scene->init();
}

void bl::game::tick()
{
    float dt = time.get_frame_time();

    display.begin_drawing();
    {
        scene->process(dt);
    }
    display.end_drawing();
}
