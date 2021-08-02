/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Window methods
*/


#include "Window.hpp"


// Methods
bool Window::pollEvent(sf::Event& event) {return _master->pollEvent(event);}

// Getters
std::shared_ptr<Master> Window::getMaster() {return _master;}
bool Window::getOpen() {return _master->getOpen();}