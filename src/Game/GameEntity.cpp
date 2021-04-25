/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameBoard methods
*/


#include "GameEntity.hpp"


// Methods
void GameEntity::horizontalMove(float move_x) {
  _position.x += move_x;
}


// Setters
void GameEntity::setSize(float size_x, float size_y) {
  _size.x = size_x;
  _size.y = size_y;
}

void GameEntity::setPosition(float pos_x, float pos_y) {
  _position.x = pos_x;
  _position.y = pos_y;
}


// Getters
const Dimensions& GameEntity::getSize() const {return _size;}
const Dimensions& GameEntity::getPosition() const {return _position;}