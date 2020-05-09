#include "asteroid.h"

void Asteroid::Update() 
{
    _y += _speed;

    if (_y > _grid_height || _x > _grid_width)
        _destroyed = true;

    _size -= _impact;
    _impact = 0;

    _destroyed = _size == 0;
}