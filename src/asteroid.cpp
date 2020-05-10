#include "asteroid.h"
#include <math.h>

Asteroid::Asteroid(int grid_width, int grid_height, float x, float y, float size, int angle)
    : _x(x), _y(y), _grid_width(grid_width), _grid_height(grid_height), _size(size), _angle(angle) { };

void Asteroid::Update()
{
    float dx = cos(_angle * M_PI / 180.0) * _speed;
    float dy = sin(_angle * M_PI / 180.0) * _speed;
    _y += dx + _speed;
    _x += dy + _speed;

    _size -= _impact;
    _impact = 0;

    if (_x > _grid_width || _y > _grid_height || _size == 0)
        _destroyed = true;
}