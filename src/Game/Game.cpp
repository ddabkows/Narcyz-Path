/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game methods
*/


#include <iostream>

#include "Game.hpp"


// Methods
void Game::generateGame() {
  _game_board = std::make_shared<GameBoard>(_game_board_size_x, _game_board_size_y);
  _player = std::make_shared<MovingEntity>(_player_size_x, _player_size_y,(_projection_size_x - _player_size_y) / 2.f,
                                           _game_board_size_y - (_projection_size_y - _player_size_y) / 2.f, _player_acceleration, _player_max_velocity);
}

void Game::updatePlayer(Directions updating_directions) {
  if (_game_timer.getElapsedTime().asSeconds() - _player_walk_timer > 0.1) {
    _player->move(updating_directions, _walls);
    _player_walk_timer = _game_timer.getElapsedTime().asSeconds();
  }
}


// Getters
const Dimensions& Game::getPlayerDimensions() const {return _player->getPosition();}
const std::vector<std::shared_ptr<GameEntity>> Game::getWalls(std::size_t quadrant_x, std::size_t quadrant_y) const {return _walls[quadrant_x][quadrant_y];}
const std::size_t Game::getPlayerQuadrantX() const {return _player->getQuadrantX();}
const std::size_t Game::getPlayerQuadrantY() const {return _player->getQuadrantY();}
