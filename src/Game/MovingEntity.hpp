/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Moving Entity 
*/


#include <vector>
#include <memory>
#include <iostream>

#include "GameEntity.hpp"
#include "GameMacros.hpp"


#ifndef _MOVING_ENTITY_HPP
#define _MOVING_ENTITY_HPP


class MovingEntity : public GameEntity {
  private:
    // Trait
    using myClass = MovingEntity;

  protected:
    float _max_velocity;


  public:
    // Constructor
    MovingEntity() = default;

    MovingEntity(float size_x, float size_y, float pos_x, float pos_y, float max_velocity) : 
                                                                      GameEntity(size_x, size_y, pos_x, pos_y),
                                                                      _max_velocity(max_velocity)
                                                                       {}

    // Copy
    MovingEntity(const myClass& moving_entity) : GameEntity(moving_entity),
                                                 _max_velocity(moving_entity._max_velocity) {
      _position = moving_entity._position;
      _size = moving_entity._size;
    }
    myClass& operator=(const myClass&) = delete;

    // Move
    MovingEntity(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    

    // Setters

    // Getters
    
    // Destructor
    ~MovingEntity() = default;

};
#endif