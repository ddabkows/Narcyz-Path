/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GUI methods
*/


#include "Window.hpp"
#include "GameWindow.hpp"
#include "GUI.hpp"


// Methods
void GUI::init() {_window = std::make_shared<GameWindow>(this, _display_window, _game);}
void GUI::setWindow(std::shared_ptr<Window> window) {_window = window;}
void GUI::displayMenus() {
  while (_window->getOpen()) {
    sf::Event event;
    while (_window->pollEvent(event)) _window->processEvent(event);
    _window->concludeEvent();
    _window->updateWindow();
  }
}
bool GUI::getOpen() {return _open;}