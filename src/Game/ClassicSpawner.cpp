/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : ClassicSpawner methods
*/


#include "ClassicSpawner.hpp"


// Methods
void ClassicSpawner::spawnMobs(float time, std::vector<std::shared_ptr<GameEntity>> walls) {
  if (_mobs.size() < _max_mobs && _spawn_speed < (time - _last_spawn)) {
    float pos_x = (_projection_size_x * static_cast<float>(_quadrant_x)) + _board_divider + static_cast<float>((rand()%static_cast<int>(_projection_size_x - _board_divider - _player_size_x)));
    float pos_y = (_projection_size_y * static_cast<float>(_quadrant_y)) + _board_divider + static_cast<float>((rand()%static_cast<int>(_projection_size_y - _board_divider - _player_size_y)));
    bool spawn_allow = true;
    for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
      std::shared_ptr<GameEntity> wall = walls[wall_index];
      if (wall->getPosition().x <= pos_x + _player_size_x && pos_x <= wall->getPosition().x + wall->getSize().x &&
          wall->getPosition().y <= pos_y + _player_size_y && pos_y <= wall->getPosition().y + wall->getSize().y) 
      spawn_allow = false;
    }
    for (std::size_t mob_index = 0; mob_index < _mobs.size(); ++mob_index) {
      std::shared_ptr<Mob> mob = _mobs[mob_index];
      if (mob->getPosition().x <= pos_x + _player_size_x && pos_x <= mob->getPosition().x + _player_size_x &&
          mob->getPosition().y <= pos_y + _player_size_y && pos_y <= mob->getPosition().y + _player_size_y) spawn_allow = false;
    }
    if (spawn_allow) {
      if (_quadrant_x == 0 && _quadrant_y == 8) {
        _mobs.emplace_back(std::make_shared<ClassicMob>(pos_x, pos_y));
      }
      _last_spawn = time;
    }
  } 
}