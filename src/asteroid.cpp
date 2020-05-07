#include "asteroid.h"

void Asteroid::Update() 
{
    _y += _speed;

    if (_y >= _grid_height)
        _destroyed = true;

    if (hit) {
        --_size;
        hit = false;
    }

    _destroyed = _size == 0;
}