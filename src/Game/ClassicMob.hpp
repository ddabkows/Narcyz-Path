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
    ClassicMob(float size_x, float size_y, float pos_x, float pos_y, float max_velocity, std::size_t quadrant_x, std::size_t quadrant_y, const int max_hp,
               float hit_charge, float hit_cooldown, int hit_strength, AttackToDisplay attack_display, Skin skin, Skin attack_skin) : Mob(size_x, size_y, pos_x, pos_y,
                                                                                                                                          max_velocity, quadrant_x, quadrant_y,
                                                                                                                                          max_hp, hit_charge, hit_cooldown, hit_strength,
                                                                                                                                          attack_display, skin, attack_skin) {}
    // Copy
    ClassicMob(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    ClassicMob(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void attack(std::shared_ptr<Player>, float) override;

    // Destructor
    ~ClassicMob() = default;
};
#endif