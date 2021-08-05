/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Mob methods
*/


#include "Mob.hpp"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Methods
float Mob::checkDistanceToPlayer(std::shared_ptr<Player> player, float new_pos_x, float new_pos_y) {
  return static_cast<float>(sqrt(pow(new_pos_x - player->getPosition().x, 2) + pow(new_pos_y - player->getPosition().y, 2) * 1.0));
}

void Mob::chargeAttack(float time) {
  if (!_charge_attack && time - _last_hit > _hit_cooldown) {
    _charge_attack = true;
    _last_hit = time;
  }
}


void Mob::attackDisplayed() {
  _display_attack = false;
}


// Getters
const AttackToDisplay& Mob::getAttackDisplay() const {return _attack_display;}
const bool& Mob::getAttackToDisplay() const {return _display_attack;}
const unsigned int& Mob::getStatesNumber() const {return _states_number;}