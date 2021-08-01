 /*
  Author : Dominik Dabkowski
  Specs  : GNU C++ version 10.2 - "gg+ -std=c++17"
  Code   : Animation methods
*/


#include "Animation.hpp"


// Methods
void Animation::update(unsigned int row, float time) {
  _current_image.y = row;

  nextImage(time);
}

void Animation::nextImage(float time) {
  if (time - _last_change > _switch_time) {
    _last_change = time;
    ++_current_image.x;

    if (_repeat && _current_image.x > _image_count.x) _current_image.x = 0;
  }

  _animation.left = static_cast<int>(_current_image.x) * _animation.width;
  _animation.top  = static_cast<int>(_current_image.y) * _animation.height;
  _rectangle.setTextureRect(_animation);
}

// Getters
const bool& Animation::checkLoop() const {return _repeat;}
bool Animation::checkLastImage() {return _current_image.x > _image_count.x;}
sf::RectangleShape Animation::getRectangle() {return _rectangle;}