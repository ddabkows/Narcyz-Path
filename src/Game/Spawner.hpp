/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Spawner
*/


#include <vector>
#include <memory>
#include <random>

#include "Mob.hpp"
#include "GameEntity.hpp"
#include "GameMacros.hpp"


#ifndef _SPAWNER_HPP
#define _SPAWNER_HPP


class Spawner {
  private:
    // Trait
    using myClass = Spawner;

    std::size_t _quadrant_x;
    std::size_t _quadrant_y;

    Dimensions _mob_size;
    float _mob_velocity;
    std::size_t _max_mobs;
    std::vector<std::shared_ptr<Mob>> _mobs = {};

    float _spawn_speed;
    float _last_spawn = 0.f;

  public:
    // Constructor
    Spawner() = default;

    Spawner(std::size_t quadrant_x, std::size_t quadrant_y, float size_x, float size_y, float mob_velocity, std::size_t max_mobs, float spawn_speed) : 
                                                                                                                                  _quadrant_x(quadrant_x),
                                                                                                                                  _quadrant_y(quadrant_y),
                                                                                                                                  _mob_size(size_x, size_y),
                                                                                                                                  _mob_velocity(mob_velocity),
                                                                                                                                  _max_mobs(max_mobs),
                                                                                                                                  _spawn_speed(spawn_speed) {}

    // Copy
    Spawner(const myClass&) = delete;
    myClass& operator=(const myClass&) = delete;

    // Move
    Spawner(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void spawn_mobs(float);
    void despawn_mobs();
};
#endif