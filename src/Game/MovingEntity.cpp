/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : MovingEntity methods
*/


#include "MovingEntity.hpp"


// Getter
float MovingEntity::getHealthProportion() const {return (static_cast<float>(_hp)/static_cast<float>(_max_hp));}
const int& MovingEntity::getHealth() const {return _hp;}