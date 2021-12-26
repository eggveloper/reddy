#include "Game.hpp"

void Game::initWindow() {
    std::ifstream ifs("config/settings.ini");

    sf::VideoMode sfWindowBounds(800, 600);
    std::string title = "untitled window";

    unsigned framerateLimit = 120;
    bool verticalSyncEnabled = false;

    if (ifs.is_open()) {
        std::getline(ifs, title);

        ifs >> sfWindowBounds.width >> sfWindowBounds.height;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
    }

    ifs.close();

    this->sfWindow = new sf::RenderWindow(sfWindowBounds, title);
    this->sfWindow->setFramerateLimit(framerateLimit);
    this->sfWindow->setVerticalSyncEnabled(verticalSyncEnabled);
}

Game::Game() {
    this->initWindow();
}

Game::~Game() {
    delete this->sfWindow;
}

void Game::updateDt() {
    this->dt = this->sfDtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
    while (this->sfWindow->pollEvent(this->sfEvent)) {
        if (this->sfEvent.type == sf::Event::Closed) {
            this->sfWindow->close();
        }
    }
}

void Game::update() {
    this->updateSFMLEvents();
}

void Game::render() {
    this->sfWindow->clear();

    this->sfWindow->display();
}

void Game::run() {
    while (this->sfWindow->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}
