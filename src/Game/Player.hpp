/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Player
*/


#include <vector>
#include <memory>
#include <iostream>

#include "GameEntity.hpp"
#include "MovingEntity.hpp"
#include "GameMacros.hpp"


#ifndef _PLAYER_HPP
#define _PLAYER_HPP


class Player : public MovingEntity {
  private:
    // Trait
    using myClass = Player;

    Directions _directions{};
    float _velocity = 0.f;
    float _acceleration;

    std::size_t _quadrant_x;
    std::size_t _quadrant_y;

  public:
    // Constructor
    Player() = default;

    Player(float size_x, float size_y, float pos_x, float pos_y, float acceleration, float max_velocity) :
                                                                                    MovingEntity(size_x, size_y, pos_x, pos_y, max_velocity),
                                                                                    _acceleration(acceleration),
                                                                                    _quadrant_x(static_cast<std::size_t>(_position.x / _projection_size_x)),
                                                                                    _quadrant_y(static_cast<std::size_t>(_position.y / _projection_size_y)) {}
    
    // Copy
    Player(const myClass& player) : MovingEntity(player),
                                    _directions(player._directions),
                                    _velocity(player._velocity),
                                    _acceleration(player._acceleration),
                                    _quadrant_x(player._quadrant_x),
                                    _quadrant_y(player._quadrant_y) {
      _position = player._position;
      _size = player._size;
      _directions = player._directions;
    }
    
    myClass& operator=(const myClass&) = delete;

    // Move
    Player(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void horizontalMove(int, const std::vector<std::shared_ptr<GameEntity>>);
    void verticalMove(int, const std::vector<std::shared_ptr<GameEntity>>);
    void oblicMove(int, int, const std::vector<std::shared_ptr<GameEntity>>);
    void move(Directions, const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>>);

    // Setters

    // Getters
    const std::size_t& getQuadrantX() const;
    const std::size_t& getQuadrantY() const;


};
#endif