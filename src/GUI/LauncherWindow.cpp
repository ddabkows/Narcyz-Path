/*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : LauncherWindow methods
*/


#include "LauncherWindow.hpp"


// Methods
void LauncherWindow::processEvent(sf::Event event) {
  _new_game.unClick();
  switch (event.type) {
    case sf::Event::Closed : {
      _master->closeWindow();
      break;
    }
    case sf::Event::MouseButtonPressed : {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        checkTextCollision(event, _new_game);
        checkTextCollision(event, _exit_game);
      }
      break;
    }
    default : break;
  }
}
void LauncherWindow::concludeEvent() {
  if (_new_game.isClicked()) _gui->setWindow(std::make_shared<GameWindow>(_gui, _master->getWindow(), _game));
  else if (_exit_game.isClicked()) _master->closeWindow();
}
void LauncherWindow::updateWindow() {
  _master->clearWindow();
  _master->drawText(_new_game.getText());
  _master->drawText(_exit_game.getText());
  _master->displayWindow();
}
void LauncherWindow::checkTextCollision(sf::Event event, Text& text) {
  Dimensions text_pos(text.getX() * (static_cast<float>(_master->getWindow()->getSize().x) / _projection_size_x),
                      text.getY() * (static_cast<float>(_master->getWindow()->getSize().y) / _projection_size_y));
  Dimensions text_size(text.getText().getGlobalBounds().width * (static_cast<float>(_master->getWindow()->getSize().x) / _projection_size_x),
                       text.getText().getGlobalBounds().height * (static_cast<float>(_master->getWindow()->getSize().y) / _projection_size_y));
  if (text_pos.x <= static_cast<float>(event.mouseButton.x) && static_cast<float>(event.mouseButton.x) <= text_pos.x + text_size.x &&
      text_pos.y <= static_cast<float>(event.mouseButton.y) && static_cast<float>(event.mouseButton.y) <= text_pos.y + text_size.y) text.click();
  else text.unClick();
}