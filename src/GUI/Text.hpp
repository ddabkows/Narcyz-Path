/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for text
*/


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <memory>


#ifndef _TEXT_HPP
#define _TEXT_HPP


class Text {
  private:
    // Trait
    using myClass = Text;

  protected:
    sf::Text _text;

  public:
    // Constructor
    Text() : _text() {};
    Text(float pos_x, float pos_y, sf::Color inside_color, sf::Color outside_color, float rotation, std::shared_ptr<sf::Font> font, std::string string) :
          _text() {
      setupText(pos_x, pos_y, inside_color, outside_color, rotation, font, string);
    }

    // Copy
    Text(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Text(myClass&&) = default;
    myClass& operator=(myClass&&) = default;

    // Methods
    void setupText(float, float, sf::Color, sf::Color, float, std::shared_ptr<sf::Font> font, std::string string);

    // Setters
    void setPosition(float, float);
    void setScale(float, float);

    // Getters
    const sf::Text& getText() const;
    float getX() const;
    float getY() const;
    const sf::Vector2f& getScale() const;

    // Destructor
    ~Text() = default;

};
#endif