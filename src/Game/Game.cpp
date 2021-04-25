/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game methods
*/


#include "Game.hpp"


// Methods
void Game::generateGame() {
  _game_board = std::make_shared<GameBoard>(_game_board_size_x, _game_board_size_y);
  _player = std::make_shared<MovingEntity>(_player_size_x, _player_size_y, _game_board_size_y - _player_size_y, 
                                           (_projection_size_x - _player_size_y) / 2.f, _player_acceleration,
                                           _player_max_velocity);
}

void Game::updatePlayer(Directions updating_directions) {
  _player->updatePosition(updating_directions, _walls, _game_board->getSize());
}