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
    {
      std::make_shared<GameEntity>(900.f, 10.f, 0.f, 8490.f)
    },
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