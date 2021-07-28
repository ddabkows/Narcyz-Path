/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Mob methods
*/


#include "Spawner.hpp"


// Methods
void Spawner::spawn_mobs(float time) {
  if (_mobs.size() < _max_mobs && _spawn_speed < (time - _last_spawn)) {
    float pos_x = (_projection_size_x * static_cast<float>(_quadrant_x)) + _board_divider + static_cast<float>((rand()%static_cast<int>(_projection_size_x - _board_divider - _mob_size.x)));
    float pos_y = (_projection_size_y * static_cast<float>(_quadrant_y)) + _board_divider + static_cast<float>((rand()%static_cast<int>(_projection_size_y - _board_divider - _mob_size.y)));
    _mobs.emplace_back(std::make_shared<Mob>(_mob_size.x, _mob_size.y, pos_x, pos_y, _mob_velocity, static_cast<float>(_quadrant_x), static_cast<float>(_quadrant_y)));
    _last_spawn = time;
  } 
}

void Spawner::despawn_mobs() {
  _mobs.clear();
}