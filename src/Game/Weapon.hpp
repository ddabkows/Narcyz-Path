/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Weapon
*/


#include "Directions.hpp"
#include "AttackToDisplay.hpp"
#include "WeaponTypes.hpp"
#include "GameEntity.hpp"
#include "MovingEntity.hpp"


#ifndef _WEAPON_HPP
#define _WEAPON_HPP


class Weapon {
  private:
    // Trait
    using myClass = Weapon;

  protected:
    int _damage;
    float _cooldown;
    AttackToDisplay _attack_display;
    WeaponTypes _weapon_type;
    float _last_hit = 0.f;
    bool _attack_to_display = false;
    

  public:
    // Constructor
    Weapon() = default;

    Weapon(int damage, float cooldown, AttackToDisplay attack_display, WeaponTypes weapon_type) : _damage(damage),
                                                                                                  _cooldown(cooldown),
                                                                                                  _attack_display(attack_display),
                                                                                                  _weapon_type(weapon_type) {}

    // Copy
    Weapon(const myClass&) = default;
    myClass& operator=(const myClass&) = delete;

    // Move
    Weapon(myClass&&) = default;
    myClass& operator=(myClass&&) = delete;

    // Methods
    virtual void attack(std::vector<std::shared_ptr<MovingEntity>>, float) = 0;
    void attackDisplayed();

    // Getters
    const AttackToDisplay& getAttackDisplay() const;
    const bool& getAttackToDisplay() const;

    // Setters
    void setDirection(Directions);
    void setPosition(Dimensions);

    // Destructor
    virtual ~Weapon() = default;
};
#endif
