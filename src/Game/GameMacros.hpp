/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game macros
*/


#include <cmath>


#ifndef _GAME_MACROS_HPP
#define _GAME_MACROS_HPP


const float _game_board_size_x             = 16000.f;
const float _game_board_size_y             = 9000.f;
const float _board_divider                 = 10.f;
const float _projection_size_x             = _game_board_size_x / _board_divider;
const float _projection_size_y             = _game_board_size_y / _board_divider;
const float _player_size_x                 = 15.f;
const float _player_size_y                 = 30.f;
const float _player_acceleration           = 0.1f;
const float _player_max_velocity           = 4.f;
const float _player_movement_mult          = -1.f;
const float _player_movement_trans         = 21.f;
const float _pi_fourth                     = static_cast<float>(sqrt(2))/2.f;
const std::size_t _despawn_dist            = 3;
const std::size_t _spawn_dist              = 1;
const int _player_starting_max_hp          = 100;
const float _classic_mob_velocity          = 8.f;
const std::size_t _classic_mob_max_count   = 15;
const float _classic_mob_spawn_speed       = 3.f;
const float _classic_mob_max_hp            = 3.f;
const std::size_t _classic_mob_spawn_1_x   = 0;
const std::size_t _classic_mob_spawn_1_y   = 8;
const float _classic_mob_hit_charge        = 0.5f;
const float _classic_mob_hit_cooldown      = 2.f;
const float _classic_mob_hit_display_time  = 0.2f;
const float _classic_mob_attack_radius     = 90.f;
const float _classic_mob_attack_size_x     = 6.f * _player_size_x;
const float _classic_mob_attack_size_y     = 3.f * _player_size_y;
const int _classic_mob_attack_strength     = 10;
const double _game_tick                    = 0.1;
const int _circle_div_iterator             = 4;
const int _circle_div_max                  = 8;
const int _direction_change                = 2;
const int _classic_weapon_damage           = 1;
const float _classic_weapon_cooldown       = 1.f;
const float _classic_weapon_attack_size_x  = 3.f * _player_size_y;
const float _classic_weapon_attack_size_y  = _player_size_y;
const float _classic_weapon_display_time   = 0.25f;
#endif