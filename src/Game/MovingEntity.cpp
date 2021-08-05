/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : MovingEntity methods
*/


#include "MovingEntity.hpp"


// Methods
void MovingEntity::takeDamage(int damage) {_hp -= damage;}
bool MovingEntity::checkCollisionGE(Dimensions new_pos, std::shared_ptr<GameEntity> game_entity) {
  return (new_pos.x <= game_entity->getPosition().x + game_entity->getSize().x && game_entity->getPosition().x <= new_pos.x + _size.x &&
          new_pos.y <= game_entity->getPosition().y + game_entity->getSize().y && game_entity->getPosition().y <= new_pos.y + _size.y);
}
bool MovingEntity::checkCollisionME(Dimensions new_pos, std::shared_ptr<MovingEntity> moving_entity) {
  return (new_pos.x <= moving_entity->getPosition().x + moving_entity->getSize().x && moving_entity->getPosition().x <= new_pos.x + _size.x &&
          new_pos.y <= moving_entity->getPosition().y + moving_entity->getSize().y && moving_entity->getPosition().y <= new_pos.y + _size.y);
}


// Getter
float MovingEntity::getHealthProportion() const {return (static_cast<float>(_hp)/static_cast<float>(_max_hp));}
const int& MovingEntity::getHealth() const {return _hp;}