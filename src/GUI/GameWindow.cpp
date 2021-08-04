/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : GameWindow methods
*/


#include "GameWindow.hpp"


void GameWindow::updateWindow() {
  _master->clearWindow();
  deleteAttacksDisplays();

  _master->drawRectangle(_background.getRectangle());
  std::size_t player_quadrant_x = _game->getPlayerQuadrantX();
  std::size_t player_quadrant_y = _game->getPlayerQuadrantY();
  drawWalls(player_quadrant_x, player_quadrant_y);
  drawMobs(player_quadrant_x, player_quadrant_y);
  drawPlayer();
  drawAttacks();
  if (player_quadrant_x == 0 && player_quadrant_y == 9) _master->drawText(_spawn_message.getText());
  _master->drawText(_keys_swap.getText());
  _master->displayWindow();
}

void GameWindow::drawPlayer() {
  choosePlayerAnimation();
  float div_x = _game_board_size_x / _board_divider;
  float div_y = _game_board_size_y / _board_divider;
  int quot_x = std::div(static_cast<int>(_game->getPlayerDimensions().x), static_cast<int>(div_x)).quot;
  int quot_y = std::div(static_cast<int>(_game->getPlayerDimensions().y), static_cast<int>(div_y)).quot;
  _player_hp.clear();
  _player_hp.emplace_back(_game->getPlayerSize().x * _hp_display_prop, _hp_display_height,
                          _player.getX() - _game->getPlayerSize().x, _player.getY() + _game->getPlayerSize().y + _hp_display_height,
                          sf::Color(255, 255, 255, 100), sf::Color::Transparent, 0.f, 0.f);
  _player_hp.emplace_back(_game->getPlayerSize().x * _hp_display_prop * _game->getPlayerHealth(), _hp_display_height,
                          _player.getX() - _game->getPlayerSize().x, _player.getY() + _game->getPlayerSize().y + _hp_display_height,
                          sf::Color(255, 0, 0, 100), sf::Color::Transparent, 0.f, 0.f);
  if (_game->getPlayerAttackToBeDisplayed()) {
    setPlayerAttackAnimation();
    AttackToDisplay attack_to_charge = _game->getPlayerAttackDisplay();
    _animated_attacks_displays.emplace_back(attack_to_charge);
    _animated_attacks.emplace_back(_game_master.getMagicBallTexture(), sf::Vector2u(_magic_ball_texture_x , _magic_ball_texture_y), 
                                   attack_to_charge.hit_display_time, false,
                                   Dimensions(attack_to_charge.display_pos.x - (static_cast<float>(quot_x) * div_x), attack_to_charge.display_pos.y - (static_cast<float>(quot_y) * div_y)),
                                   Dimensions(attack_to_charge.starting_size.x, attack_to_charge.starting_size.y),
                                   _player_attack_direction); 
    _game->playerAttackDisplayed();
  }
  _master->drawRectangle(_player.getRectangle());
  _master->drawRectangle(_player_hp[0].getRectangle());
  _master->drawRectangle(_player_hp[1].getRectangle());
}

void GameWindow::drawMobs(std::size_t player_quadrant_x, std::size_t player_quadrant_y) {
  std::vector<std::shared_ptr<Spawner>> spawners = _game->getSpawners();
  _mobs.clear();
  _mobs_hp.clear();

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
        _mobs.emplace_back(mob->getSize().x, mob->getSize().y, pos_x, pos_y, sf::Color(0, 0, 0), sf::Color(0,0,0), 0.5f, 0.f);
        _mobs_hp.emplace_back(std::vector<Rectangle>{});
        _mobs_hp[mob_index].emplace_back(mob->getSize().x * _hp_display_prop, _hp_display_height,
                                         pos_x - mob->getSize().x, pos_y + mob->getSize().y + _hp_display_height,
                                         sf::Color(255, 255, 255, 100), sf::Color::Transparent, 0.f, 0.f);
        _mobs_hp[mob_index].emplace_back(mob->getSize().x * _hp_display_prop * mob->getHealthProportion(), _hp_display_height,
                                         pos_x - mob->getSize().x, pos_y + mob->getSize().y + _hp_display_height,
                                         sf::Color(255, 0, 0, 100), sf::Color::Transparent, 0.f, 0.f);
        if (in_screen_mobs[mob_index]->getAttackToDisplay()) {
          AttackToDisplay attack_to_charge = in_screen_mobs[mob_index]->getAttackDisplay();
          std::shared_ptr<sf::Texture> animation_texture = _game_master.getMobAttackTexture(attack_to_charge.skin);
          _animated_attacks_displays.emplace_back(attack_to_charge);
          _animated_attacks.emplace_back(animation_texture, sf::Vector2u(_mob_attack_1_x, _mob_attack_1_y), attack_to_charge.hit_display_time, false,
                                         Dimensions(attack_to_charge.pos.x - (static_cast<float>(quot_x) * div_x), attack_to_charge.pos.y - (static_cast<float>(quot_y) * div_y)),
                                         Dimensions(attack_to_charge.size.x, attack_to_charge.size.y), attack_to_charge.attack_direction);
          in_screen_mobs[mob_index]->attackDisplayed();
        }
        _master->drawRectangle(_mobs[mob_index].getRectangle());
        _master->drawRectangle(_mobs_hp[mob_index][0].getRectangle());
        _master->drawRectangle(_mobs_hp[mob_index][1].getRectangle());
      }
    }
  }
}

