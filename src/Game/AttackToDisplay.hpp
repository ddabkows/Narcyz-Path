/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Struct of Dimensions
*/


#include "Dimensions.hpp"


#ifndef _ATTACK_TO_DISPLAY_HPP
#define _ATTACK_TO_DISPLAY_HPP


struct AttackToDisplay {
  AttackToDisplay() = default;
  AttackToDisplay(float size_x, float size_y, float display_time) : size(size_x, size_y),
                                                                    pos(0.f, 0.f),
                                                                    hit_display_time(display_time) {}
  Dimensions size;
  Dimensions pos;
  float hit_display_time;
  float display_moment = 0.f;
};
#endif