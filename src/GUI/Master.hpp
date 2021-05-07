/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Master
*/


#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#ifndef _MASTER_HPP
#define _MASTER_HPP


class Master {
  private:
    // Trait
    using myClass = Master;

    std::shared_ptr<sf::RenderWindow> _window;

  public:
    // Constructor
    Master() : _window() {
    }

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

    // Setters

    // Getters
    std::shared_ptr<sf::RenderWindow>& getWindow();
    bool getOpen();

    // Destructor
    ~Master() = default;
};
#endif