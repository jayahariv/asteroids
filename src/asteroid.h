#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid {
public:
    Asteroid() = delete;
    Asteroid(int grid_width, int grid_height, float x, float y, int size)
        : _x(x), _y(y), _grid_width(grid_width), _grid_height(grid_height), _size(size) {};
    
    void Update();
    const bool Destroyed()      { return _destroyed; };
    const int Size()            { return _size; };
    const float X()             { return _x; };
    const float Y()             { return _y; };
    void Hit(int weaponSize)          { _impact = weaponSize; }

private:
    float _speed{0.03};
    int _grid_width, _grid_height;
    bool _destroyed{false};
    int _size; // size of the asteroid, 
    float _x, _y;
    int _impact{0}; // impact of hit
};

#endif