void GameWindow::drawWalls(std::size_t player_quadrant_x, std::size_t player_quadrant_y) {
  std::vector<std::shared_ptr<GameEntity>> walls = _game->getWalls(player_quadrant_x, player_quadrant_y);
  _walls.clear();

  for (std::size_t wall_index = 0; wall_index < walls.size(); ++wall_index) {
    _walls.emplace_back(walls[wall_index]->getSize().x, 
                        walls[wall_index]->getSize().y, 
                        walls[wall_index]->getPosition().x - static_cast<float>(player_quadrant_x) * _projection_size_x,
                        walls[wall_index]->getPosition().y - static_cast<float>(player_quadrant_y) * _projection_size_y, 
                        sf::Color::White, sf::Color::Yellow, 0.f, 0.f);
    _master->drawRectangle(_walls[wall_index].getRectangle());
  } 
}

void GameWindow::processEvent(sf::Event event) {
  _swap_pressed = false;
  switch (event.type) {
    case sf::Event::Closed : {
      _master->closeWindow();
      break;
    }
    case sf::Event::MouseButtonPressed : {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Dimensions keys_swap_pos(_keys_swap.getX() * (static_cast<float>(_master->getWindow()->getSize().x) / _projection_size_x),
                                 _keys_swap.getY() * (static_cast<float>(_master->getWindow()->getSize().y) / _projection_size_y));
        Dimensions keys_swap_size(_keys_swap.getText().getGlobalBounds().width * (static_cast<float>(_master->getWindow()->getSize().x) / _projection_size_x),
                                  _keys_swap.getText().getGlobalBounds().height * (static_cast<float>(_master->getWindow()->getSize().y) / _projection_size_y));
        if (keys_swap_pos.x <= static_cast<float>(event.mouseButton.x) && static_cast<float>(event.mouseButton.x) <= keys_swap_pos.x + keys_swap_size.x &&
            keys_swap_pos.y <= static_cast<float>(event.mouseButton.y) && static_cast<float>(event.mouseButton.y) <= keys_swap_pos.y + keys_swap_size.y) {
          _swap_pressed = true;
          break;
        }
      }
      break;
    }
    case sf::Event::KeyPressed : {
      //std::cout << static_cast<int>(event.key.code) << std::endl;
      if (event.key.code == _move_top) {_top_clicked = true; break;} 
      else if (event.key.code == _move_bot) {_bot_clicked = true; break;}
      else if (event.key.code == _move_lft) {_lft_clicked = true; break;}
      else if (event.key.code == _move_rgt) {_rgt_clicked = true; break;}
      else if (event.key.code == 71) {_lft_attack = true; break;}
      else if (event.key.code == 72) {_rgt_attack = true; break;}
      else if (event.key.code == 73) {_top_attack = true; break;}
      else if (event.key.code == 74) {_bot_attack = true; break;}
      else if (event.key.code == sf::Keyboard::Escape) {
        _master->closeWindow();
        break;
      }
      break;
    }
    case sf::Event::KeyReleased : {
      //std::cout << static_cast<int>(event.key.code) << std::endl;
      if (event.key.code == _move_top) {_top_clicked = false; break;} 
      else if (event.key.code == _move_bot) {_bot_clicked = false; break;}
      else if (event.key.code == _move_lft) {_lft_clicked = false; break;}
      else if (event.key.code == _move_rgt) {_rgt_clicked = false; break;}
      else if (event.key.code == 71) {_lft_attack = false; break;}
      else if (event.key.code == 72) {_rgt_attack = false; break;}
      else if (event.key.code == 73) {_top_attack = false; break;}
      else if (event.key.code == 74) {_bot_attack = false; break;}
      break;
    }
    default: {break;}
  }
}

