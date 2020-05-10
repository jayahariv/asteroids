#include "weapon.h"
#include <math.h>

Weapon::Weapon(int width, int height, float x, float y, float angle, float speed)
    : x(x), y(y), grid_width(width), grid_height(height), angle(angle), speed(speed) {};

Weapon::Weapon(const Weapon &w)
    : x(w.x), y(w.y), grid_width(w.grid_width), grid_height(w.grid_height), angle(w.angle), speed(w.speed) {};

Weapon::Weapon(Weapon &&w) 
{
    x = std::move(w.x);
    y = std::move(w.y);
    grid_width = std::move(w.grid_width);
    grid_height = std::move(w.grid_height);
    angle = std::move(w.angle);
    speed = std::move(w.speed);
};

Weapon &Weapon::operator=(const Weapon &w)
{
    if(this != &w) {
        x = w.x;
        y = w.y;
        grid_width = w.grid_width;
        grid_height = w.grid_height;
        angle = w.angle;
        speed = w.speed;
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
        speed = std::move(w.speed);
    }
    return *this;
}

void Weapon::Update() {
    float dx = cos(angle * M_PI / 180.0) * speed;
    float dy = sin(angle * M_PI / 180.0) * speed;
    
    x += dx;
    y += dy;

    if (x < 0 || y < 0)
        destroyed = true; // out of frame
}