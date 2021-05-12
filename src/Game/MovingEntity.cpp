/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Moving Entity methods
*/


#include <cmath>

#include "MovingEntity.hpp"


// Methods
void MovingEntity::horizontalMove(int right, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>> walls) {
  std::vector<std::shared_ptr<GameEntity>> in_player_zone_walls = walls[_quadrant_x][_quadrant_y];
  bool conflict = false;
  for (std::size_t wall_index = 0; wall_index < in_player_zone_walls.size(); ++wall_index) {
    float wall_position_y = in_player_zone_walls[wall_index]->getPosition().y;
    float wall_size_y = in_player_zone_walls[wall_index]->getSize().y;
    if ((wall_position_y < _position.y && _position.y < wall_position_y + wall_size_y) ||
              (_position.y < wall_position_y && wall_position_y < _position.y + _size.y)) {
      float wall_position_x = in_player_zone_walls[wall_index]->getPosition().x;
      float wall_size_x = in_player_zone_walls[wall_index]->getSize().x;
      if ((0 < right && _position.x + _size.x <= wall_position_x && !(_position.x + _size.x + (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans) < wall_position_x)) ||
         (right < 0 && wall_position_x + wall_size_x <= _position.x && !(wall_position_x + wall_size_x < _position.x - (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans)))) {
        conflict = true;
        _velocity = 0.f;
        if (0 < right && _position.x + _size.x < wall_position_x) {
          _position.x = wall_position_x - _size.x;
        }
        else if (right < 0 && wall_position_x + wall_size_x < _position.x) {
          _position.x = wall_position_x + wall_size_x;
        }
      }
    }
  }
  if (!conflict) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration;
    }
    _position.x += static_cast<float>(right) * (_player_movement_mult / (_velocity) + _player_movement_trans);
  }
}

void MovingEntity::verticalMove(int down, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>> walls) {
  std::vector<std::shared_ptr<GameEntity>> in_player_zone_walls = walls[_quadrant_x][_quadrant_y];
  bool conflict = false;
  for (std::size_t wall_index = 0; wall_index < in_player_zone_walls.size(); ++wall_index) {
    float wall_position_x = in_player_zone_walls[wall_index]->getPosition().x;
    float wall_size_x = in_player_zone_walls[wall_index]->getSize().x;
    if ((wall_position_x < _position.x && _position.x < wall_position_x + wall_size_x) ||
              (_position.x < wall_position_x && wall_position_x < _position.x + _size.x)) {
      float wall_position_y = in_player_zone_walls[wall_index]->getPosition().y;
      float wall_size_y = in_player_zone_walls[wall_index]->getSize().y;
      if ((0 < down && _position.y + _size.y <= wall_position_y && !(_position.y + _size.y + (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans) < wall_position_y)) ||
         (down < 0 && wall_position_y + wall_size_y <= _position.y && !(wall_position_y + wall_size_y < _position.y - (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans)))) {
        conflict = true;
        _velocity = 0.f;
        if (0 < down && _position.y + _size.y < wall_position_y) {
          _position.y = wall_position_y - _size.y;
        }
        else if (down < 0 && wall_position_y + wall_size_y < _position.y) {
          _position.y = wall_position_y + wall_size_y;
        }
      }
    }
  }
  if (!conflict) {
    if (_velocity + _acceleration < _max_velocity) {
      _velocity += _acceleration;
    }
    _position. y += static_cast<float>(down) * (_player_movement_mult / (_velocity) + _player_movement_trans);
  }
}

