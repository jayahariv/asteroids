#ifndef MISSILE_H
#define MISSILE_H

#include "weapon.h"

class Missile : public Weapon
{
public:
    Missile(int width, int height, float x, float y, float angle)
        : Weapon(width, height, x, y, angle) {};
    Missile(const Missile& m);
    Missile(Missile&& m);
    Missile &operator=(const Missile &w);
    Missile &operator=(Missile &&w);
    ~Missile() {};

    void Update() override;
    float Size() override           { return 0.5f; };

private:
    float _speed{0.1};
};

#endif