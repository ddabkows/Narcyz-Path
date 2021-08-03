/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game main cpp
*/


#include "../GUI/GUI.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

int main() {
  GUI gui{};
  gui.displayMenus();
  return 0;
}