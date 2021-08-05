/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Classic Mob
*/


#include "Mob.hpp"


#ifndef _CLASSIC_MOB_HPP
#define _CLASSIC_MOB_HPP


class ClassicMob : public Mob {
  private:
    // Trait
    using myClass = ClassicMob;

  public:
    // Constructor
    ClassicMob(float pos_x, float pos_y) : Mob(_player_size_x, _player_size_y, pos_x, pos_y, _classic_mob_velocity, _classic_mob_spawn_1_x, _classic_mob_spawn_1_y,
               _classic_mob_max_hp, _classic_mob_hit_charge, _classic_mob_hit_cooldown, _classic_mob_attack_strength, 
               AttackToDisplay(_classic_mob_attack_size_x, _classic_mob_attack_size_y, _classic_mob_hit_display_time, Skin(classic_mob_attack)),
               no_skin, classic_mob_attack, _classic_mob_states_nbr) {}
    // Copy
    ClassicMob(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    ClassicMob(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void move(std::shared_ptr<Player>, std::vector<std::shared_ptr<Mob>>, const std::vector<std::shared_ptr<GameEntity>>, float) override;
    void attack(std::shared_ptr<Player>, float) override;
    float checkDistance(std::shared_ptr<Player>, float, float);
    unsigned int getState() override;

    // Destructor
    ~ClassicMob() = default;
};
#endif