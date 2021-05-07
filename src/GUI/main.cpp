/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game main cpp
*/


#include "GameWindow.hpp"
#include "Master.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


int main() {
  GameWindow game_win{};
  Master master{};
  bool keep_program_open = true;
  
  while (keep_program_open) {
    sf::Event event;

    while (master.getWindow()->pollEvent(event)) { game_win.processEvent(event); }
    //while (game_win.pollEvent(event)) {game_win.processEvent(event);}
    game_win.updateWindow();

    if (!game_win.getOpen()) {
      keep_program_open = false;
    }
  }
  return 0;
}