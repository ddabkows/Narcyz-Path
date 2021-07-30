/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Weapon methods
*/


#include "Weapon.hpp"


// Methods
void Weapon::attackDisplayed() {_attack_to_display = false;}

// Getters
const AttackToDisplay& Weapon::getAttackDisplay() const {return _attack_display;}
const bool& Weapon::getAttackToDisplay() const {return _attack_to_display;}

// Setters
void Weapon::setDirection(Directions new_direction) {_attack_display.attack_direction = new_direction;}
void Weapon::setPosition(Dimensions player_position) {_attack_display.pos = player_position;}