/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameBoard methods
*/


#include "GameBoard.hpp"


// Setters
void GameBoard::setSize(float size_x, float size_y) {
  _inside_limits.x = size_x;
  _inside_limits.y = size_y;
}


// Getters
const Dimensions& GameBoard::getSize() const {return _inside_limits;}
