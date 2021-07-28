/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Mob
*/


#include <vector>
#include <memory>

#include "MovingEntity.hpp"
#include "GameMacros.hpp"


#ifndef _MOB_HPP
#define _MOB_HPP


class Mob : public MovingEntity {
  private:
    // Trait
    using myClass = Mob;

  public:
    // Constructor
    Mob() = default;

    Mob(float size_x, float size_y, float pos_x, float pos_y, float max_velocity, std::size_t quadrant_x, std::size_t quadrant_y) : 
                                                                                  MovingEntity(size_x, size_y, pos_x, pos_y, max_velocity, quadrant_x, quadrant_y) {}

    // Copy
    Mob(const myClass& mob) : MovingEntity(mob) {
      _position = mob._position;
      _size = mob._size;
    }

    myClass& operator=(const myClass&) = delete;

    // Move
    Mob(myClass&& mob) : MovingEntity(mob) {
      _position = mob._position;
      _size = mob._size;
    }
    myClass& operator=(myClass&&) = delete;

    // Methods
    void move(std::shared_ptr<GameEntity>, std::vector<std::shared_ptr<Mob>>, const std::vector<std::shared_ptr<GameEntity>>);
    float checkDistanceToPlayer(std::shared_ptr<GameEntity>, float, float);
};
#endif