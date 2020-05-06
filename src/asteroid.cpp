#include "asteroid.h"

void Asteroid::Update() 
{
    y += _speed;

    if (y >= _grid_height)
        destroyed = true;
}