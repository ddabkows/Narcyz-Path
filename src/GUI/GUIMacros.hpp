/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GUI macros
*/


#include <string>


#ifndef _GUI_MACROS_HPP
#define _GUI_MACROS_HPP

const std::string _font_1_path           = "../fonts/MiddAges.ttf";
const std::string _magic_ball_path       = "../img/sprites/player/attack_1.png";
const std::string _mob_attack_1_path     = "../img/sprites/mob_attacks/1.png";
const std::string _player_path           = "../img/sprites/player/player.png";
const float _hp_display_prop             = 3.f;
const float _hp_display_height           = 3.f;
const std::string _spawn_text            = "Hello! If you are reading this, you are\nnot the kind of people who read the\nREADME files, huh? Or are you the kind\nof people who do not like anyone to tell\nthem what to do? Well, whatever it is\nit's not important right now\n(but read the README bro, it's funny)\n\nControls:\nMove-WSAD/ZQSD\nAttacks-arrow keys\nExit-escape";
const std::string _swap_keys_text        = "WSAD/ZQSD";
const std::string _new_game_text         = "PLAY";
const std::string _exit_game_text        = "EXIT GAME";
const unsigned int _magic_ball_texture_x = 9;
const unsigned int _magic_ball_texture_y = 1;
const unsigned int _mob_attack_1_x       = 9;
const unsigned int _mob_attack_1_y       = 1;
const float _player_display_time         = 3.f;
const unsigned int _player_texture_x     = 9;
const unsigned int _player_texture_y     = 9;
const float _player_rotation             = 3.f;
const float _new_game_x                    = 755.f;
const float _new_game_y                    = 300.f;
const float _exit_game_x                   = 704.f;
const float _exit_game_y                   = 350.f;
#endif