/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Moving Entity methods
*/


#include "MovingEntity.hpp"


// Methods
void MovingEntity::horizontalMove(float move_x) {
  _position.x += move_x;
}

void MovingEntity::verticalMove(float move_y) {
  _position.y += move_y;
}

void MovingEntity::oblicMove(float move_x, float move_y) {
  _position.x += move_x;
  _position.y += move_y;
}

bool MovingEntity::checkNorthConflicts(std::vector<std::shared_ptr<GameEntity>> game_entities) {
  for (std::size_t entity = 0; entity < game_entities.size(); ++entity) {
    if (game_entities[entity]->getPosition().y + game_entities[entity]->getSize().y == _position.y) {return true;}
  }
  if (_position.y == 0.f) {return true;}
  return false;
}

void MovingEntity::checkNewDirectionsConsequences(Directions updating_directions, std::vector<std::shared_ptr<GameEntity>> game_entities,
                                                  Dimensions game_board) {
  if (_directions.north && updating_directions.north) {
    if (!_directions.south && !_directions.west && !_directions.east && 
        !updating_directions.south && !updating_directions.west && !updating_directions.east) {
      if (checkNorthConflicts(game_entities)) {_velocity = 0.f;}
      else {_velocity += _acceleration;}
    }
  }
  else {
    _velocity = 0.f;
  }
  if (_velocity > _max_velocity) {_velocity = _max_velocity;}
}

void MovingEntity::updateVelocity(Directions updating_directions, std::vector<std::shared_ptr<GameEntity>> game_entities, Dimensions game_board) {
  checkNewDirectionsConsequences(updating_directions, game_entities, game_board);
}