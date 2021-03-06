/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Master
*/


#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../Game/GameMacros.hpp"
#include "GUIMacros.hpp"
#include "Skin.hpp"


#ifndef _MASTER_HPP
#define _MASTER_HPP


class Master {
  private:
    // Trait
    using myClass = Master;

    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<sf::Font> _font_1;

  public:
    // Constructor
    Master(std::shared_ptr<sf::RenderWindow> window) : _window(window),
                                                       _font_1() {setupWindow();}

    // Copy
    Master(const myClass&) = default;
    myClass& operator=(const myClass&) = default;

    // Move
    Master(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void setupWindow();
    void displayWindow();
    void closeWindow();
    void clearWindow();
    bool pollEvent(sf::Event&);
    void drawRectangle(const sf::RectangleShape&);
    void drawText(const sf::Text&);
    // Setters

    // Getters
    std::shared_ptr<sf::RenderWindow>& getWindow();
    std::shared_ptr<sf::Font>& getFont1();
    bool getOpen();

    // Destructor
    ~Master() = default;
};
#endif