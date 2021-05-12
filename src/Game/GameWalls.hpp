/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game walls
*/


#include <memory>
#include <vector>

#include "GameEntity.hpp"
#include "GameMacros.hpp"


#ifndef _GAME_WALLS_HPP
#define _GAME_WALLS_HPP


const std::vector<std::vector<std::vector<std::shared_ptr<GameEntity>>>> walls = {
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    { // [0][9]
      std::make_shared<GameEntity>(1600.f, 10.f, 0.f, 8100.f),      // Top wall
      std::make_shared<GameEntity>(1600.f, 10.f, 0.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 880.f, 0.f, 8110.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 880.f, 1590.f, 8110.f)     // Right wall}
    }
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
    },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  },
  {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {}
  }
};
#endif