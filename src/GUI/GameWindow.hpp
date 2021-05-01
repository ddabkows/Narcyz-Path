/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of GameWindow
*/


#include <memory>

#include "Rectangle.hpp"
#include "../Game/Dimensions.hpp"
#include "../Game/GameMacros.hpp"
#include "../Game/Directions.hpp"


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
    GameWindow() : _background(_projection_size_x, _projection_size_y, 0.f, 0.f, sf::Color(120, 120, 120, 120), sf::Color(0, 0, 0, 255), 0.f, 0.f),
                   _player(_player_size_x, _player_size_y, _game_board_size_y - _player_size_y, (_projection_size_x - _player_size_y) / 2.f,
                   sf::Color(255, 255, 255, 255), sf::Color(0, 0, 0, 255), 0.5f, 0.f) {}
    
    // Copy
    GameWindow(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameWindow(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void drawWindow();
    void processEvent(sf::Event);

    // Setters
    void setPlayerPosition(const Dimensions&);

    // Getters
    const Directions& getPlayerDirections() const;

    // Destructor
    ~GameWindow() = default;
};
#endif