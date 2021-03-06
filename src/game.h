#ifndef GAME_H
#define GAME_H

#include <random>
#include <algorithm>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "asteroid.h"
#include "ship.h"

static const int MAX_ASTEROIDS{8};

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const { return _score; }

 private:
  Ship ship;
  std::vector<std::unique_ptr<Asteroid>> _asteroids;
  std::size_t _grid_width, _grid_height;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_size;
  std::uniform_int_distribution<int> random_angle;

  int _score{0};

  void PlaceFood();
  void Update();
  void GenerateAsteroids();
};

#endif