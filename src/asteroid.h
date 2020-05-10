#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid {
public:
    Asteroid() = delete;
    Asteroid(int grid_width, int grid_height, float x, float y, float size, int angle);
    
    void Update();
    const bool Destroyed()              { return _destroyed; };
    const float Size()                  { return _size; };
    const float X()                     { return _x; };
    const float Y()                     { return _y; };
    void Hit(float weaponSize)          { _impact = weaponSize; };
    bool AsteroidCell(float x, float y, float w, float h) {
        return x <= (_x + _size) && (x + w) >= _x && y <= (_y + _size) && (y + h) >= _y; 
    };

private:
    float _speed{0.03};
    int _grid_width, _grid_height;
    bool _destroyed{false};
    float _size; // size of the asteroid, 
    float _x, _y;
    float _impact{0}; // impact of hit
    int _angle;
};

#endif