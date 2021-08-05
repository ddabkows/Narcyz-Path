/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Game Master methods
*/


#include "GameMaster.hpp"


// Methods
void GameMaster::setupMaster() {
  _magic_ball_texture = std::make_shared<sf::Texture>();
  _magic_ball_texture->loadFromFile(_magic_ball_path);
  _magic_ball_texture->setSmooth(true);

  _classic_mob_attack = std::make_shared<sf::Texture>();
  _classic_mob_attack->loadFromFile(_mob_attack_1_path);
  _classic_mob_attack->setSmooth(true);

  _player_texture = std::make_shared<sf::Texture>();
  _player_texture->loadFromFile(_player_path);
  _player_texture->setSmooth(true);
}

std::shared_ptr<sf::Texture> GameMaster::getMobAttackTexture(Skin skin) {
  switch (skin) {
    case no_skin : {
      return nullptr;
    }
    case classic_mob_attack : {
      return _classic_mob_attack;
    }
    default : {
      return nullptr;
    }
  }
}

// Getters
std::shared_ptr<sf::Texture> GameMaster::getMagicBallTexture() {return _magic_ball_texture;}
std::shared_ptr<sf::Texture> GameMaster::getPlayerTexture() {return _player_texture;}