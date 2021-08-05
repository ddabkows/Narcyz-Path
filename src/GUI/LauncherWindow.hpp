/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of LauncherWindow
*/


#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "../Game/Game.hpp"
#include "Animation.hpp"
#include "Window.hpp"
#include "GUI.hpp"
#include "GameMaster.hpp"
#include "Rectangle.hpp"
#include "Master.hpp"
#include "Text.hpp"
#include "GameWindow.hpp"


#ifndef _LAUNCHER_WINDOW_HPP
#define _LAUNCHER_WINDOW_HPP


class LauncherWindow : public Window {
  private:
    // Trait
    using myClass = LauncherWindow;

    Text _new_game{};
    Text _exit_game{};

  public:
    // Constructor
    LauncherWindow(GUI* gui, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Game> game) : Window(gui, window, game) {
      _new_game = Text(_new_game_x, _new_game_y, sf::Color::Black, sf::Color::White, 0.f, _master->getFont1(), _new_game_text);
      _exit_game = Text(_exit_game_x, _exit_game_y, sf::Color::Black, sf::Color::White, 0.f, _master->getFont1(), _exit_game_text);
      std::cout << _new_game.getText().getGlobalBounds().width << std::endl;
      std::cout << _exit_game.getText().getGlobalBounds().width << std::endl;
    }

    // Copy
    LauncherWindow(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    LauncherWindow(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void updateWindow() override;
    void processEvent(sf::Event) override;
    void concludeEvent() override;
    void checkTextCollision(sf::Event, Text&);

    // Destructor
    ~LauncherWindow() = default;
};
#endif