void GameWindow::concludeEvent() {
  if (_swap_pressed) swapMoveKeys();
  if (!_game->isOver()) {
    setPlayerDirections();
    _game->updateGame(_player_direction, _player_attack_direction);
    setPlayerPosition();
  }
  else {
    _master->closeWindow();
  }
}

void GameWindow::setPlayerDirections() {
  if (_top_clicked && _rgt_clicked) {_player_direction = north_east;}
  else if (_rgt_clicked && _bot_clicked) {_player_direction = south_east;}
  else if (_bot_clicked && _lft_clicked) {_player_direction = south_west;}
  else if (_lft_clicked && _top_clicked) {_player_direction = north_west;}
  else if (_top_clicked) {_player_direction = north;}
  else if (_rgt_clicked) {_player_direction = east;}
  else if (_bot_clicked) {_player_direction = south;}
  else if (_lft_clicked) {_player_direction = west;}
  else {_player_direction = standby;}
  if (_top_attack) {_player_attack_direction = north;}
  else if (_bot_attack) {_player_attack_direction = south;}
  else if (_rgt_attack) {_player_attack_direction = east;}
  else if (_lft_attack) {_player_attack_direction = west;}
  else {_player_attack_direction = standby;}
}

void GameWindow::setPlayerPosition() {
  Dimensions new_dimensions = _game->getPlayerDimensions();
  int quadrant_y = static_cast<int>(new_dimensions.y / _projection_size_y);
  int quadrant_x = static_cast<int>(new_dimensions.x / _projection_size_x);
  float screen_dimension_y = new_dimensions.y - static_cast<float>(quadrant_y * static_cast<int>(_projection_size_y));
  float screen_dimension_x = new_dimensions.x - static_cast<float>(quadrant_x * static_cast<int>(_projection_size_x));
  _player.setPosition(screen_dimension_x, screen_dimension_y);
}

void GameWindow::deleteAttacksDisplays() {
  for (std::size_t attack_display_index = 0; attack_display_index < _animated_attacks_displays.size(); ++attack_display_index) {
    if (!_animated_attacks[attack_display_index].checkLoop() && _animated_attacks[attack_display_index].checkLastImage()) {
      _animated_attacks.erase(_animated_attacks.begin() + static_cast<int>(attack_display_index));
      _animated_attacks_displays.erase(_animated_attacks_displays.begin() + static_cast<int>(attack_display_index));
      --attack_display_index;
    }
  }
}

void GameWindow::drawAttacks() {
  for (std::size_t attack_index = 0; attack_index < _animated_attacks.size(); ++attack_index) {
    _animated_attacks[attack_index].nextImage(_game->getGameTimer());
    _master->drawRectangle(_animated_attacks[attack_index].getRectangle());
  }
}

void GameWindow::swapMoveKeys() {
  if (_move_top == sf::Keyboard::W) {
    _move_top = sf::Keyboard::Z;
    _move_lft = sf::Keyboard::Q;
  }
  else {
    _move_top = sf::Keyboard::W;
    _move_lft = sf::Keyboard::A;
  }
  _swap_pressed = false;
  _top_clicked = false;
  _bot_clicked = false;
  _rgt_clicked = false;
  _lft_clicked = false;
  _top_attack = false;
  _bot_attack = false;
  _rgt_attack = false;
  _lft_attack = false;
}

void GameWindow::setPlayerAttackAnimation() {
  _player.setLoop(false);
  _player.setSwitchTime(_classic_weapon_display_time);
  if (_player_attack_direction == north) _player.update(8);
  else if (_player_attack_direction == south) _player.update(7);
  else if (_player_attack_direction == west) _player.update(6);
  else if (_player_attack_direction == east) _player.update(5);
}

void GameWindow::choosePlayerAnimation() {
  _player.nextImage(_game->getGameTimer());
  if (_player.checkLoop() || (!_player.checkLoop() && _player.checkLastImage()) || _old_player_direction != _player_direction) {
    if (!_player.checkLoop()) {
      _player.setLoop(true);
      _player.setSwitchTime(_player_display_time);
    }
    setPlayerNormalAnimation();
  }
  _old_player_direction = _player_direction;
}

void GameWindow::setPlayerNormalAnimation() {
  if (_player_direction == standby) _player.update(0);
  else if (_player_direction == north) _player.update(4);
  else if (_player_direction == south) _player.update(3);
  else if (_player_direction < south) _player.update(1);
  else if (_player_direction > south) _player.update(2);
}