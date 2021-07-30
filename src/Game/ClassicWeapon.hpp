/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of classic Weapon
*/


#include "Weapon.hpp"


#ifndef _CLASSIC_WEAPON_HPP
#define _CLASSIC_WEAPON_HPP


class ClassicWeapon : public Weapon {
  private:
    // Trait
    using myClass = ClassicWeapon;

  public:
    // Constructor
    ClassicWeapon() = default;

    ClassicWeapon(int damage, float cooldown, AttackToDisplay attack_display, WeaponTypes weapon_type) : Weapon(damage, cooldown, attack_display, weapon_type) {}

    // Copy
    ClassicWeapon(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    ClassicWeapon(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void attack(std::vector<std::shared_ptr<MovingEntity>>, float) override;

    // Destructor
    ~ClassicWeapon() = default;
};
#endif