void MovingEntity::oblicMove(int right, int down, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>> walls) {
  std::vector<std::shared_ptr<GameEntity>> in_player_zone_walls = walls[_quadrant_x][_quadrant_y];
  bool conflict_horizontal = false;
  for (std::size_t wall_index = 0; wall_index < in_player_zone_walls.size(); ++wall_index) {
    float wall_position_y = in_player_zone_walls[wall_index]->getPosition().y;
    float wall_size_y = in_player_zone_walls[wall_index]->getSize().y;
    if ((wall_position_y < _position.y && _position.y < wall_position_y + wall_size_y) ||
              (_position.y < wall_position_y && wall_position_y < _position.y + _size.y)) {
      float wall_position_x = in_player_zone_walls[wall_index]->getPosition().x;
      float wall_size_x = in_player_zone_walls[wall_index]->getSize().x;
      if ((0 < right && _position.x + _size.x <= wall_position_x && !(_position.x + _size.x + (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans) < wall_position_x)) ||
         (right < 0 && wall_position_x + wall_size_x <= _position.x && !(wall_position_x + wall_size_x < _position.x - (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans)))) {
        conflict_horizontal = true;
        _velocity = 0.f;
        if (0 < right && _position.x + _size.x < wall_position_x) {
          _position.x = wall_position_x - _size.x;
        }
        else if (right < 0 && wall_position_x + wall_size_x < _position.x) {
          _position.x = wall_position_x + wall_size_x;
        }
      }
    }
  }

  bool conflict_vertical = false;
  for (std::size_t wall_index = 0; wall_index < in_player_zone_walls.size(); ++wall_index) {
    float wall_position_x = in_player_zone_walls[wall_index]->getPosition().x;
    float wall_size_x = in_player_zone_walls[wall_index]->getSize().x;
    if ((wall_position_x < _position.x && _position.x < wall_position_x + wall_size_x) ||
              (_position.x < wall_position_x && wall_position_x < _position.x + _size.x)) {
      float wall_position_y = in_player_zone_walls[wall_index]->getPosition().y;
      float wall_size_y = in_player_zone_walls[wall_index]->getSize().y;
      if ((0 < down && _position.y + _size.y <= wall_position_y && !(_position.y + _size.y + (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans) < wall_position_y)) ||
         (down < 0 && wall_position_y + wall_size_y <= _position.y && !(wall_position_y + wall_size_y < _position.y - (_player_movement_mult / (_velocity + _acceleration) + _player_movement_trans)))) {
        conflict_vertical = true;
        _velocity = 0.f;
        if (0 < down && _position.y + _size.y < wall_position_y) {
          _position.y = wall_position_y - _size.y;
        }
        else if (down < 0 && wall_position_y + wall_size_y < _position.y) {
          _position.y = wall_position_y + wall_size_y;
        }
      }
    }
  }

  if ((!conflict_horizontal) || (!conflict_vertical)) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration;
    }
  }
  if (!conflict_horizontal) {_position.x += static_cast<float>(right) * (std::sqrt(2) / 2.f) * (_player_movement_mult / (_velocity) + _player_movement_trans);}
  if (!conflict_vertical) {_position.y += static_cast<float>(down) * (std::sqrt(2) / 2.f) * (_player_movement_mult / (_velocity) + _player_movement_trans);}
}

void MovingEntity::move(Directions player_decision, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>> walls) {
  _quadrant_x = static_cast<std::size_t>(_position.x / _projection_size_x);
  _quadrant_y = static_cast<std::size_t>(_position.y / _projection_size_y);
  if (player_decision - _directions > 2 || player_decision - _directions < -2) {
    if (!((player_decision == north && _directions == north_west) || (player_decision == north_west && _directions == north))) {
      _velocity = 0.f;
    }
  }
  switch (player_decision) {
    case north : {
      verticalMove(-1, walls);
      break;
    }
    case north_east : {
      oblicMove(1, -1, walls);
      break;
    }
    case east : {
      horizontalMove(1, walls);
      break;
    }
    case south_east : {
      oblicMove(1, 1, walls);
      break;
    }
    case south : {
      verticalMove(1, walls);
      break;
    }
    case south_west : {
      oblicMove(-1, 1, walls);
      break;
    }
    case west : {
      horizontalMove(-1, walls);
      break;
    }
    case north_west : {
      oblicMove(-1, -1, walls);
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


// Getters
const std::size_t MovingEntity::getQuadrantX() const {return _quadrant_x;}
const std::size_t MovingEntity::getQuadrantY() const {return _quadrant_y;}