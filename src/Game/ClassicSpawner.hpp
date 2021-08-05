/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of ClassicSpawner
*/


#include <vector>
#include <memory>
#include <random>


#include "Spawner.hpp"
#include "GameEntity.hpp"
#include "ClassicMob.hpp"
#include "GameMacros.hpp"
#include "AttackToDisplay.hpp"


#ifndef _CLASSIC_SPAWNER_HPP
#define _CLASSIC_SPAWNER_HPP


class ClassicSpawner : public Spawner {
  private:
    using myClass = ClassicSpawner;

  public:
    // Constructor
    ClassicSpawner(std::size_t quadrant_x, std::size_t quadrant_y) : Spawner(quadrant_x, quadrant_y, _classic_mob_max_count, _classic_mob_spawn_speed) {}

    // Copy
    ClassicSpawner(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    ClassicSpawner(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void spawnMobs(float, std::vector<std::shared_ptr<GameEntity>>) override;
};
#endif