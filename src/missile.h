#ifndef MISSILE_H
#define MISSILE_H

#include "weapon.h"

class Missile : public Weapon
{
public:
    Missile(int width, int height, float x, float y, float angle)
        : Weapon(width, height, x, y, angle, 0.1f) {};
    Missile(const Missile& m);
    Missile(Missile&& m);
    Missile &operator=(const Missile &w);
    Missile &operator=(Missile &&w);
    ~Missile() {};

    float Size() override           { return 0.5f; };

private:
};

#endif