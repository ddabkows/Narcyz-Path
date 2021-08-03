/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Window
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
#include "Animation.hpp"


#ifndef _WINDOW_HPP
#define _WINDOW_HPP


class GUI;


class Window {
  private:
    // Trait
    using myClass = Window;

  protected:
    GUI* _gui{};
    std::shared_ptr<Master> _master{};
    std::shared_ptr<Game> _game{};

  public:
    // Constructor
    Window(GUI* gui, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Game> game) : _gui(gui),
                                                                                             _master(std::make_shared<Master>(window)),
                                                                                             _game(game) {}

    // Copy
    Window(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Window(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    virtual void updateWindow() = 0;
    virtual void processEvent(sf::Event event) = 0;
    virtual void concludeEvent() = 0;
    bool pollEvent(sf::Event&);

    // Getters
    bool getOpen();
    std::shared_ptr<Master> getMaster();

    // Destructor
    virtual ~Window() = default;


};
#endif