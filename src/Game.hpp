#ifndef _REDDY_GAME_HPP
#define _REDDY_GAME_HPP

#include "State.hpp"

class Game {
public:
    Game();
    virtual ~Game();

    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();

private:
    sf::RenderWindow *sfWindow;
    sf::Event sfEvent;
    sf::Clock sfDtClock;

    float dt;

    void initWindow();
};

#endif /* _REDDY_GAME_HPP */
