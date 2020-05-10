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
    float Size()                { return 2.0; };

    Direction direction = Direction::kNone;
    Angle angle = Angle::kNone;
    bool fire{false};
    bool destroyed{false};
    float x, y;                                     //postion of ship
    std::vector<std::unique_ptr<Weapon>> weapons;
    float degree_rotation{270};     // ship to move up on start, needs y value to go down!

private:
    int _grid_width, _grid_height;
    float _speed{0.1f};
    float _weapon_cooldown{0.3};    // (seconds) cool down before loading next weapon

    std::chrono::time_point<std::chrono::steady_clock> _last_weapon_load{std::chrono::steady_clock::now()};

    void UpdatePosition();
    void RemoveDestroyedWeapons();
    void LoadNewWeapon();
    void UpdateWeapons();
};

#endif