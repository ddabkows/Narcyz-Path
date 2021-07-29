/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game macros
*/


#include <cmath>


#ifndef _GAME_MACROS_HPP
#define _GAME_MACROS_HPP


const float _game_board_size_x = 16000.f;
const float _game_board_size_y = 9000.f;
const float _board_divider = 10.f;
const float _projection_size_x = _game_board_size_x / _board_divider;
const float _projection_size_y = _game_board_size_y / _board_divider;
const float _player_size_x = 15.f;
const float _player_size_y = 30.f;
const float _player_acceleration = 0.1f;
const float _player_max_velocity = 4.f;
const float _player_movement_mult = -1.f;
const float _player_movement_trans = 21.f;
const float _pi_fourth = static_cast<float>(sqrt(2))/2.f;
const std::size_t _despawn_dist = 3;
const std::size_t _spawn_dist = 1;
const int _player_starting_max_hp = 100;
#endif