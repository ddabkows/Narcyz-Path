/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game 
*/


#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "GameEntity.hpp"
#include "GameBoard.hpp"
#include "MovingEntity.hpp"
#include "GameMacros.hpp"


#ifndef _GAME_HPP
#define _GAME_HPP


class Game {
  private:
    // Trait
    using myClass = Game;

    std::shared_ptr<GameBoard> _game_board;
    std::vector<std::shared_ptr<GameEntity>> _walls{};
    std::shared_ptr<MovingEntity> _player;
    std::vector<std::shared_ptr<MovingEntity>> _enemies{};

    float _player_walk_timer = 0.f;
    sf::Clock _game_timer{};

  public:
  // Constructor
  Game() : _game_board(),
           _player() {
    generateGame();
  }
    
  // Copy
  Game(const myClass& game) = delete;
  myClass& operator=(const myClass&) = delete;

  // Move
  Game(myClass&&) = delete;
  myClass& operator=(myClass&&) = delete;

  // Methods
  void generateGame();
  void updatePlayer(Directions);

  // Setters

  // Getters

  // Destructor
  ~Game() = default;

};
#endif