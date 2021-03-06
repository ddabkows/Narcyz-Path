/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game 
*/


#include <vector>
#include <memory>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "GameEntity.hpp"
#include "ClassicSpawner.hpp"
#include "GameBoard.hpp"
#include "MovingEntity.hpp"
#include "Player.hpp"
#include "Mob.hpp"
#include "Spawner.hpp"
#include "GameMacros.hpp"
#include "GameWalls.hpp"
#include "AttackToDisplay.hpp"


#ifndef _GAME_HPP
#define _GAME_HPP


class Game {
  private:
    // Trait
    using myClass = Game;

    std::shared_ptr<GameBoard> _game_board;
    std::shared_ptr<Player> _player;
    std::vector<std::shared_ptr<MovingEntity>> _enemies{};
    const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>> _walls = walls;

    float _player_walk_timer = 0.f;
    sf::Clock _game_timer{};
    bool _is_over = false;
    std::vector<std::shared_ptr<Spawner>> _mob_spawners = {std::make_shared<ClassicSpawner>(_classic_mob_spawn_1_x, _classic_mob_spawn_1_y)};

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
  void updateGame(Directions, Directions);
  void checkSpawners();
  std::size_t checkDist(std::size_t, std::size_t);
  void endGame();
  void playerAttackDisplayed();

  // Setters

  // Getters
  const Dimensions& getPlayerDimensions() const;
  const std::vector<std::shared_ptr<GameEntity>>& getWalls(std::size_t, std::size_t) const;
  const std::size_t& getPlayerQuadrantX() const;
  const std::size_t& getPlayerQuadrantY() const;
  const Dimensions& getPlayerSize() const;
  const bool& getPlayerAttackToBeDisplayed() const;
  const AttackToDisplay& getPlayerAttackDisplay() const;
  const std::vector<std::shared_ptr<Spawner>>& getSpawners() const;
  float getPlayerHealth() const;
  const bool& isOver() const;
  float getGameTimer() const;

  // Destructor
  ~Game() = default;

};
#endif