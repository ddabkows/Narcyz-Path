/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Moving Entity 
*/


#include <vector>
#include <memory>

#include "GameEntity.hpp"


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
    void horizontalMove();
    void verticalMove(std::vector<std::shared_ptr<GameEntity>>, Dimensions);
    void oblicMove(float, float);
    void move(std::vector<std::shared_ptr<GameEntity>>, Dimensions);
    bool checkNorthConflicts(std::vector<std::shared_ptr<GameEntity>>);
    void checkNewDirectionsConsequences(Directions, std::vector<std::shared_ptr<GameEntity>>, Dimensions);
    void updateVelocity(Directions, std::vector<std::shared_ptr<GameEntity>>, Dimensions);

    // Setters

    // Getters
    
    // Destructor
    ~MovingEntity() = default;

};
#endif