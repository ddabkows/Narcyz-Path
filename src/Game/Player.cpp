/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Player methods
*/


#include "Player.hpp"


// Methods
void Player::horizontalMove(int right, std::vector<std::shared_ptr<GameEntity>> mobs, const std::vector<std::shared_ptr<GameEntity>> walls) {
  bool conflict;
  conflict = checkHorizontal(right, mobs);
  if (!conflict) conflict = checkHorizontal(right, walls);
  if (!conflict) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration;
    }
    _position.x += static_cast<float>(right) * (_player_movement_mult / (_velocity) + _player_movement_trans);
  }
}

bool Player::checkHorizontal(int right, std::vector<std::shared_ptr<GameEntity>> entities) {
  bool conflict = false;
  for (std::size_t entity_index = 0; entity_index < entities.size(); ++entity_index) {
    float entity_position_y = entities[entity_index]->getPosition().y;
    float entity_size_y = entities[entity_index]->getSize().y;
    if (entity_position_y < _position.y + _size.y && _position.y < entity_position_y + entity_size_y) {
      float entity_position_x = entities[entity_index]->getPosition().x;
      float entity_size_x = entities[entity_index]->getSize().x;
      if ((0 < right && _position.x + _size.x <= entity_position_x && !(_position.x + _size.x + (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans) < entity_position_x)) ||
        (right < 0 && entity_position_x + entity_size_x <= _position.x && !(entity_position_x + entity_size_x < _position.x - (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans)))) {
        conflict = true;
        _velocity = 0.f;
        if (0 < right && _position.x + _size.x < entity_position_x) {
          _position.x = entity_position_x - _size.x;
        }
        else if (right < 0 && entity_position_x + entity_size_x < _position.x) {
          _position.x = entity_position_x + entity_size_x;
        }
        break;
      }
    }
  }
  return conflict;
}

void Player::verticalMove(int down, std::vector<std::shared_ptr<GameEntity>> mobs, const std::vector<std::shared_ptr<GameEntity>> walls) {
  bool conflict;
  conflict = checkVertical(down, mobs);
  if (!conflict) conflict = checkVertical(down, walls);
  
  if (!conflict) {
    if (_velocity + _acceleration < _max_velocity) {
      _velocity += _acceleration;
    }
    _position. y += static_cast<float>(down) * (_player_movement_mult / (_velocity) + _player_movement_trans);
  }
}

bool Player::checkVertical(int down, std::vector<std::shared_ptr<GameEntity>> entities) {
  bool conflict = false;
  for (std::size_t entity_index = 0; entity_index < entities.size(); ++entity_index) {
    float entity_position_x = entities[entity_index]->getPosition().x;
    float entity_size_x = entities[entity_index]->getSize().x;
    if (entity_position_x < _position.x + _size.x && _position.x < entity_position_x + entity_size_x) {
      float entity_position_y = entities[entity_index]->getPosition().y;
      float entity_size_y = entities[entity_index]->getSize().y;
      if ((0 < down && _position.y + _size.y <= entity_position_y && !(_position.y + _size.y + (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans) < entity_position_y)) ||
         (down < 0 && entity_position_y + entity_size_y <= _position.y && !(entity_position_y + entity_size_y < _position.y - (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans)))) {
        conflict = true;
        _velocity = 0.f;
        if (0 < down && _position.y + _size.y < entity_position_y) {
          _position.y = entity_position_y - _size.y;
        }
        else if (down < 0 && entity_position_y + entity_size_y < _position.y) {
          _position.y = entity_position_y + entity_size_y;
        }
        break;
      }
    }
  }
  return conflict;
}

void Player::oblicMove(int right, int down, std::vector<std::shared_ptr<GameEntity>> mobs, const std::vector<std::shared_ptr<GameEntity>> walls) {
  bool conflict_horizontal;
  conflict_horizontal = checkHorizontal(right, mobs);
  if (!conflict_horizontal) conflict_horizontal = checkHorizontal(right, walls);
  
  if (!conflict_horizontal) {
    if (_velocity + _acceleration < _max_velocity) {
      _velocity += _acceleration;
    }
    _position.x += static_cast<float>(right) * _pi_fourth * (_player_movement_mult / (_velocity)+_player_movement_trans);
  }

  bool conflict_vertical;
  conflict_vertical = checkVertical(down, mobs);
  if (!conflict_vertical) conflict_vertical = checkVertical(down, walls);

  if (!conflict_vertical) {
    if (conflict_horizontal) {
      if (_velocity + _acceleration < _max_velocity) {
        _velocity += _acceleration;
      }
    }
    _position.y += static_cast<float>(down) * _pi_fourth * (_player_movement_mult / (_velocity)+_player_movement_trans);
  }
}

void Player::move(Directions player_decision, std::vector<std::shared_ptr<MovingEntity>> mobs, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>> walls) {
  _quadrant_x = static_cast<std::size_t>(_position.x / _projection_size_x);
  _quadrant_y = static_cast<std::size_t>(_position.y / _projection_size_y);
  std::vector<std::shared_ptr<GameEntity>> in_player_zone_walls = walls[_quadrant_x][_quadrant_y];
  std::vector<std::shared_ptr<GameEntity>> reinterpreted_mobs{};
  for (std::size_t mob_index = 0; mob_index < mobs.size(); ++mob_index) {
    reinterpreted_mobs.emplace_back(mobs[mob_index]);
  }
  if (player_decision - _directions > _direction_change || player_decision - _directions < -_direction_change) {
    if (!((player_decision == north && _directions == north_west) || (player_decision == north_west && _directions == north))) {
      _velocity = 0.f;
    }
  }
  switch (player_decision) {
    case north : {
      verticalMove(-1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    case north_east : {
      oblicMove(1, -1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    case east : {
      horizontalMove(1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    case south_east : {
      oblicMove(1, 1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    case south : {
      verticalMove(1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    case south_west : {
      oblicMove(-1, 1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    case west : {
      horizontalMove(-1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    case north_west : {
      oblicMove(-1, -1, reinterpreted_mobs, in_player_zone_walls);
      break;
    }
    default : {
      _velocity = 0;
      break;
    }
  }
  _directions = player_decision;
  _quadrant_x = static_cast<std::size_t>(_position.x / _projection_size_x);
  _quadrant_y = static_cast<std::size_t>(_position.y / _projection_size_y);
}

void Player::attack(std::vector<std::shared_ptr<MovingEntity>> mobs, float time) {
  _weapon->attack(mobs, time);
}

void Player::attackDisplayed() {_weapon->attackDisplayed();}


// Setters
void Player::setAttackDirection(Directions new_direction) {_weapon->setDirection(new_direction);}
void Player::setAttackPosition() {_weapon->setPosition(_position);}

// Getters
const std::size_t& Player::getQuadrantX() const {return _quadrant_x;}
const std::size_t& Player::getQuadrantY() const {return _quadrant_y;}
const bool& Player::getAttackToBeDisplayed() const {return _weapon->getAttackToDisplay();}
const AttackToDisplay& Player::getAttackToDisplay() const {return _weapon->getAttackDisplay();}