/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game 
*/


#include "GameEntity.hpp"
#include "GameBoard.hpp"
#include "MovingEntity.hpp"
#include "GameMacros.hpp"

#include <vector>
#include <memory>


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

  // Setters

  // Getters

  // Destructor
  ~Game() = default;

};
#endif