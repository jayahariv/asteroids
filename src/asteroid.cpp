#include "asteroid.h"

void Asteroid::Update() 
{
    _y += _speed;
    _size -= _impact;
    _impact = 0;
    
    if (_x > _grid_width || _y > _grid_height || _size == 0)
        _destroyed = true;
}