#include "missile.h"
#include <iostream>

Missile::Missile(const Missile &m)
    : Weapon(m.grid_width, m.grid_height, m.x, m.y, m.angle, m.speed)
{
}

Missile::Missile(Missile &&m)
    : Weapon(std::move(m.grid_width), std::move(m.grid_height), std::move(m.x), std::move(m.y)
    , std::move(m.angle), std::move(m.speed))
{
}

Missile &Missile::operator=(const Missile &m)
{
    if (this != &m)
    {
        grid_width = m.grid_width;
        grid_height = m.grid_height;
        x = m.x;
        y = m.y;
        angle = m.angle;
        speed = m.speed;
    }
    return *this;
}

Missile &Missile::operator=(Missile &&m)
{
    if (this != &m)
    {
        grid_width = std::move(m.grid_width);
        grid_height = std::move(m.grid_height);
        x = std::move(m.x);
        y = std::move(m.y);
        angle = std::move(m.angle);
        speed = std::move(m.speed);
    }
    return *this;
}