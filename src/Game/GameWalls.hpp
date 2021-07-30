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
    { // [0][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 0.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 890.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 500.f),
    },
    { // [0][1]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 1400.f),
    },
    { // [0][2]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 2300.f),
    },
    { // [0][3]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 3200.f),
    },
    { // [0][4]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 4100.f),
    },
    { // [0][5]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 5000.f),
    },
    { // [0][6]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 5900.f),
    },
    { // [0][7]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 6800.f),
    },
    { // [0][8]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 7700.f),
      std::make_shared<GameEntity>(800.f, 450.f, 400.f, 7425.f),    // Center wall
    },
    { // [0][9]
      std::make_shared<GameEntity>(750.f, 10.f, 0.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 850.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 0.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 900.f, 0.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 1590.f, 8600.f),
    }
  },
  {
    { // [1][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 1600.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 500.f),
    },
    { // [1][1]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 1400.f),
    },
    { // [1][2]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 2300.f),
    },
    { // [1][3]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 3200.f),
    },
    { // [1][4]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 4100.f),
    },
    { // [1][5]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 5000.f),
    },
    { // [1][6]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 5900.f),
    },
    { // [1][7]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 6800.f),
    },
    { // [1][8]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 7700.f),
    },
    { // [1][9]
      std::make_shared<GameEntity>(750.f, 10.f, 1600.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 2450.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 1600.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 1600.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 3190.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 2375.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [2][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 3200.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 500.f),
    },
    { // [2][1]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 1400.f),
    },
    { // [2][2]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 2300.f),
    },
    { // [2][3]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 3200.f),
    },
    { // [2][4]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 4100.f),
    },
    { // [2][5]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 5000.f),
    },
    { // [2][6]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 5900.f),
    },
    { // [2][7]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 6800.f),
    },
    { // [2][8]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 7700.f),
    },
    { // [2][9]
      std::make_shared<GameEntity>(750.f, 10.f, 3200.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4050.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 3200.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 3200.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 4790.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [3][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 4800.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 500.f),
    },
    { // [3][1]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 1400.f),
    },
    { // [3][2]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 2300.f),
    },
    { // [3][3]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 3200.f),
    },
    { // [3][4]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 4100.f),
    },
    { // [3][5]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 5000.f),
    },
    { // [3][6]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 5900.f),
    },
    { // [3][7]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 6800.f),
    },
    { // [3][8]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 7700.f),
    },
    { // [3][9]
      std::make_shared<GameEntity>(750.f, 10.f, 4800.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 5650.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 4800.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 4800.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 6390.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [4][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 6400.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 500.f),
    },
    { // [4][1]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 1400.f),
    },
    { // [4][2]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 2300.f),
    },
    { // [4][3]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 3200.f),
    },
    { // [4][4]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 4100.f),
    },
    { // [4][5]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 5000.f),
    },
    { // [4][6]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 5400.f),       // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 5900.f)
    },
    { // [4][7]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 6800.f),
    },
    { // [4][8]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 7700.f),
    },
    { // [4][9]
      std::make_shared<GameEntity>(750.f, 10.f, 6400.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 7250.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 6400.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 6400.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 7990.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [5][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 8000.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 500.f),
    },
    { // [5][1]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 1400.f),
    },
    { // [5][2]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 2300.f),
    },
    { // [5][3]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 3200.f),
    },
    { // [5][4]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 4100.f),
    },
    { // [5][5]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 5000.f),
    },
    { // [5][6]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 5900.f),
    },
    { // [5][7]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 6800.f),
    },
    { // [5][8]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 7700.f),
    },
    { // [5][9]
      std::make_shared<GameEntity>(750.f, 10.f, 8000.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 8850.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 8000.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 8000.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 9590.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [6][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 9600.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 500.f),
    },
    { // [6][1]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 1400.f),
    },
    { // [6][2]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 2300.f),
    },
    { // [6][3]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 3200.f),
    },
    { // [6][4]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 4100.f),
    },
    { // [6][5]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 5000.f),
    },
    { // [6][6]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 5900.f),
    },
    { // [6][7]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 6800.f),
    },
    { // [6][8]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 7700.f),
    },
    { // [6][9]
      std::make_shared<GameEntity>(750.f, 10.f, 9600.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 10450.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 9600.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 9600.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 11190.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [7][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 11200.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 500.f),
    },
    { // [7][1]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 1400.f),
    },
    { // [7][2]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 2300.f),
    },
    { // [7][3]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 3200.f),
    },
    { // [7][4]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 4100.f),
    },
    { // [7][5]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 5000.f),
    },
    { // [7][6]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 5900.f),
    },
    { // [7][7]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 6800.f),
    },
    { // [7][8]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 7700.f),
    },
    { // [7][9]
      std::make_shared<GameEntity>(750.f, 10.f, 11200.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12050.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 11200.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 11200.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 12790.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [8][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 12800.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 500.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 0.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 500.f),
    },
    { // [8][1]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 900.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 1400.f),
    },
    { // [8][2]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 1800.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 2300.f),
    },
    { // [8][3]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 2700.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 3200.f),
    },
    { // [8][4]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 3600.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 4100.f),
    },
    { // [8][5]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 4500.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 5000.f),
    },
    { // [8][6]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 5400.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 5900.f),
    },
    { // [8][7]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 6300.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 6800.f),
    },
    { // [8][8]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 7200.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 7700.f),
    },
    { // [8][9]
      std::make_shared<GameEntity>(750.f, 10.f, 12800.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 13650.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 12800.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 12800.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(10.f, 400.f, 14390.f, 8600.f),
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  },
  {
    { // [9][0]
      std::make_shared<GameEntity>(1600.f, 10.f, 14400.f, 0.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 890.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 890.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 0.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 500.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 0.f),    // Right walls
    },
    { // [9][1]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 900.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 900.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 1790.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 1790.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 900.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 1400.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 900.f),    // Right walls
    },
    { // [9][2]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 1800.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 1800.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 2690.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 2690.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 1800.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 2300.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 1800.f),    // Right walls
    },
    { // [9][3]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 2700.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 2700.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 3590.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 3590.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 2700.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 3200.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 2700.f),    // Right walls
    },
    { // [9][4]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 3600.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 3600.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 4490.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 4490.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 3600.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 4100.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 3600.f),    // Right walls
    },
    { // [9][5]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 4500.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 4500.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 5390.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 5390.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 4500.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 5000.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 4500.f),    // Right walls
    },
    { // [9][6]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 5400.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 5400.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 6290.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 6290.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 5400.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 5900.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 5400.f),    // Right walls
    },
    { // [9][7]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 6300.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 6300.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 7190.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 7190.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 6300.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 6800.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 6300.f),    // Right walls
    },
    { // [9][8]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 7200.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 7200.f),
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 8090.f),      // Bottom walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 8090.f),
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 7200.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 7700.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 7200.f),    // Right walls
    },
    { // [9][9]
      std::make_shared<GameEntity>(750.f, 10.f, 14400.f, 8100.f),      // Top walls
      std::make_shared<GameEntity>(750.f, 10.f, 15250.f, 8100.f),
      std::make_shared<GameEntity>(1600.f, 10.f, 14400.f, 8990.f),      // Bottom wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 8100.f),       // Left wall
      std::make_shared<GameEntity>(10.f, 400.f, 14400.f, 8600.f),
      std::make_shared<GameEntity>(10.f, 900.f, 15990.f, 8100.f),    // Right walls
      std::make_shared<GameEntity>(50.f, 50.f, 775.f, 8525.f),      // Middle square  
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8300.f),     // Top latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8300.f),
      std::make_shared<GameEntity>(400.f, 10.f, 300.f, 8790.f),     // Bottom latteral walls 
      std::make_shared<GameEntity>(400.f, 10.f, 900.f, 8790.f)
    }
  }
};
#endif