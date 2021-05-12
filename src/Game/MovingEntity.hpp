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

    Directions _directions{};
    float _max_velocity;
    float _acceleration;
    float _velocity = 0.f;
    std::size_t _quadrant_x = 9;
    std::size_t _quadrant_y = 9;

  public:
    // Constructor
    MovingEntity() = default;

    MovingEntity(float size_x, float size_y, float pos_x, float pos_y, float acceleration, float max_velocity) : 
                                                                      GameEntity(size_x, size_y, pos_x, pos_y),
                                                                      _max_velocity(max_velocity),
                                                                      _acceleration(acceleration) {}

    // Copy
    MovingEntity(const myClass& moving_entity) : GameEntity(moving_entity),
                                                 _directions(moving_entity._directions),
                                                 _max_velocity(moving_entity._max_velocity),
                                                 _acceleration(moving_entity._acceleration),
                                                 _velocity(moving_entity._velocity) {
      _position = moving_entity._position;
      _size = moving_entity._size;
      _directions = moving_entity._directions;
      _velocity = moving_entity._velocity;
    }
    myClass& operator=(const myClass&) = delete;

    // Move
    MovingEntity(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void horizontalMove(int, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>>);
    void verticalMove(int, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>>);
    void oblicMove(int, int, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>>);
    void move(Directions, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>>);

    // Setters

    // Getters
    
    // Destructor
    ~MovingEntity() = default;

};
#endif