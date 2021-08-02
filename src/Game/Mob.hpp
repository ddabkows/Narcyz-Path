/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Mob
*/


#include <vector>
#include <memory>

#include "MovingEntity.hpp"
#include "Player.hpp"
#include "GameMacros.hpp"
#include "AttackToDisplay.hpp"


#ifndef _MOB_HPP
#define _MOB_HPP


class Mob : public MovingEntity {
  private:
    // Trait
    using myClass = Mob;

  protected:
    float _last_hit   = 0.f;
    float _hit_charge;
    float _hit_cooldown;
    int _hit_strength;
    bool _charge_attack = false;
    bool _display_attack = false;
    AttackToDisplay _attack_display;
    Skin _attack_skin;

  public:
    // Constructor
    Mob() = default;

    Mob(float size_x, float size_y, float pos_x, float pos_y, float max_velocity, std::size_t quadrant_x, std::size_t quadrant_y, const int max_hp,
      float hit_charge, float hit_cooldown, int hit_strength, AttackToDisplay attack_display, Skin skin, Skin attack_skin) : MovingEntity(size_x, size_y, pos_x, pos_y, max_velocity,
                                                                                                                    quadrant_x, quadrant_y, max_hp),
                                                                                                                    _hit_charge(hit_charge),
                                                                                                                    _hit_cooldown(hit_cooldown),
                                                                                                                    _hit_strength(hit_strength),
                                                                                                                    _attack_display(attack_display),
                                                                                                                    _attack_skin(attack_skin) {_skin = skin;}

    // Copy
    Mob(const myClass& mob) : MovingEntity(mob),
                              _hit_charge(mob._hit_charge),
                              _hit_cooldown(mob._hit_cooldown),
                              _hit_strength(mob._hit_strength),
                              _attack_display(mob._attack_display),
                              _attack_skin(mob._attack_skin) {
      _position = mob._position;
      _size = mob._size;
    }

    myClass& operator=(const myClass&) = delete;

    // Move
    Mob(myClass&& mob) : MovingEntity(mob),
                         _hit_charge(mob._hit_charge),
                         _hit_cooldown(mob._hit_cooldown),
                         _hit_strength(mob._hit_strength),
                         _attack_display(mob._attack_display),
                         _attack_skin(mob._attack_skin) {
      _position = mob._position;
      _size = mob._size;
    }
    myClass& operator=(myClass&&) = delete;

    // Methods
    void move(std::shared_ptr<Player>, std::vector<std::shared_ptr<Mob>>, const std::vector<std::shared_ptr<GameEntity>>, float);
    float checkDistanceToPlayer(std::shared_ptr<Player>, float, float);
    void chargeAttack(float);
    virtual void attack(std::shared_ptr<Player>, float) = 0;
    void attackDisplayed();

    // Getters
    const AttackToDisplay& getAttackDisplay() const;
    const bool& getAttackToDisplay() const;

    // Destructor
    virtual ~Mob() = default;

};
#endif