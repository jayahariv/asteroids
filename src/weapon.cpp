#include "weapon.h"
#include <iostream>

Weapon::Weapon(int width, int height, float x, float y, float angle)
    : x(x), y(y), grid_width(width), grid_height(height), angle(angle){};

Weapon::Weapon(const Weapon &w)
    : x(w.x), y(w.y), grid_width(w.grid_width), grid_height(w.grid_height), angle(w.angle){};

Weapon::Weapon(Weapon &&w) 
{
    x = std::move(w.x);
    y = std::move(w.y);
    grid_width = std::move(w.grid_width);
    grid_height = std::move(w.grid_height);
    angle = std::move(w.angle);
};

Weapon &Weapon::operator=(const Weapon &w)
{
    if(this != &w) {
        x = w.x;
        y = w.y;
        grid_width = w.grid_width;
        grid_height = w.grid_height;
        angle = w.angle;
    }
    return *this;
}
Weapon &Weapon::operator=(Weapon &&w)
{
    if(this != &w) {
        x = std::move(w.x);
        y = std::move(w.y);
        grid_width = std::move(w.grid_width);
        grid_height = std::move(w.grid_height);
        angle = std::move(w.angle);
    }
    return *this;
}