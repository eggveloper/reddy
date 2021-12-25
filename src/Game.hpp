#ifndef _REDDY_GAME_HPP
#define _REDDY_GAME_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Game {
public:
    Game();
    virtual ~Game();

    void updateSFMLEvents();
    void update();
    void render();
    void run();

private:
    sf::RenderWindow *sfWindow;
    sf::Event sfEvent;

    void initWindow();
};

#endif /* _REDDY_GAME_HPP */
