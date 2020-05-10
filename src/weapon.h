#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
public:
    Weapon(int width, int height, float x, float y, float angle, float speed);
    Weapon(const Weapon &w);
    Weapon(Weapon &&w);
    Weapon &operator=(const Weapon &w);
    Weapon &operator=(Weapon &&w);
    virtual ~Weapon(){};

    void Update();
    bool WeaponCell(int x, int y) { return x == this->x && y == this->y; };
    virtual float Size() = 0;

    bool destroyed{false}; // (1)hitting target or (2)remove from frame
    float x, y;            // position

protected:
    float angle;
    float speed{0.1f};

    int grid_width;
    int grid_height;
};

#endif