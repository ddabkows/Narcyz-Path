/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Class of Game Master
*/


#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUIMacros.hpp"
#include "Skin.hpp"


#ifndef _GAME_MASTER_HPP
#define _GAME_MASTER_HPP


class GameMaster {
  private:
    // Trait
    using myClass = GameMaster;

    std::shared_ptr<sf::Font> _font_1;
    std::shared_ptr<sf::Texture> _magic_ball_texture;
    std::shared_ptr<sf::Texture> _classic_mob_attack;
    std::shared_ptr<sf::Texture> _player_texture;

  public:
    // Constructor
    GameMaster() : _font_1(),
                   _magic_ball_texture(),
                   _classic_mob_attack(),
                   _player_texture() {setupMaster();}

    // Copy
    GameMaster(const myClass&) = delete;
    myClass& operator=(const myClass&) = default;

    // Move
    GameMaster(myClass&&) = delete;
    myClass& operator=(myClass&&) = delete;

    // Methods
    void setupMaster();
    std::shared_ptr<sf::Texture> getMobAttackTexture(Skin);

    // Getters
    std::shared_ptr<sf::Font>& getFont1();
    std::shared_ptr<sf::Texture> getMagicBallTexture();
    std::shared_ptr<sf::Texture> getPlayerTexture();

    // Destructor
    ~GameMaster() = default;
};
#endif