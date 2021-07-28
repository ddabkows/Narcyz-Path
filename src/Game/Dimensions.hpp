/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Struct of Dimensions
*/


#ifndef _DIMENSIONS_HPP
#define _DIMENSIONS_HPP


struct Dimensions {
  Dimensions() = default;
  Dimensions(float to_x, float to_y) : x(to_x), 
                                       y(to_y) {} 
  float x;
  float y;
};
#endif 