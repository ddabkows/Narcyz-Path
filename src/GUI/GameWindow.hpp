/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of GameWindow
*/


#include <memory>

#include "Rectangle.hpp"
#include "../Game/Dimensions.hpp"
#include "../Game/GameMacros.hpp"


#ifndef _GAME_WINDOW_HPP
#define _GAME_WINDOW_HPP


class GameWindow {
  private:
    // Trait
    using myClass = GameWindow;

    Rectangle _background;
    Rectangle _player;

    bool _top_clicked = false;
    bool _bot_clicked = false;
    bool _rgt_clicked = false;
    bool _lft_clicked = false;

  public:
    // Constructor
    GameWindow()
};
#endif