#include "ship.h"
#include "missile.h"

Ship::Ship(int grid_width, int grid_height)
    : _grid_width(grid_width)
    , _grid_height(grid_height)
{
    x = _grid_width / 2;
    y = _grid_height - 10;
};

void Ship::Update()
{
    UpdatePosition();

    RemoveDestroyedWeapons();

    LoadNewWeapon();

    UpdateWeapons();
}

void Ship::UpdatePosition()
{
    // todo: change this to use angle!!!

    switch (direction)
    {
    case Direction::kForward:
        y -= _speed;
        break;

    case Direction::kBackward:
        y += _speed;
        break;
    default: 
        break;
    }

    switch (angle)
    {
    case Angle::kLeft:
        x -= _speed;
        break;
    case Angle::kRight:
        x += _speed;
        break;
    default: 
        break;
    }

    x = fmod(x + _grid_width, _grid_width);
    y = fmod(y + _grid_height, _grid_height);
}

void Ship::RemoveDestroyedWeapons()
{
    // Remove destroyed weapons
    while (true) {
        auto iter = std::find_if(weapons.begin(), weapons.end(), 
                                    [](const std::unique_ptr<Weapon> &w) { return w->destroyed; });
        if (iter != weapons.end())
            weapons.erase(iter);
        else 
            return;
    }
    
}

void Ship::LoadNewWeapon()
{
    auto w = std::make_unique<Missile>(_grid_width, _grid_height, x, y, 1.0);
    weapons.push_back(std::move(w));
}

void Ship::UpdateWeapons()
{
    for (const std::unique_ptr<Weapon> &w : weapons)
        w->Update();
}