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
                                           _game_board_size_y - 0.5f * (_projection_size_y - _player_size_y) / 2.f, _player_acceleration, _player_max_velocity,
                                           _player_starting_max_hp);
  
}

void Game::updateGame(Directions updating_directions, Directions updating_attack_directions) {
  endGame();
  if (!_is_over) {
    std::vector<std::shared_ptr<MovingEntity>> mobs{};
    for (std::size_t spawner_index = 0; spawner_index < _mob_spawners.size(); ++spawner_index) {
      if (_mob_spawners[spawner_index]->getQuadrantX() == _player->getQuadrantX() && _mob_spawners[spawner_index]->getQuadrantY() == _player->getQuadrantY()) {
        for (std::size_t mob_index = 0; mob_index < _mob_spawners[spawner_index]->getMobs().size(); ++mob_index) {
          mobs.emplace_back(_mob_spawners[spawner_index]->getMobs()[mob_index]);
        }
      } 
    }

    float time = _game_timer.getElapsedTime().asSeconds();
    if (time - _player_walk_timer > _game_tick) {
      _player->move(updating_directions, mobs, _walls);
      checkSpawners();
      _player_walk_timer = _game_timer.getElapsedTime().asSeconds();
    }
  }
}

void Game::checkSpawners() {
  float time = _game_timer.getElapsedTime().asSeconds();
  for (std::size_t spawner_index = 0; spawner_index < _mob_spawners.size(); ++spawner_index) {
    std::size_t dist_x = checkDist(_player->getQuadrantX(), _mob_spawners[spawner_index]->getQuadrantX());
    std::size_t dist_y = checkDist(_player->getQuadrantY(), _mob_spawners[spawner_index]->getQuadrantY());
    if (dist_x == 0 && dist_y == 0) {
      std::vector<std::shared_ptr<Mob>> mobs_to_move = _mob_spawners[spawner_index]->getMobs();
      for (std::size_t mob_index = 0; mob_index < mobs_to_move.size(); ++mob_index) {
        std::vector<std::shared_ptr<Mob>> other_mobs = mobs_to_move;
        other_mobs.erase(other_mobs.begin() + static_cast<int>(mob_index));
        mobs_to_move[mob_index]->move(_player, other_mobs, _walls[_player->getQuadrantX()][_player->getQuadrantY()], time);
      }
    }
    if (dist_x <= _spawn_dist && dist_y <= _spawn_dist) {
      _mob_spawners[spawner_index]->spawn_mobs(time, _walls[_mob_spawners[spawner_index]->getQuadrantX()][_mob_spawners[spawner_index]->getQuadrantY()]);
    }
    else if (dist_x > _despawn_dist || dist_y > _despawn_dist) {
      _mob_spawners[spawner_index]->despawn_mobs();
    }
  }
}

std::size_t Game::checkDist(std::size_t a_quadrant, std::size_t b_quadrant) {
  return static_cast<std::size_t>(abs(static_cast<int>(a_quadrant - b_quadrant)));
}

void Game::endGame() {
  if (_player->getHealth() <= 0) {_is_over = true;}
}


// Getters
const Dimensions& Game::getPlayerDimensions() const {return _player->getPosition();}
const std::vector<std::shared_ptr<GameEntity>>& Game::getWalls(std::size_t quadrant_x, std::size_t quadrant_y) const {return _walls[quadrant_x][quadrant_y];}
const std::size_t& Game::getPlayerQuadrantX() const {return _player->getQuadrantX();}
const std::size_t& Game::getPlayerQuadrantY() const {return _player->getQuadrantY();}
const std::vector<std::shared_ptr<Spawner>>& Game::getSpawners() const {return _mob_spawners;}
const Dimensions& Game::getPlayerSize() const {return _player->getSize();}
float Game::getPlayerHealth() const {return _player->getHealthProportion();}
const bool& Game::isOver() const {return _is_over;}
float Game::getGameTimer() const {return _game_timer.getElapsedTime().asSeconds();}
