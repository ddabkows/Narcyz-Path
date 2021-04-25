/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game Entity 
*/


#include "Dimensions.hpp"


#ifndef _GAME_ENTITY_HPP
#define _GAME_ENTITY_HPP


class GameEntity {
  private:
    // Trait
    using myClass = GameEntity;

protected:
    Dimensions _position;
    Dimensions _size;
    float _velocity = 0;

  public:
    // Constructor
    GameEntity() = default;

    GameEntity(float size_x, float size_y, float pos_x, float pos_y) : _position(),
                                                               _size() {
      setSize(size_x, size_y);
      setPosition(pos_x, pos_y);
    }

    // Copy
    GameEntity(const myClass& game_entity) {
      _position = game_entity._position;
      _size = game_entity._size;
    }
    myClass& operator=(const myClass&) = delete;

    // Move
    GameEntity(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void horizontalMove(float);
    void verticalMove(float);
    void oblicMove(float, float);

    // Setters
    void setSize(float, float);
    void setPosition(float, float);

    // Getters
    const Dimensions& getSize() const;
    const Dimensions& getPosition() const;
    
    // Destructor
    ~GameEntity() = default;
};
#endif