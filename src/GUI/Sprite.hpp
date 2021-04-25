/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for sprite
*/


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <memory>


#ifndef _SPRITE_H_
#define _SPRITE_H_
 

class Sprite {
  private:
    // Trait
    using myClass = Sprite;

protected:
    sf::Sprite _sprite;
    std::shared_ptr<sf::Texture> _texture;

  public:
    //Constructor
    Sprite(float size_x, float size_y, float pos_x, float pos_y, sf::Color inside_color, float rotation, std::shared_ptr<sf::Texture> texture)  :  _sprite(),
                                                                                                                                                                                                                                              _texture(texture) {
      setupSprite(size_x, size_y, pos_x, pos_y, inside_color, rotation);
    }

    // Copy
    Sprite(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Sprite(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void setupSprite(float, float, float, float, sf::Color, float);
    void moveX(float);

    // Setters
    void setPosition(float, float);
    void setScale(float, float);

    // Getters
    const sf::Sprite& getSprite() const;
    const float& getX() const;
    const float& getY() const;
    const sf::Vector2f& getScale() const;

    // Destructor
    ~Sprite() = default;
};
#endif