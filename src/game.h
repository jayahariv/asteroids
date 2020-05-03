#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "asteroid.h"
#include "ship.h"

static const int MAX_ASTEROIDS{5};

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const { return _score; }

 private:
  Ship ship;
  std::vector<Asteroid> asteroids;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int _score{0};

  void PlaceFood();
  void Update();
  void GenerateAsteroids();
};

#endif