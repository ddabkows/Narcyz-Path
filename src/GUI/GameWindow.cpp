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
      //std::cout << static_cast<int>(event.key.code) << std::endl;
      switch (event.key.code) {
        case 22 : {
          _top_clicked = true;
          break;
        }
        case 18 : {
          _bot_clicked = true;
          break;
        }
        case 0 : {
          _lft_clicked = true;
          break;
        }
        case 3 : {
          _rgt_clicked = true;
          break;
        }
        default : {break;}
      }
      break;
    }
    case sf::Event::KeyReleased : {
      //std::cout << static_cast<int>(event.key.code) << std::endl;
      switch (event.key.code) {
        case 22 : {
          _top_clicked = false;
          break;
        }
        case 18 : {
          _bot_clicked = false;
          break;
        }
        case 0 : {
          _lft_clicked = false;
          break;
        }
        case 3 : {
          _rgt_clicked = false;
          break;
        }
        default : {break;}
      }
      break;
    }
    default : {
      break;
    }
  }
}

void GameWindow::concludeEvent() {
  setPlayerDirection();
  _game.updatePlayer(_player_direction);
  setPlayerPosition();
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
  else {
    _player_direction = standby;
  }
}

void GameWindow::setPlayerPosition() {
  Dimensions new_dimensions = _game.getPlayerDimensions();
  int quadrant_y = static_cast<int>(new_dimensions.y / _projection_size_y);
  int quadrant_x = static_cast<int>(new_dimensions.x / _projection_size_x);
  float screen_dimension_y = new_dimensions.y - static_cast<float>(quadrant_y * static_cast<int>(_projection_size_y));
  float screen_dimension_x = new_dimensions.x - static_cast<float>(quadrant_x * static_cast<int>(_projection_size_x));
  _player.setPosition(screen_dimension_x, screen_dimension_y);
}

bool GameWindow::pollEvent(sf::Event& event) {
  return _master.pollEvent(event);
}


// Getters
bool GameWindow::getOpen() {return _master.getOpen();}
Master& GameWindow::getMaster() {return _master;}