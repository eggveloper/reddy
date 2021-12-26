#ifndef _REDDY_GAMESTATE_HPP
#define _REDDY_GAMESTATE_HPP

#include "State.hpp"

class GameState : public State {
public:
    GameState(sf::RenderWindow* sfWindow);
    virtual ~GameState();

    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* sfTarget = nullptr);

private:

};

#endif /* _REDDY_GAMESTATE_HPP */
