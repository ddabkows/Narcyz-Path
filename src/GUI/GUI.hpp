/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of GUI
*/


#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "../Game/Game.hpp"


#ifndef _GUI_HPP
#define _GUI_HPP


class Window;


class GUI {
  private:
    // Trait
    using myClass = GUI;

    std::shared_ptr<Window> _window = nullptr;
    std::shared_ptr<Game> _game = std::make_shared<Game>();
    std::shared_ptr<sf::RenderWindow> _display_window = std::make_shared<sf::RenderWindow>();
    bool _open = true;

  public:
    // Constructor
    GUI() {init();}

    // Copy
    GUI(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    GUI(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void init();
    void setWindow(std::shared_ptr<Window>);
    void displayMenus();

    // Getters
    bool getOpen();

    // Destructor
    ~GUI() = default;
};
#endif