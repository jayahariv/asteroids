#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid {
public:
    Asteroid() = delete;
    Asteroid(float x, float y): x(x), y(y) {};
    
    void Update();

    float x, y;
    bool destroyed{false};

private:
    float _speed{0.1};
};

#endif