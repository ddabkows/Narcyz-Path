/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Mob methods
*/


#include "Spawner.hpp"


// Methods
void Spawner::spawnMobs(float time, std::vector<std::shared_ptr<GameEntity>> walls) {
  if (_mobs.size() < _max_mobs && _spawn_speed < (time - _last_spawn)) {
    float pos_x = (_projection_size_x * static_cast<float>(_quadrant_x)) + _board_divider + static_cast<float>((rand()%static_cast<int>(_projection_size_x - _board_divider - _mob_size.x)));
    float pos_y = (_projection_size_y * static_cast<float>(_quadrant_y)) + _board_divider + static_cast<float>((rand()%static_cast<int>(_projection_size_y - _board_divider - _mob_size.y)));
    bool spawn_allow = true;
    for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
      if (walls[wall_index]->getPosition().x <= pos_x + _mob_size.x && pos_x <= walls[wall_index]->getPosition().x + walls[wall_index]->getSize().x &&
          walls[wall_index]->getPosition().y <= pos_y + _mob_size.y && pos_y <= walls[wall_index]->getPosition().y + walls[wall_index]->getSize().y) 
      spawn_allow = false;
    }
    for (std::size_t mob_index = 0; mob_index < _mobs.size(); ++mob_index) {
      if (_mobs[mob_index]->getPosition().x <= pos_x + _mob_size.x && pos_x <= _mobs[mob_index]->getPosition().x + _mob_size.x &&
          _mobs[mob_index]->getPosition().y <= pos_y + _mob_size.y && pos_y <= _mobs[mob_index]->getPosition().y + _mob_size.y) spawn_allow = false;
    }
    if (spawn_allow) {
      if (_quadrant_x == 0 && _quadrant_y == 8) {
        _mobs.emplace_back(std::make_shared<ClassicMob>(_mob_size.x, _mob_size.y, pos_x, pos_y, _mob_velocity, 
                                                        static_cast<float>(_quadrant_x), static_cast<float>(_quadrant_y), _max_hp,
                                                        _hit_charge, _hit_cooldown, _hit_strength, _attack_display, _skin, _attack_skin));
      }
      _last_spawn = time;
    }
  } 
}

void Spawner::despawnMobs() {
  _mobs.clear();
}

void Spawner::killMobs() {
  for (std::size_t mob_index = 0; mob_index < _mobs.size(); ++mob_index) {
    if (_mobs[mob_index]->getHealth() <= 0) {
      _mobs.erase(_mobs.begin() + static_cast<int>(mob_index));
      --mob_index;
    }
  }
}

// Setters
void Spawner::setMobs(std::vector<std::shared_ptr<Mob>> new_mobs) {_mobs = new_mobs;}

// Getters
const std::size_t& Spawner::getQuadrantX() const {return _quadrant_x;}
const std::size_t& Spawner::getQuadrantY() const {return _quadrant_y;}
std::vector<std::shared_ptr<Mob>> Spawner::getMobs() {return _mobs;}