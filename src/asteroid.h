#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid {
public:
    Asteroid() = delete;
    Asteroid(int grid_width, int grid_height, float x, float y)
        : x(x), y(y), _grid_width(grid_width), _grid_height(grid_height) {};
    
    void Update();

    float x, y;
    bool destroyed{false};

private:
    float _speed{0.03};
    int _grid_width, _grid_height;
};

#endif