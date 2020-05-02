#include "ship.h"

void Ship::Update()
{
    SDL_Point prev_cell{static_cast<int>(_x), static_cast<int>(_y)};
    UpdatePosition();
    SDL_Point cur_cell{static_cast<int>(_x), static_cast<int>(_y)};
    
    UpdateWeapon();

    Fire();
}

void Ship::UpdatePosition()
{
    // todo: change this to use angle!!!

    switch (direction)
    {
    case Direction::kForward:
        _y -= speed;
        break;

    case Direction::kBackward:
        _y += speed;
        break;
    }
    
    switch (angle)
    {
    case Angle::kLeft:
        _x -= speed;
        break;
    case Angle::kRight:
        _x += speed;
        break;
    }
}

void Ship::UpdateWeapon()
{
    auto iter = std::find_if(_weapons.begin(), _weapons.end(), [](const std::unique_ptr<Weapon> &w){ return w->destroyed; });

    for (const std::unique_ptr<Weapon> w : iter) 
        _weapons.erase(w);
}

void Ship::Fire()
{
    /*
    - init weapon and save to weapons array
    - finish weapons
    */

}