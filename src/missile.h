#ifndef MISSILE_H
#define MISSILE_H

#include "weapon.h"

class Missile : public Weapon
{
public:
    Missile() = delete;
    Missile(int width, int height, float x, float y, float angle)
        : Weapon(width, height, x, y, angle){};
    Missile(const Missile& m)
        : Weapon(m.grid_width, m.grid_width, m.x, m.y, m.angle) {};

    void Update() override;
    bool WeaponCell(int x, int y) override { return x == this->x && y == this->y; };

private:
    float _speed{0.1};
};

#endif