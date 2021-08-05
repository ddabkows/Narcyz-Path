/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class for animation
*/


#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Game/Dimensions.hpp"
#include "../Game/GameMacros.hpp"


#ifndef _ANIMATION_HPP
#define _ANIMATION_HPP


class Animation final {
  private: 
    // Trait
    using myClass = Animation;

    sf::Vector2u _image_count{};
    sf::Vector2u _current_image{};

    float _last_change = 0.f;
    float _switch_time{};
    bool _repeat{};

    sf::IntRect _animation{};
    sf::Texture* _texture{};
    sf::RectangleShape _rectangle{};

  public:
    // Constructor
    Animation() = default;
    Animation(std::shared_ptr<sf::Texture> texture, sf::Vector2u image_count, float total_time, bool repeat,
              Dimensions position,Dimensions size, float rotation): _image_count(image_count),
                                                                    _switch_time(total_time/static_cast<float>(image_count.x)),
                                                                    _repeat(repeat),
                                                                    _texture(&*texture),
                                                                    _rectangle(sf::Vector2f(size.x, size.y)) {
      _current_image.x = 0;
      _current_image.y = 0;
      _animation.width = static_cast<int>(texture->getSize().x / _image_count.x);
      _animation.height = static_cast<int>(texture->getSize().y / _image_count.y);
      _rectangle.setTexture(_texture);
      _rectangle.setPosition(position.x, position.y);
      _rectangle.setRotation(45 * rotation - 135);
    }

    // Copy
    Animation(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Animation(myClass&&) = default;
    myClass& operator=(myClass&&) = default;

    // Methods
    void update(unsigned int);
    void nextImage(float);

    // Setters
    void setLoop(bool);
    void setPosition(float, float);
    void setSwitchTime(float);

    // Getters
    const bool& checkLoop() const;
    bool checkLastImage();
    sf::RectangleShape getRectangle();
    const float& getX() const;
    const float& getY() const;

    // Destructor
    ~Animation() = default;
};
#endif