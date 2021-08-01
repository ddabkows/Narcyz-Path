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
    Directions _directions{};
    float _max_velocity;

    std::size_t _quadrant_x;
    std::size_t _quadrant_y;

    int _max_hp;
    int _hp;


  public:
    // Constructor
    MovingEntity() = default;

    MovingEntity(float size_x, float size_y, float pos_x, float pos_y, float max_velocity, std::size_t quadrant_x, std::size_t quadrant_y, const int max_hp) : 
                                                                      GameEntity(size_x, size_y, pos_x, pos_y),
                                                                      _max_velocity(max_velocity),
                                                                      _quadrant_x(quadrant_x),
                                                                      _quadrant_y(quadrant_y),
                                                                      _max_hp(max_hp),
                                                                      _hp(max_hp)
                                                                       {}

    // Copy
    MovingEntity(const myClass& moving_entity) : GameEntity(moving_entity),
                                                 _directions(moving_entity._directions),
                                                 _max_velocity(moving_entity._max_velocity),
                                                 _quadrant_x(moving_entity._quadrant_x),
                                                 _quadrant_y(moving_entity._quadrant_y),
                                                 _max_hp(moving_entity._max_hp),
                                                 _hp(moving_entity._hp) {
      _position = moving_entity._position;
      _size = moving_entity._size;
    }
    myClass& operator=(const myClass&) = delete;

    // Move
    MovingEntity(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void takeDamage(int);

    // Setters

    // Getters
    float getHealthProportion() const;
    const int& getHealth() const;
    
    // Destructor
    ~MovingEntity() = default;

};
#endif