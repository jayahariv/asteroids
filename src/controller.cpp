#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, Ship &ship) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ship.direction = Ship::Direction::kForward;
          break;

        case SDLK_DOWN:
          ship.direction = Ship::Direction::kBackward;
          break;

        case SDLK_LEFT:
          ship.angle = Ship::Angle::kLeft;
          break;

        case SDLK_RIGHT:
          ship.angle = Ship::Angle::kRight;
          break;
        case SDLK_a:
          ship.fire = true;
          break;
      }
    } else if (e.type == SDL_KEYUP) {
      ship.direction = Ship::Direction::kNone;
      ship.angle = Ship::Angle::kNone;
      ship.fire = false;
    }
  }
}