/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Master methods
*/


#include "Master.hpp"


//Methods
void Master::setupWindow() {
  _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(static_cast<int>(_projection_size_x), static_cast<int>(_projection_size_y)),
                                                             "Narcyz Path");
  _window->setFramerateLimit(120);
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


// Setters

// Getters
std::shared_ptr<sf::RenderWindow>& Master::getWindow() {return _window;}
bool Master::getOpen() {return _window->isOpen();}