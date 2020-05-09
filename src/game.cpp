#include "SDL.h"
#include "game.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : ship(grid_width, grid_height)
    , engine(dev())
    , random_w(0, static_cast<int>(grid_width - 3))  // width minus size 
    , random_size(1, 3)
    , _grid_width(grid_width)
    , _grid_height(grid_height) { }

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
    renderer.Render(ship, _asteroids);

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

void Game::Update() {
  if (ship.destroyed) return;

  // remove destroyed asteriods
  while (true) 
  {
    auto iter = std::find_if(_asteroids.begin(), _asteroids.end(), [](auto &a) { return a->Destroyed(); });
    if (iter != _asteroids.end())
      _asteroids.erase(iter);
    else 
      break;
  }

  GenerateAsteroids();

  ship.Update();

  // update asteroids & check collision!
  for (auto &a : _asteroids) {
    a->Update();
    if (a->AsteroidCell(ship.x, ship.y, ship.Size(), ship.Size())) {
      ship.destroyed = true;
      return;
    }

    for (auto const& w : ship.weapons) {
      if (!a->Destroyed() && a->AsteroidCell(w->x, w->y, w->Size(), w->Size())) {
        a->Hit(w->Size());
        w->destroyed = true; 
      }
    }

    if (a->Destroyed())
      _score++;
  }
}

void Game::GenerateAsteroids() {
  if (_asteroids.size() == MAX_ASTEROIDS) return;
  
  float x, y, size;
  while (_asteroids.size() < MAX_ASTEROIDS ) {
    x = random_w(engine);
    y = 0; 
    size = (float)random_size(engine) / (float)2;

    bool already_taken = false;
    for (auto &a : _asteroids) {
      if (a->AsteroidCell(x, y, a->Size(), a->Size())) {
        already_taken = true;
        break;
      }
    }
    if (!already_taken && !ship.ShipCell(x, y)) {
      auto a = std::make_unique<Asteroid>(_grid_width, _grid_height, x, y, size);
      _asteroids.push_back(std::move(a));
    }
  }
}