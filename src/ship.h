#include <vector>
#include "SDL.h"

#include "weapon.h"

class Ship {
public:
    enum class Direction { kNone, kForward, kBackward };
    enum class Angle { kNone, kLeft, kRight };
    
    Ship();

    // updates the ship position and bullet position
    void Update();
    // check bullets is in given position
    bool isBulletsCell(int x, int y);

    Direction direction = Direction::kNone;
    Angle angle = Angle::kNone;

    bool destroyed{false};

    // position of ship
    float x;
    float y;

private: 
    float _shootingSpeed{0.1f};
    std::vector<Weapon> _bullets; 
};