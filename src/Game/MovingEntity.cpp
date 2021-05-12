/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Moving Entity methods
*/


#include "MovingEntity.hpp"


// Methods
void MovingEntity::horizontalMove(int right) {
  if ((0 < right && _position.x + _size.x + (-1.f / (_velocity + _acceleration) + 21.f) < _game_board_size_x) || 
                                   (right < 0 && 0 < _position.x - (-1.f / (_velocity + _acceleration) + 21.f))) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration;
    }
    _position.x += static_cast<float>(right) * (-1.f / (_velocity) + 21.f);
  }
  else {
    if (0 < right && _position.x + _size.x < _game_board_size_x) {
      _velocity = 0.f;
      _position.x = _game_board_size_x - _size.x;
    }
    else if (right < 0 && 0 < _position.x) {
      _velocity = 0.f;
      _position.x = 0.f;
    }
  }
}

void MovingEntity::verticalMove(int down) {
  if ((0 < down && _position.y + _size.y + (-1.f / (_velocity + _acceleration) + 21.f) <= _game_board_size_y) || 
                                   (down < 0 && 0 <= _position.y - (-1.f / (_velocity + _acceleration) + 21.f))) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration;
    }
    _position.y += static_cast<float>(down) * (-1.f / ( _velocity) + 21.f);
  } 
  else {
    if (0 < down && _position.y + _size.y < _game_board_size_y) {
      _velocity = 0.f;
      _position.y = _game_board_size_y - _size.y;
    }
    else if (down < 0 && 0 < _position.y) {
      _velocity = 0.f;
      _position.y = 0.f;
    }
  }
}

void MovingEntity::oblicMove(int right, int down) {
  if ((0 < right && _position.x + _size.x + (-1.f / (2.f * (_velocity + _acceleration)) + 10.5f) < _game_board_size_x) ||
                                   (right < 0 && 0 < _position.x - (-1.f / (2.f * (_velocity + _acceleration)) + 10.5f))) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration/2.f;
    }
    _position.x += static_cast<float>(right) * (-1.f / (2.f * _velocity) + 10.5f);
  }
  else {
    if (0 < right && _position.x + _size.x < _game_board_size_x) {
      _velocity = 0.f;
      _position.x = _game_board_size_x - _size.x;
    }
    else if (right < 0 && 0 < _position.x) {
      _velocity = 0.f;
      _position.x = 0.f;
    }
  }
  if ((0 < down && _position.y + _size.y + (-1.f / (2.f * (_velocity + _acceleration)) + 10.5f) <= _game_board_size_y) ||
                                   (down < 0 && 0 <= _position.y - (-1.f / (2.f * (_velocity + _acceleration)) + 10.5f))) {
    if (_velocity + _acceleration < _max_velocity) { 
      _velocity += _acceleration/2.f;
    }
    _position.y += static_cast<float>(down) * (-1.f / (2.f * _velocity) + 10.5);
  }
  else {
    if (0 < down && _position.y + _size.y < _game_board_size_y) {
      _velocity = 0.f;
      _position.y = _game_board_size_y - _size.y;
    }
    else if (down < 0 && 0 < _position.y) {
      _velocity = 0.f;
      _position.y = 0.f;
    }
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
  _directions = player_decision;
}