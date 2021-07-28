/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of GameWindow
*/


#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Rectangle.hpp"
#include "Master.hpp"
#include "Text.hpp"
#include "../Game/Game.hpp"
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
    Master _master;
    Game _game;
    std::vector<Rectangle> _walls{};
    Text _spawn_text;

    bool _top_clicked = false;
    bool _bot_clicked = false;
    bool _rgt_clicked = false;
    bool _lft_clicked = false;
    bool _open_window = true;

    Directions _player_direction;

  public:
    // Constructor
    GameWindow() : _background(_projection_size_x, _projection_size_y, 0.f, 0.f, sf::Color(0, 20, 0, 255), sf::Color(0, 0, 0, 255), 0.f, 0.f),
                   _player(_player_size_x, _player_size_y, _game_board_size_y - _player_size_y, (_projection_size_x - _player_size_x) / 2.f,
                   sf::Color::White, sf::Color(0, 0, 0, 255), 0.5f, 0.f),
                   _master(),
                   _game(),
                   _spawn_text(100, 100, sf::Color(0, 0, 0), sf::Color(255, 255, 255), 0.f, _master.getFont1(), std::string("Spawn Monsters")),
                   _player_direction(standby) {}
    
    // Copy
    GameWindow(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    GameWindow(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void updateWindow();
    void processEvent(sf::Event event);
    void concludeEvent();
    bool pollEvent(sf::Event&);

    // Setters
    void setPlayerPosition();
    void setPlayerDirection();

    // Getters
    const Directions& getPlayerDirections() const;
    bool getOpen();
    Master& getMaster();

    // Destructor
    ~GameWindow() = default;
};
#endif