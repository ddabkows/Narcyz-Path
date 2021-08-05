/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Spawner
*/


#include <vector>
#include <memory>
#include <random>

#include "Mob.hpp"
#include "ClassicMob.hpp"
#include "GameEntity.hpp"
#include "GameMacros.hpp"
#include "AttackToDisplay.hpp"


#ifndef _SPAWNER_HPP
#define _SPAWNER_HPP


class Spawner {
  private:
    // Trait
    using myClass = Spawner;

  protected:
    std::size_t _quadrant_x;
    std::size_t _quadrant_y;

    std::size_t _max_mobs{};
    std::vector<std::shared_ptr<Mob>> _mobs = {};

    float _spawn_speed{};
    float _last_spawn = 0.f;

  public:
    // Constructor
    Spawner() = default;

    Spawner(std::size_t quadrant_x, std::size_t quadrant_y, std::size_t max_mobs, float spawn_speed) : _quadrant_x(quadrant_x),
                                                                                                       _quadrant_y(quadrant_y),
                                                                                                       _max_mobs(max_mobs),
                                                                                                       _spawn_speed(spawn_speed) {}

    // Copy
    Spawner(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    Spawner(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    virtual void spawnMobs(float, std::vector<std::shared_ptr<GameEntity>>) = 0;
    void despawnMobs();
    void killMobs();

    // Setters
    void setMobs(std::vector<std::shared_ptr<Mob>>);

    // Getters
    const std::size_t& getQuadrantX() const;
    const std::size_t& getQuadrantY() const;
    std::vector<std::shared_ptr<Mob>> getMobs();

    // Destructor
    virtual ~Spawner() = default;
};
#endif