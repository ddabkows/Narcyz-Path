 /*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Rectangle methods
*/


#include "Rectangle.hpp"


// Methods
void Rectangle::setupRectangle(float pos_x, float pos_y, sf::Color inside_color, sf::Color outline_color, float outline_thickness, float rotation) {
  _rectangle.setPosition(pos_x, pos_y);
  _rectangle.setFillColor(inside_color);
  _rectangle.setOutlineColor(outline_color);
  _rectangle.setOutlineThickness(outline_thickness);
  _rectangle.setRotation(rotation);
}

void Rectangle::moveX(float move_x) {
  _rectangle.setPosition(getX() + move_x, getY());
}


// Setters
void Rectangle::setPosition(float pos_x, float pos_y) {
  _rectangle.setPosition(pos_x, pos_y);
}

// Getters
const sf::RectangleShape& Rectangle::getRectangle() const {return _rectangle;}
const float& Rectangle::getX() const {return _rectangle.getPosition().x;}
const float& Rectangle::getY() const {return _rectangle.getPosition().y;}