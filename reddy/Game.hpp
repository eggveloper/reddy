#ifndef _REDDY_GAME_HPP
#define _REDDY_GAME_HPP

#include <states/GameState.hpp>

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
    sf::RenderWindow* sfWindow;
    sf::Event sfEvent;
    sf::Clock sfDtClock;

    float dt;

    std::stack<State*> states;

    void initWindow();
    void initStates();
};

#endif /* _REDDY_GAME_HPP */
