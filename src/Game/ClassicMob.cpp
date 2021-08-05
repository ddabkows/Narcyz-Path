/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Classic Mob methods
*/


#include "ClassicMob.hpp"


// Methods
void ClassicMob::move(std::shared_ptr<Player> player, std::vector<std::shared_ptr<Mob>> other_mobs, const std::vector<std::shared_ptr<GameEntity>> walls, float time) {
  Dimensions new_position(INFINITY, INFINITY);
  for (int quadrant = 0; quadrant < _circle_div_max; ++quadrant) {
    float new_pos_x = _position.x + _max_velocity * static_cast<float>(cos(static_cast<float>(quadrant) / _circle_div_iterator * M_PI));
    float new_pos_y = _position.y + _max_velocity * static_cast<float>(sin(static_cast<float>(quadrant) / _circle_div_iterator * M_PI));
    if (!(player->getPosition().x <= new_pos_x + _size.x && new_pos_x <= player->getPosition().x + player->getSize().x &&
           player->getPosition().y <= new_pos_y + _size.y && new_pos_y <= player->getPosition().y + player->getSize().y)) {
      bool wall_conflict = false;
      for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
        std::shared_ptr<GameEntity> wall = walls[wall_index];
        if (checkCollisionGE(Dimensions(new_pos_x, new_pos_y), wall)) {
          wall_conflict = true;
          break;
        }
      }
      if (!wall_conflict) {
        bool other_mob_conflict = false;
        for (std::size_t other_mob_index = 0; other_mob_index < other_mobs.size(); ++other_mob_index) {
          std::shared_ptr<MovingEntity> other_mob = other_mobs[other_mob_index];
          if (checkCollisionME(Dimensions(new_pos_x, new_pos_y), other_mob)) {
            other_mob_conflict = true;
            break;
          } 
        }
        if (!other_mob_conflict) {
          if (checkDistanceToPlayer(player, new_pos_x, new_pos_y) < checkDistanceToPlayer(player, new_position.x, new_position.y)) {
            new_position = Dimensions(new_pos_x, new_pos_y);  
            if (quadrant <= 5) _directions = Directions(quadrant + 3);
            else _directions = Directions(quadrant - 5);
          }
        }
      }
    }
    else {
      chargeAttack(time);
    }
    attack(player, time);
  }
  if (new_position != Dimensions(INFINITY, INFINITY)) {
    _position.x = new_position.x;
    _position.y = new_position.y;
  }
}
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
  return 0;
}