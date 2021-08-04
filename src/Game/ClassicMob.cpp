/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Classic Mob methods
*/


#include "ClassicMob.hpp"


// Methods
void ClassicMob::attack(std::shared_ptr<Player> player, float time) {
  if (_charge_attack) {
    if (time - _last_hit > _hit_charge) {
      _charge_attack = false;
      _attack_display.pos = Dimensions(_position.x - ((_attack_display.size.x - _size.x) / 2.f), _position.y - ((_attack_display.size.y - _size.y) / 2.f));
      _last_hit = time;
      _attack_display.attack_direction = east;
      if (checkDistance(player, _attack_display.pos.x + (_attack_display.size.x / 2.f), _attack_display.pos.y + (_attack_display.size.y / 2.f)) <= _classic_mob_attack_radius) {
        player->takeDamage(_hit_strength);
      }
      _attack_display.display_moment = time;
      _display_attack = true;
    }
  }
}

float ClassicMob::checkDistance(std::shared_ptr<Player> player, float pos_x, float pos_y) {
  float player_x = player->getPosition().x + (player->getSize().x / 2.f);
  float player_y = player->getPosition().y + (player->getSize().y / 2.f);
  return static_cast<float>(sqrt(pow(pos_x - player_x, 2) + pow(pos_y - player_y, 2) * 1.0));
}

unsigned int ClassicMob::getState() {
  if (_display_attack) {return 5;}
  else if (_directions == standby) {return 0;}
  else if (_directions == north) {return 4;}
  else if (_directions == south) {return 3;}
  else if (_directions < south) {return 1;}
  else if (_directions > south) {return 2;}
}