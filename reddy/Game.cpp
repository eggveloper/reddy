#include "Game.hpp"

Game::Game() {
    this->initWindow();
    this->initStates();
}

Game::~Game() {
    delete this->sfWindow;

    while (!this->states.empty()) {
        delete this->states.top();

        this->states.pop();
    }
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

    if (!this->states.empty()) {
        this->states.top()->update(this->dt);
    }
}

void Game::render() {
    this->sfWindow->clear();

    if (!this->states.empty()) {
        this->states.top()->render();
    }

    this->sfWindow->display();
}

void Game::run() {
    while (this->sfWindow->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}

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

void Game::initStates() {
    this->states.push(new GameState(this->sfWindow));
}
