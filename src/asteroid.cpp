#include "asteroid.h"
#include <iostream>

Asteroid::Asteroid(int grid_width, int grid_height, float x, float y, float size)
    : _x(x), _y(y), _grid_width(grid_width), _grid_height(grid_height), _size(size)
{
   
};

void Asteroid::Update()
{
    _y += _speed;
    _size -= _impact;
    _impact = 0;

    if (_x > _grid_width || _y > _grid_height || _size == 0)
        _destroyed = true;
}