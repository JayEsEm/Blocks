#include "bl/game.hpp"

#include "bl/display.hpp"
#include "bl/time.hpp"

#include "bl/scns/all.hpp"

namespace bl
{
    game::game(bl::display& display, bl::time& time)
        : display(display)
        , time(time)
        , scene(std::make_unique<bl::scns::main>(*this))
    {
    }

    game::~game()
    {
    }

    void game::run()
    {
        init();

        while (display.should_close() == false)
        {
            tick();
        }
    }

    bl::canvas& game::get_canvas() const
    {
        return get_display();
    }

    bl::display& game::get_display() const
    {
        return display;
    }

    bl::time& game::get_time() const
    {
        return time;
    }

    void game::init()
    {
        scene->init();
    }

    void game::tick()
    {
        {
            float dt = time.get_frame_time();

            scene->update(dt);
        }

        display.begin_drawing();
        {
            scene->render(display);
        }
        display.end_drawing();
    }
}
