/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for rectangle shapes
*/


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_


class Rectangle final {
  private:
    // Trait
    using myClass = Rectangle; 

    sf::RectangleShape _rectangle;
  
  public:
    //Constructor
    Rectangle(float size_x, float size_y, float pos_x, float pos_y, sf::Color inside_color, sf::Color outline_color, float outline_thickness, float rotation) : 
      _rectangle(sf::Vector2f(size_x, size_y)) {
      setupRectangle(pos_x, pos_y, inside_color, outline_color, outline_thickness, rotation);
    }

    // Copy
    Rectangle(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Rectangle(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void setupRectangle(float, float, sf::Color, sf::Color, float, float);
    void moveX(float);

    // Setters
    void setPosition(float, float);

    // Getters
    const sf::RectangleShape& getRectangle() const;
    const float& getX() const;
    const float& getY() const;

    // Destructor
    ~Rectangle() = default;
};
#endif