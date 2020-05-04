#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
public:
    Weapon(int width, int height, float x, float y, float angle);
    Weapon(const Weapon &w);
    Weapon(Weapon &&w);
    Weapon &operator=(const Weapon &w);
    Weapon &operator=(Weapon &&w);
    virtual ~Weapon(){};

    virtual void Update() = 0;
    virtual bool WeaponCell(int x, int y);

    bool destroyed{false}; // (1)hitting target or (2)remove from frame
    float x, y;            // position

protected:
    float angle;

    int grid_width;
    int grid_height;
};

#endif