/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Mob methods
*/


#include "Spawner.hpp"


// Methods
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