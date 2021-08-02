/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : MovingEntity methods
*/


#include "MovingEntity.hpp"


// Methods
void MovingEntity::takeDamage(int damage) {_hp -= damage;}
bool MovingEntity::checkCollisionGE(std::shared_ptr<GameEntity> game_entity) {
  return (_position.x <= game_entity->getPosition().x + game_entity->getSize().x && game_entity->getPosition().x <= _position.x + _size.x &&
          _position.y <= game_entity->getPosition().y + game_entity->getSize().y && game_entity->getPosition().y <= _position.y + _size.y);
}
bool MovingEntity::checkCollisionME(std::shared_ptr<MovingEntity> moving_entity) {
  return (_position.x <= moving_entity->getPosition().x + moving_entity->getSize().x && moving_entity->getPosition().x <= _position.x + _size.x &&
    _position.y <= moving_entity->getPosition().y + moving_entity->getSize().y && moving_entity->getPosition().y <= _position.y + _size.y);
}


// Getter
float MovingEntity::getHealthProportion() const {return (static_cast<float>(_hp)/static_cast<float>(_max_hp));}
const int& MovingEntity::getHealth() const {return _hp;}