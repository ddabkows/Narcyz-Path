/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Master methods
*/


#include "Master.hpp"


//Methods
void Master::setupWindow() {
  _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(static_cast<int>(_projection_size_x), static_cast<int>(_projection_size_y)),
                                                             "Narcyz Path");
  _window->setSize(sf::Vector2u(800, 450));
  _window->setFramerateLimit(120);

  _font_1 = std::make_shared<sf::Font>();
  _font_1->loadFromFile(_font_1_path);

  _magic_ball_texture = std::make_shared<sf::Texture>();
  _magic_ball_texture->loadFromFile(_magic_ball_path);
  _magic_ball_texture->setSmooth(true);

  _classic_mob_attack = std::make_shared<sf::Texture>();
  _classic_mob_attack->loadFromFile(_mob_attack_1_path);
  _classic_mob_attack->setSmooth(true);
}

void Master::clearWindow() {
  _window->clear();
}

void Master::displayWindow() {
  _window->display();
}

void Master::closeWindow() {
  _window->close();
}

bool Master::pollEvent(sf::Event& event) {
  return _window->pollEvent(event);
}

void Master::drawRectangle(const sf::RectangleShape& rectangle) {
  _window->draw(rectangle);
}

void Master::drawText(const sf::Text& text) {
  _window->draw(text);
}

std::shared_ptr<sf::Texture> Master::getMobAttackTexture(Skin skin) {
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

// Setters

// Getters
std::shared_ptr<sf::RenderWindow>& Master::getWindow() {return _window;}
std::shared_ptr<sf::Font>& Master::getFont1() {return _font_1;}
std::shared_ptr<sf::Texture> Master::getMagicBallTexture() {return _magic_ball_texture;}
bool Master::getOpen() {return _window->isOpen();}
