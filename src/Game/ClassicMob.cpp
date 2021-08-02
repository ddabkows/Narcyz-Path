/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Classic Mob methods
*/


#include "ClassicMob.hpp"


// Methods
void Mob::attack(std::shared_ptr<Player> player, float time) {
  if (_charge_attack) {
    if (time - _last_hit > _hit_charge) {
      _charge_attack = false;
      _last_hit = time;
      _attack_display.attack_direction = east;
      if (checkDistanceToPlayer(player, _attack_display.pos.x + (_attack_display.size.x / 2.f), _attack_display.pos.y + (_attack_display.size.y / 2.f)) <= _classic_mob_attack_radius) {
        player->takeDamage(_hit_strength);
      }
      _attack_display.display_moment = time;
      _display_attack = true;
    }
  }
}