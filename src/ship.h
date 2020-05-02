#include <vector>
#include "SDL.h"

#include "weapon.h"

class Ship {
public:
    enum class Direction { kNone, kForward, kBackward };
    enum class Angle { kNone, kLeft, kRight };
    
    Ship() = delete;
    Ship(int grid_width, int grid_height) 
        : _grid_width(grid_width)
        , _grid_height(_grid_height)
        , _x(_grid_width/2)
        , _y(_grid_height - 10) { };

    void Update();
    bool ShipCell(int x, int y) { return x == _x && y == _y; };

    Direction direction = Direction::kNone;
    Angle angle = Angle::kNone;

    bool destroyed{false};

private: 
    int _grid_width, _grid_height; 
    float _x, _y; //postion of ship
    
    float _shootingSpeed{0.1f};
    std::vector<std::unique_ptr<Weapon>> _weapons; 
};