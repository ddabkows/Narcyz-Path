/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Classic weapon methods
*/


#include "ClassicWeapon.hpp"


void ClassicWeapon::attack(std::vector<std::shared_ptr<MovingEntity>> mobs, float time) {
  if (time - _last_hit > _cooldown) {
    _attack_to_display = true;
    _attack_display.display_moment = time;
    _last_hit = time;
    if (_attack_display.attack_direction == west || _attack_display.attack_direction == east) {
      if (_attack_display.size.x < _attack_display.size.y) {_attack_display.size = Dimensions(_attack_display.size.y, _attack_display.size.x);}
      _attack_display.pos.y = _attack_display.pos.y - ((_attack_display.size.y - _player_size_y) / 2.f);
      if (_attack_display.attack_direction == west) {
        _attack_display.pos.x = _attack_display.pos.x - _attack_display.size.x;
        _attack_display.display_pos.x = _attack_display.pos.x + _attack_display.starting_size.x;
        _attack_display.display_pos.y = _attack_display.pos.y + _attack_display.starting_size.y;  
      }
      else {
        _attack_display.pos.x = _attack_display.pos.x + _player_size_x;
        _attack_display.display_pos = _attack_display.pos;
      }
    }
    else {
      if (_attack_display.size.x > _attack_display.size.y) {_attack_display.size = Dimensions(_attack_display.size.y, _attack_display.size.x);}
      _attack_display.pos.x = _attack_display.pos.x - ((_attack_display.size.x - _player_size_x) / 2.f);
      if (_attack_display.attack_direction == north) {
        _attack_display.pos.y = _attack_display.pos.y - _attack_display.size.y;
        _attack_display.display_pos.x = _attack_display.pos.x;
        _attack_display.display_pos.y = _attack_display.pos.y + _attack_display.starting_size.x;
      }
      else {
        _attack_display.pos.y = _attack_display.pos.y + _player_size_y;
        _attack_display.display_pos.x = _attack_display.pos.x + _attack_display.starting_size.y;
        _attack_display.display_pos.y = _attack_display.pos.y;
      }
    }
    for (std::size_t mob_index = 0; mob_index < mobs.size(); ++mob_index) {
      std::shared_ptr<MovingEntity> mob = mobs[mob_index];
      if (_attack_display.pos.x <= mob->getPosition().x + mob->getSize().x && mob->getPosition().x <= _attack_display.pos.x + _attack_display.size.x &&
          _attack_display.pos.y <= mob->getPosition().y + mob->getSize().y && mob->getPosition().y <= _attack_display.pos.y + _attack_display.size.y) {
            mob->takeDamage(_damage);
          }
    }
  }
}