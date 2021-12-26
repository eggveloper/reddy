#ifndef _REDDY_STATE_HPP
#define _REDDY_STATE_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class State {
public:
    State(sf::RenderWindow* sfWindow);
    virtual ~State();

    virtual void endState() = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* sfTarget = nullptr) = 0;

private:
    sf::RenderWindow* sfWindow;
    std::vector<sf::Texture> textures;
};

#endif /* _REDDY_STATE_HPP */
