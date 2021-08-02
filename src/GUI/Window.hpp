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


class Window {
  private:
    // Trait
    using myClass = Window;

  protected:
    std::shared_ptr<Master> _master{};

  public:
    // Constructor
    Window(std::shared_ptr<sf::RenderWindow> window) {
      _master = std::make_shared<Master>(window);
    }

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