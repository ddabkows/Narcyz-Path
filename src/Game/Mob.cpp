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
void Mob::move(std::shared_ptr<Player> player, std::vector<std::shared_ptr<Mob>> other_mobs, const std::vector<std::shared_ptr<GameEntity>> walls, float time) {
  Dimensions old_position = _position;
  float best_distance = INFINITY;
  Dimensions best_position = _position;
  if (!(checkDistanceToPlayer(player, _position.x, _position.y) <= _classic_mob_attack_radius/2.f)) {
    for (int quadrant = 0; quadrant < _circle_div_max; ++quadrant) {
      _position.x = old_position.x + _max_velocity * static_cast<float>(cos(static_cast<float>(quadrant) / _circle_div_iterator * M_PI));
      _position.y = old_position.y + _max_velocity * static_cast<float>(sin(static_cast<float>(quadrant) / _circle_div_iterator * M_PI));
      bool wall_conflict = false;
      for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
        std::shared_ptr<GameEntity> wall = walls[wall_index];
          if (checkCollisionGE(wall)) {
            wall_conflict = true;
            _position = old_position;
            break;
          }
      }
      if (!wall_conflict) {
        bool other_mob_conflict = false;
        for (std::size_t other_mob_index = 0; other_mob_index < other_mobs.size(); ++other_mob_index) {
          std::shared_ptr<MovingEntity> other_mob = other_mobs[other_mob_index];
          if (checkCollisionME(other_mob)) {
            other_mob_conflict = true;
            _position = old_position;
            break;
          }
        }
        if (!other_mob_conflict) {
          float new_dist = checkDistanceToPlayer(player, _position.x, _position.y);
          if (new_dist < best_distance) {
            best_distance = new_dist;
            best_position = _position;
            if (quadrant <= 5) _directions = Directions(quadrant + 3);
            else _directions = Directions(quadrant - 5);
          }
          else _position = old_position;
        }
      }
      _position = best_position;
    }
  }  
  else {
    chargeAttack(time);
    _position = old_position;
  }
  attack(player, time);
}

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