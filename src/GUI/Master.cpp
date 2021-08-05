/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Master methods
*/


#include "Master.hpp"


//Methods
void Master::setupWindow() {
  _font_1 = std::make_shared<sf::Font>();
  _font_1->loadFromFile(_font_1_path);
}

void Master::clearWindow() {
  _window->clear();
}

void Master::displayWindow() {
  _window->display();
}

void Master::closeWindow() {
  _window->close();
}

bool Master::pollEvent(sf::Event& event) {
  return _window->pollEvent(event);
}

void Master::drawRectangle(const sf::RectangleShape& rectangle) {
  _window->draw(rectangle);
}

void Master::drawText(const sf::Text& text) {
  _window->draw(text);
}



// Setters


// Getters
std::shared_ptr<sf::RenderWindow>& Master::getWindow() {return _window;}
std::shared_ptr<sf::Font>& Master::getFont1() {return _font_1;}
bool Master::getOpen() {return _window->isOpen();}