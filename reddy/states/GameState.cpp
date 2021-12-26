#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* sfWindow) : State(sfWindow) {

}

GameState::~GameState() {

}

void GameState::endState() {

}

void GameState::update(const float& dt) {
    std::cout << "[INFO] gamestate is sus???" << std::endl;
}

void GameState::render(sf::RenderTarget* sfTarget) {

}
