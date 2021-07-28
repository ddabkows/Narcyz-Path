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
  _player = std::make_shared<Player>(_player_size_x, _player_size_y,(_projection_size_x - _player_size_x) / 2.f,
                                           _game_board_size_y - 0.5f * (_projection_size_y - _player_size_y) / 2.f, _player_acceleration, _player_max_velocity);
  
}

void Game::updatePlayer(Directions updating_directions) {
  std::vector<std::shared_ptr<GameEntity>> mobs;
  std::shared_ptr<Mob> mob = std::make_shared<Mob>(100.f, 100.f, 100.f, 100.f, 20, std::size_t(0), std::size_t(9));
  mobs.emplace_back(mob);

  if (_game_timer.getElapsedTime().asSeconds() - _player_walk_timer > 0.1) {
    _player->move(updating_directions, mobs, _walls);
    checkSpawners();
    std::vector<std::shared_ptr<Mob>> mobs = _mob_spawners[0]->getMobs();
    if (mobs.size() == 0) std::cout << "Spawner Empty" << std::endl;
    else {
      for (std::size_t i = 0; i < mobs.size(); ++i) {
        std::cout << mobs[i]->getPosition().x << std::endl;
      }
    }
    _player_walk_timer = _game_timer.getElapsedTime().asSeconds();
  }
}

void Game::checkSpawners() {
  for (std::size_t spawner_index = 0; spawner_index < _mob_spawners.size(); ++spawner_index) {
    std::size_t dist_x = checkDist(_player->getQuadrantX(), _mob_spawners[spawner_index]->getQuadrantX());
    std::size_t dist_y = checkDist(_player->getQuadrantY(), _mob_spawners[spawner_index]->getQuadrantY());
    if (dist_x <= _spawn_dist && dist_y <= _spawn_dist) {
      _mob_spawners[spawner_index]->spawn_mobs(_game_timer.getElapsedTime().asSeconds());
    }
    else if (dist_x > _despawn_dist || dist_y > _despawn_dist) {
      _mob_spawners[spawner_index]->despawn_mobs();
    }
  }
}

std::size_t Game::checkDist(std::size_t a_quadrant, std::size_t b_quadrant) {
  return static_cast<std::size_t>(abs(static_cast<int>(a_quadrant - b_quadrant)));
}


// Getters
const Dimensions& Game::getPlayerDimensions() const {return _player->getPosition();}
const std::vector<std::shared_ptr<GameEntity>>& Game::getWalls(std::size_t quadrant_x, std::size_t quadrant_y) const {return _walls[quadrant_x][quadrant_y];}
const std::size_t& Game::getPlayerQuadrantX() const {return _player->getQuadrantX();}
const std::size_t& Game::getPlayerQuadrantY() const {return _player->getQuadrantY();}
