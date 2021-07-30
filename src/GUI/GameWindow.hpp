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
#include "../Game/AttackToDisplay.hpp"


#ifndef _GAME_WINDOW_HPP
#define _GAME_WINDOW_HPP


class GameWindow {
  private:
    // Trait
    using myClass = GameWindow;

    Rectangle _background;
    Rectangle _player;
    std::vector<Rectangle> _player_hp{};
    Master _master;
    Game _game;
    std::vector<Rectangle> _walls{};
    std::vector<Rectangle> _mobs{};
    std::vector<Rectangle> _attacks{};
    std::vector<AttackToDisplay> _attacks_displays{};
    std::vector<std::vector<Rectangle>> _mobs_hp{};

    bool _top_clicked = false;
    bool _bot_clicked = false;
    bool _rgt_clicked = false;
    bool _lft_clicked = false;
    bool _top_attack = false;
    bool _bot_attack = false;
    bool _rgt_attack = false;
    bool _lft_attack = false;
    bool _open_window = true;
    bool _swap_pressed = false;

    Directions _player_direction;
    Directions _player_attack_direction;
    Text _spawn_message;
    Text _keys_swap;

  public:
    // Constructor
    GameWindow() : _background(_projection_size_x, _projection_size_y, 0.f, 0.f, sf::Color(0, 50, 0, 255), sf::Color(0, 0, 0, 255), 0.f, 0.f),
                   _player(_player_size_x, _player_size_y, _game_board_size_y - _player_size_y, (_projection_size_x - _player_size_x) / 2.f,
                   sf::Color(0, 0, 100), sf::Color(0, 0, 0, 255), 0.5f, 0.f),
                   _master(),
                   _game(),
                   _player_direction(standby),
                   _player_attack_direction(standby),
                   _spawn_message(20.f, 20.f, sf::Color::Black, sf::Color::White, 0.f, _master.getFont1(), _spawn_text),
                   _keys_swap(1388.f, 10.f, sf::Color::Black, sf::Color::White, 0.f, _master.getFont1(), _swap_keys_text) {}
    
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
    void drawMobs(std::size_t, std::size_t);
    void drawWalls(std::size_t, std::size_t);
    void drawPlayer();
    void drawAttacks();
    void deleteAttacksDisplays();

    // Setters
    void setPlayerPosition();
    void setPlayerDirections();

    // Getters
    const Directions& getPlayerDirections() const;
    bool getOpen();
    Master& getMaster();

    // Destructor
    ~GameWindow() = default;
};
#endif