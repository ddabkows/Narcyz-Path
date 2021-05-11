/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Moving Entity methods
*/


#include "MovingEntity.hpp"


// Methods
void MovingEntity::horizontalMove(int right) {
  if ((0 < right && _position.x + _size.x + _velocity < _game_board_size_x) || (right < 0 && 0 < _position.x - _velocity)) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration;
    }
    _position.x += static_cast<float>(right) * (_velocity * _velocity / 4.f +  12.f);
  }
  else {
    _velocity = 0.f;
  }
}

void MovingEntity::verticalMove(int down) {
  if ((0 < down && _position.y + _size.y + _velocity < _game_board_size_y) || (down < 0 && 0 < _position.y - _velocity)) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration;
    }
    _position.y += static_cast<float>(down) * (_velocity * _velocity / 4.f + 12.f);
  } 
  else {
    _velocity = 0.f;
  }
}

void MovingEntity::oblicMove(int right, int down) {
  if ((0 < right && _position.x + _size.x + _velocity < _game_board_size_x) || (right < 0 && 0 < _position.x - _velocity)) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration/2.f;
    }
    _position.x += static_cast<float>(right) * (_velocity * _velocity / 8.f + 6.f);
  }
  else {
    _velocity = 0.f;
  }
  if ((0 < down && _position.y + _size.y + _velocity < _game_board_size_y) || (down < 0 && 0 < _position.y - _velocity)) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration/2.f;
    }
    _position.y += static_cast<float>(down) * (_velocity * _velocity / 8.f + 6.f);
  }
  else {
    _velocity = 0.f;
  }
}

void MovingEntity::move(Directions player_decision) {
  if (player_decision - _directions > 2 || player_decision - _directions < -2) {
    if (!((player_decision == north && _directions == north_west) || (player_decision == north_west && _directions == north))) {
      _velocity = 0.f;
    }
  }
  switch (player_decision) {
    case north : {
      verticalMove(-1);
      break;
    }
    case north_east : {
      oblicMove(1, -1);
      break;
    }
    case east : {
      horizontalMove(1);
      break;
    }
    case south_east : {
      oblicMove(1, 1);
      break;
    }
    case south : {
      verticalMove(1);
      break;
    }
    case south_west : {
      oblicMove(-1, 1);
      break;
    }
    case west : {
      horizontalMove(-1);
      break;
    }
    case north_west : {
      oblicMove(-1, -1);
      break;
    }
    default : {
      _velocity = 0;
      break;
    }
  }
  std::cout << _velocity * _velocity / 4.f + 12.f << std::endl;
  _directions = player_decision;
}