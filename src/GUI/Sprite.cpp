/*
 Author : Dominik Dabkowski
 Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
 Code   : Sprite methods
*/


#include "Sprite.hpp"


// Methods
void Sprite::setupSprite(float size_x, float size_y, float pos_x, float pos_y, sf::Color color, float rotation) {
  _sprite.setScale(size_x, size_y);
  _sprite.setPosition(pos_x, pos_y);
  _sprite.setColor(color);
  _sprite.setRotation(rotation);
  _sprite.setTexture(*_texture);
}

void Sprite::moveX(float move_x) {
  _sprite.setPosition(getX() + move_x, getY());
}


// Setter
void Sprite::setPosition(float pos_x, float pos_y) {
  _sprite.setPosition(pos_x, pos_y);
}

void Sprite::setScale(float scale_x, float scale_y) {
  _sprite.setScale(scale_x, scale_y);
}

// Getters
const sf::Sprite& Sprite::getSprite() const { return _sprite;}
const float& Sprite::getX() const {return _sprite.getPosition().x;}
const float& Sprite::getY() const {return _sprite.getPosition().y;}
const sf::Vector2f& Sprite::getScale() const { return _sprite.getScale();}
