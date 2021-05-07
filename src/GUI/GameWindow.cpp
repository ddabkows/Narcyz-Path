/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameWindow methods
*/


#include "GameWindow.hpp"


void GameWindow::updateWindow() {
  _master.clearWindow();
  _master.drawRectangle(_player.getRectangle());
  _master.displayWindow();
}

void GameWindow::processEvent(sf::Event event) {
  switch (event.type) {
    case sf::Event::Closed : {
      _master.closeWindow();
      _open_window = false;
      break;
    }
    case sf::Event::KeyPressed : {
      std::cout << event.key.code << std::endl;
      break;
    }
    case sf::Event::KeyReleased : {
      std::cout << event.key.code << std::endl;
      break;
    }
    default : {
      break;
    }
  }
  setPlayerDirection();
  _game.updatePlayer(_player_direction);

}


void GameWindow::setPlayerDirection() {
  if (_top_clicked && _rgt_clicked) {
    _player_direction = north_east;
  }
  else if (_rgt_clicked && _bot_clicked) {
    _player_direction = south_east;
  }
  else if (_bot_clicked && _lft_clicked) {
    _player_direction = south_west;
  }
  else if (_lft_clicked && _top_clicked) {
    _player_direction = north_west;
  }
  else if (_top_clicked) {
    _player_direction = north;
  }
  else if (_rgt_clicked) {
    _player_direction = east;
  }
  else if (_bot_clicked) {
    _player_direction = south;
  }
  else if (_lft_clicked) {
    _player_direction = west;
  }
}

void GameWindow::setPlayerPosition() {
  Dimensions new_dimensions = _game.getPlayerDimensions();
  _player.setPosition(new_dimensions.x, new_dimensions.y);
}

bool GameWindow::pollEvent(sf::Event& event) {
  return _master.pollEvent(event);
}


// Getters
const Directions& GameWindow::getPlayerDirections() const {return _player_direction;}
const bool& GameWindow::getOpen() const {return _open_window;}
Master& GameWindow::getMaster() {return _master;}