/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameWindow methods
*/


#include "GameWindow.hpp"


void GameWindow::updateWindow() {
  _master.clearWindow();
  _walls.clear();
  _master.drawRectangle(_background.getRectangle());
  _master.drawRectangle(_player.getRectangle());
  std::size_t player_quadrant_x = _game.getPlayerQuadrantX();
  std::size_t player_quadrant_y = _game.getPlayerQuadrantY();
  std::vector<std::shared_ptr<GameEntity>> walls = _game.getWalls(player_quadrant_x, player_quadrant_y);
  std::vector<std::shared_ptr<Spawner>> spawners = _game.getSpawners();
  _mobs.clear();
  for (std::size_t spawner_index = 0; spawner_index < spawners.size(); ++spawner_index) {
    if (spawners[spawner_index]->getQuadrantX() == player_quadrant_x && spawners[spawner_index]->getQuadrantY() == player_quadrant_y) {
      std::vector<std::shared_ptr<Mob>> in_screen_mobs = spawners[spawner_index]->getMobs();
      for (std::size_t mob_index = 0; mob_index < in_screen_mobs.size(); ++mob_index) {
        std::shared_ptr<Mob> mob = in_screen_mobs[mob_index];
        float div_x = _game_board_size_x / _board_divider;
        float div_y = _game_board_size_y / _board_divider;
        int quot_x = std::div(static_cast<int>(mob->getPosition().x), static_cast<int>(div_x)).quot;
        int quot_y = std::div(static_cast<int>(mob->getPosition().y), static_cast<int>(div_y)).quot;
        float pos_x = mob->getPosition().x - (static_cast<float>(quot_x) * div_x);
        float pos_y = mob->getPosition().y - (static_cast<float>(quot_y) * div_y);
        _mobs.emplace_back(mob->getSize().x, mob->getSize().y, pos_x, pos_y, sf::Color::Red, sf::Color(0,0,0), 0.5f, 0.f);
        _master.drawRectangle(_mobs[mob_index].getRectangle());
      }
    }
  }
  for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
    _walls.emplace_back(walls[wall_index]->getSize().x, 
                        walls[wall_index]->getSize().y, 
                        walls[wall_index]->getPosition().x - static_cast<float>(player_quadrant_x) * _projection_size_x,
                        walls[wall_index]->getPosition().y - static_cast<float>(player_quadrant_y) * _projection_size_y, 
                        sf::Color::White, sf::Color::Yellow, 0.5f, 0.f);
    _master.drawRectangle(_walls[wall_index].getRectangle());
  } 
  _master.drawText(_spawn_text.getText());
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