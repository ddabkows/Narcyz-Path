/*
 Author : Dominik Dabkowski
 Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
 Code   : Text methods
*/


#include "Text.hpp"


// Methods
void Text::setupText(float pos_x, float pos_y, sf::Color inside_color, sf::Color outside_color, float rotation, std::shared_ptr<sf::Font> font, std::string string) {
  _text.setFont(*font);
  _text.setString(string);
  _text.setPosition(pos_x, pos_y);
  _text.setFillColor(inside_color);
  _text.setOutlineColor(outside_color);
  _text.rotate(rotation);
  _text.setStyle(sf::Text::Bold);
  _text.setOutlineThickness(1.f);
  _text.setScale(1.f, 1.f);
}
void Text::click() {_clicked = true;}
void Text::unClick() {_clicked = false;}


// Setters
void Text::setPosition(float pos_x, float pos_y) {
  _text.setPosition(pos_x, pos_y);
}

void Text::setScale(float scale_x, float scale_y) {
  _text.setScale(scale_x, scale_y);
}


// Getters
const sf::Text& Text::getText() const {return _text;}
float Text::getX() const {return _text.getGlobalBounds().left;}
float Text::getY() const {return _text.getGlobalBounds().top;}
const sf::Vector2f& Text::getScale() const {return _text.getScale();}
const bool& Text::isClicked() const {return _clicked;}