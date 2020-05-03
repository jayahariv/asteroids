#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : ship(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) { }

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, ship);
    Update();
    renderer.Render(ship, asteroids);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(_score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::GenerateAsteroids() {
  if (asteroids.size() == MAX_ASTEROIDS) return;
  
  int x, y;
  while (asteroids.size() < MAX_ASTEROIDS ) {
    x = random_w(engine);
    
    if (!ship.ShipCell(x, y)) {
      Asteroid a(x, 0);
      asteroids.push_back(a);
    }
  }
}

void Game::Update() {
  if (ship.destroyed) return;

  // remove destroyed asteriods
  while (true) 
  {
    auto iter = std::find_if(asteroids.begin(), asteroids.end(), [](const Asteroid a) { return a.destroyed; });
    if (iter != asteroids.end())
      asteroids.erase(iter);
    else 
      break;
  }

  GenerateAsteroids();

  ship.Update();

  // update asteroids & check collision!
  int new_x = static_cast<int>(ship.x);
  int new_y = static_cast<int>(ship.y);
  for (auto a : asteroids) {
    a.Update();
    if (a.x == new_x && a.y == new_y) {
      ship.destroyed = true;
      return;
    }

    for (auto const& w : ship.weapons) {
      if (a.x == w->x && a.y == w->y) {
        a.destroyed = true;
        _score++;
      }
    }
  }
}