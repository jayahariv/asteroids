#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "ship.h"
#include "asteroid.h" 

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Ship &ship, std::vector<std::unique_ptr<Asteroid>> &asteriods);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Texture * ship_texture;
  SDL_Texture * ast_texture;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif