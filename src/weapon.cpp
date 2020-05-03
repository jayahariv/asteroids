#include "weapon.h"

Weapon::Weapon(int width, int height, float x, float y, float angle)
    : x(x)
    , y(y)
    , grid_width(width)
    , grid_height(height)
    , angle(angle) { };

Weapon::Weapon(const Weapon& w)
    : x(w.x)
    , y(w.y)
    , grid_width(w.grid_width)
    , grid_height(w.grid_height)
    , angle(w.angle) { };