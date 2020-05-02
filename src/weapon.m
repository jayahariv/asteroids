#include "weapon.h"

Weapon::Weapon(int width, int height, int x, int y, float angle)
: _x(x)
, _y(y)
, _grid_width(width)
, _grid_height(height)
, _angle(angle) { }