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
    int turn_angle = 5;
    degree_rotation += angle == Angle::kLeft ?  -turn_angle : angle == Angle::kRight ? turn_angle : 0.0;
    degree_rotation = fmod(degree_rotation, 360);
    
    float dx = cos(degree_rotation * M_PI / 180.0) * _speed;
    float dy = sin(degree_rotation * M_PI / 180.0) * _speed;

    x += direction == Direction::kForward ? dx : direction == Direction::kBackward ? -dx : 0.0;
    y += direction == Direction::kForward ? dy : direction == Direction::kBackward ? -dy : 0.0;

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
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - _last_weapon_load;
    if (fire && diff.count() > _weapon_cooldown) {
        auto w = std::make_unique<Missile>(_grid_width, _grid_height, x, y, degree_rotation);
        weapons.push_back(std::move(w));
        _last_weapon_load = now;
    }
}

void Ship::UpdateWeapons()
{
    for (const std::unique_ptr<Weapon> &w : weapons)
        w->Update();
}