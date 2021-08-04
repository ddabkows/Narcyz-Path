 /*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Animation methods
*/


#include "Animation.hpp"
#include <iostream>


// Methods
void Animation::update(unsigned int row) {
  _current_image.y = row;
  _current_image.x = 0;
}

void Animation::nextImage(float time) {
  if (_current_image.y != 0) std::cout << _current_image.y << std::endl;
  if (time - _last_change > _switch_time) {
    _last_change = time;
    ++_current_image.x;

    if (_repeat && _current_image.x > _image_count.x) _current_image.x = 0;
  }

  _animation.left = static_cast<int>(_current_image.x) * _animation.width;
  _animation.top  = static_cast<int>(_current_image.y) * _animation.height;
  _rectangle.setTextureRect(_animation);
}

// Setters
void Animation::setLoop(bool loop) {_repeat = loop;}
void Animation::setPosition(float x, float y) {_rectangle.setPosition(x, y);}
void Animation::setSwitchTime(float new_total_time) {_switch_time = new_total_time / static_cast<float>(_image_count.x);}
// Getters
const bool& Animation::checkLoop() const {return _repeat;}
bool Animation::checkLastImage() {return _current_image.x == _image_count.x-1;}
sf::RectangleShape Animation::getRectangle() {return _rectangle;}
const float& Animation::getX() const {return _rectangle.getPosition().x;}
const float& Animation::getY() const {return _rectangle.getPosition().y;}