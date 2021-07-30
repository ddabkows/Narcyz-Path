/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Player
*/


#include <vector>
#include <memory>
#include <iostream>

#include "MovingEntity.hpp"
#include "GameMacros.hpp"
#include "Weapon.hpp"
#include "ClassicWeapon.hpp"


#ifndef _PLAYER_HPP
#define _PLAYER_HPP


class Player : public MovingEntity {
  private:
    // Trait
    using myClass = Player;

    Directions _directions{};
    float _velocity = 0.f;
    float _acceleration;
    std::shared_ptr<Weapon> _weapon;

  public:
    // Constructor
    Player() = default;

    Player(float size_x, float size_y, float pos_x, float pos_y, float acceleration, float max_velocity, const int max_hp) :
                                                                                    MovingEntity(size_x, size_y, pos_x, pos_y, max_velocity,
                                                                                    std::size_t(0),
                                                                                    std::size_t(9), max_hp),
                                                                                    _acceleration(acceleration),
                                                                                    _weapon(std::make_shared<ClassicWeapon>(_classic_weapon_damage,
                                                                                                                            _classic_weapon_cooldown,
                                                                                                                            AttackToDisplay(_classic_weapon_attack_size_x,
                                                                                                                                            _classic_weapon_attack_size_y,
                                                                                                                                            _classic_weapon_display_time),
                                                                                                                            WeaponTypes(classic))) {}
    
    // Copy
    Player(const myClass& player) : MovingEntity(player),
                                    _directions(player._directions),
                                    _velocity(player._velocity),
                                    _acceleration(player._acceleration),
                                    _weapon(player._weapon) {
      _position = player._position;
      _size = player._size;
      _directions = player._directions;
    }
    
    myClass& operator=(const myClass&) = delete;

    // Move
    Player(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void horizontalMove(int, std::vector<std::shared_ptr<GameEntity>>, const std::vector<std::shared_ptr<GameEntity>>);
    bool checkHorizontal(int, std::vector<std::shared_ptr<GameEntity>>);
    void verticalMove(int, std::vector<std::shared_ptr<GameEntity>>, const std::vector<std::shared_ptr<GameEntity>>);
    bool checkVertical(int, std::vector<std::shared_ptr<GameEntity>>);
    void oblicMove(int, int, std::vector<std::shared_ptr<GameEntity>>, const std::vector<std::shared_ptr<GameEntity>>);
    void move(Directions, std::vector<std::shared_ptr<MovingEntity>>, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>>);
    void attack(std::vector<std::shared_ptr<MovingEntity>>, float);
    void attackDisplayed();

    // Setters
    void setAttackDirection(Directions);
    void setAttackPosition();

    // Getters
    const std::size_t& getQuadrantX() const;
    const std::size_t& getQuadrantY() const;
    const bool& getAttackToBeDisplayed() const;
    const AttackToDisplay& getAttackToDisplay() const;

    // Destructor
    ~Player() = default;
};
#endif