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
  Dimensions new_position(_position.x, _position.y);
  for (int quadrant = 0; quadrant < _circle_div_max; ++quadrant) {
    float new_pos_x = _position.x + _max_velocity * static_cast<float>(cos(static_cast<float>(quadrant) / _circle_div_iterator * M_PI));
    float new_pos_y = _position.y + _max_velocity * static_cast<float>(sin(static_cast<float>(quadrant) / _circle_div_iterator * M_PI));
    if (!(player->getPosition().x <= new_pos_x + _size.x && new_pos_x <= player->getPosition().x + player->getSize().x &&
           player->getPosition().y <= new_pos_y + _size.y && new_pos_y <= player->getPosition().y + player->getSize().y)) {
      bool wall_conflict = false;
      for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
        std::shared_ptr<GameEntity> wall = walls[wall_index];
        if (wall->getPosition().x <= new_pos_x + _size.x && new_pos_x <= wall->getPosition().x + wall->getSize().x &&
          wall->getPosition().y <= new_pos_y + _size.y && new_pos_y <= wall->getPosition().y + wall->getSize().y) {
          wall_conflict = true;
          break;
        }
      }
      if (!wall_conflict) {
        bool other_mob_conflict = false;
        for (std::size_t other_mob_index = 0; other_mob_index < other_mobs.size(); ++other_mob_index) {
          std::shared_ptr<MovingEntity> other_mob = other_mobs[other_mob_index];
          if (checkCollisionME(other_mob)) {
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
  _position.x = new_position.x;
  _position.y = new_position.y;
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