#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "SDL.h"
#include <chrono>
#include <ctime>

#include "weapon.h"

class Ship
{
public:
    enum class Direction
    {
        kNone,
        kForward,
        kBackward
    };
    enum class Angle
    {
        kNone,
        kLeft,
        kRight
    };

    Ship() = delete;
    Ship(int grid_width, int grid_height);

    void Update();
    bool ShipCell(int x, int y) { return x == this->x && y == this->y; };

    Direction direction = Direction::kNone;
    Angle angle = Angle::kNone;

    bool destroyed{false};
    float x, y; //postion of ship
    std::vector<std::unique_ptr<Weapon>> weapons;

private:
    int _grid_width, _grid_height;
    float _speed{0.1f};
    float _weapon_cooldown{0.3}; // cool down before loading next weapon

    std::time_t _last_weapon_load{static_cast<std::time_t>(0)};

    void UpdatePosition();
    void RemoveDestroyedWeapons();
    void LoadNewWeapon();
    void UpdateWeapons();
};

#endif