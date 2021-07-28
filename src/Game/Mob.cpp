/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Mob methods
*/


#include "Mob.hpp"


// Methods
void Mob::move(std::shared_ptr<GameEntity> player, std::vector<std::shared_ptr<Mob>> other_mobs, const std::vector<std::shared_ptr<GameEntity>> walls) {
  float step_dist = _max_velocity;
  Dimensions new_position(_position.x, _position.y);
  for (int quadrant = 0; quadrant < 8; ++quadrant) {
    float new_pos_x = _position.x + step_dist * static_cast<float>(cos(static_cast<float>(quadrant) / 4 * M_PI));
    float new_pos_y = _position.y + step_dist * static_cast<float>(sin(static_cast<float>(quadrant) / 4 * M_PI));
    if (!(player->getPosition().x <= new_pos_x + _size.x && new_pos_x <= player->getPosition().x + player->getSize().x &&
           player->getPosition().y <= new_pos_y + _size.y && new_pos_y <= player->getPosition().y + player->getSize().y)) {
      bool wall_conflict = false;
      for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
        if (walls[wall_index]->getPosition().x <= new_pos_x + _size.x && new_pos_x <= walls[wall_index]->getPosition().x + walls[wall_index]->getSize().x &&
            walls[wall_index]->getPosition().y <= new_pos_y + _size.y && new_pos_y <= walls[wall_index]->getPosition().y + walls[wall_index]->getSize().y) {
          wall_conflict = true;
          break;
        }
      }
      if (!wall_conflict) {
        bool other_mob_conflict = false;
        for (std::size_t other_mob_index = 0; other_mob_index < other_mobs.size(); ++other_mob_index) {
          if (other_mobs[other_mob_index]->getPosition().x <= new_pos_x + _size.x && new_pos_x <= other_mobs[other_mob_index]->getPosition().x + other_mobs[other_mob_index]->getSize().x &&
               other_mobs[other_mob_index]->getPosition().y <= new_pos_y + _size.y && new_pos_y <= other_mobs[other_mob_index]->getPosition().y + other_mobs[other_mob_index]->getSize().y) {
            other_mob_conflict = true;
            break;
          } 
        }
        if (!other_mob_conflict) {
          if (checkDistanceToPlayer(player, new_pos_x, new_pos_y) < checkDistanceToPlayer(player, new_position.x, new_position.y)) {
            new_position = Dimensions(new_pos_x, new_pos_y);  
          }
        }
      }
    }
  }
  _position.x = new_position.x;
  _position.y = new_position.y;
  std::cout << "Final choice: " << checkDistanceToPlayer(player, new_position.x, new_position.y) << std::endl << std::endl;
}

float Mob::checkDistanceToPlayer(std::shared_ptr<GameEntity> player, float new_pos_x, float new_pos_y) {
  return static_cast<float>(sqrt(pow(new_pos_x - player->getPosition().x, 2) + pow(new_pos_y - player->getPosition().y, 2) * 1.0));
}