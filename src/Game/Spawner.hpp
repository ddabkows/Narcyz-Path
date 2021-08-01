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
#include "AttackToDisplay.hpp"


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
    int _max_hp;
    float _hit_charge;
    float _hit_cooldown;
    int _hit_strength;
    AttackToDisplay _attack_display;
    Skin _skin;
    Skin _attack_skin;

  public:
    // Constructor
    Spawner() = default;

    Spawner(std::size_t quadrant_x, std::size_t quadrant_y, float size_x, float size_y, float mob_velocity, std::size_t max_mobs, float spawn_speed, 
            const int max_hp, const float hit_charge, const float hit_cooldown, const int hit_strength, AttackToDisplay attack_display,
            Skin skin, Skin _attack_skin) : _quadrant_x(quadrant_x),
                                            _quadrant_y(quadrant_y),
                                            _mob_size(size_x, size_y),
                                            _mob_velocity(mob_velocity),
                                            _max_mobs(max_mobs),
                                            _spawn_speed(spawn_speed),
                                            _max_hp(max_hp),
                                            _hit_charge(hit_charge),
                                            _hit_cooldown(hit_cooldown),
                                            _hit_strength(hit_strength),
                                            _attack_display(attack_display),
                                            _skin(skin),
                                            _attack_skin(skin) {}

    // Copy
    Spawner(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    Spawner(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void spawnMobs(float, std::vector<std::shared_ptr<GameEntity>>);
    void despawnMobs();
    void killMobs();

    // Setters
    void setMobs(std::vector<std::shared_ptr<Mob>>);

    // Getters
    const std::size_t& getQuadrantX() const;
    const std::size_t& getQuadrantY() const;
    std::vector<std::shared_ptr<Mob>> getMobs();
};
#endif