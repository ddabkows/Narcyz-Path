/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Moving Entity methods
*/


#include "MovingEntity.hpp"


// Methods
void MovingEntity::horizontalMove() {
  _position.x += _velocity;
}

void MovingEntity::verticalMove(std::vector<std::shared_ptr<GameEntity>> game_entities, Dimensions game_board) {
  _position.y += _velocity;
  for (size_t entity = 0; entity < game_entities.size(); ++entity) {
    float entity_pos_x  = game_entities[entity]->getPosition().x;
    float entity_size_x = game_entities[entity]->getSize().x;
    if (entity_pos_x < _position.x + _size.x || 
         _position.x < entity_pos_x + entity_size_x) {
      float entity_pos_y  = game_entities[entity]->getPosition().y;
      float entity_size_y = game_entities[entity]->getSize().y;
      if (entity_pos_y + entity_size_y < _position.y) {
        _position.y = entity_pos_y + entity_size_y;
      }
      else if (_position.y + _size.y < entity_pos_y) {
        _position.y = entity_pos_y - _size.y;
      }
    }
  }
}

void MovingEntity::oblicMove(float move_x, float move_y) {
  _position.x += move_x;
  _position.y += move_y;
}

void MovingEntity::move(std::vector<std::shared_ptr<GameEntity>> game_entities, Dimensions game_board) {
  if (_directions.north) {
    if (!_directions.west && !_directions.east && !_directions.south) {
       verticalMove(game_entities, game_board);
    }
  }
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
  move(game_entities, game_board);
}

void MovingEntity::updateVelocity(Directions updating_directions, std::vector<std::shared_ptr<GameEntity>> game_entities, Dimensions game_board) {
  checkNewDirectionsConsequences(updating_directions, game_entities, game_board);
}