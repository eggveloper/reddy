#include "Game.hpp"

void Game::initWindow() {
    this->sfWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "reddy");
}

Game::Game() {
    this->initWindow();
}

Game::~Game() {
    delete this->sfWindow;
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
        this->update();
        this->render();
    }
}
