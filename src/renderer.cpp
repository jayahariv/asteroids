#include "renderer.h"
#include <iostream>
#include <string>
#include <math.h>
#include "SDL_image.h"

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Ship Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  ship_texture = IMG_LoadTexture(sdl_renderer, "../ship.png");
  ast_texture = IMG_LoadTexture(sdl_renderer, "../ast.png");
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Ship &ship, std::vector<std::unique_ptr<Asteroid>> &asteriods) {
  SDL_Rect block;
  float width = screen_width / grid_width;
  float height = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render asteriods
  for (auto &a : asteriods) {
    int x = a->X() * width;
    int y = a->Y() * height;
    int size = a->Size() * width;
    const SDL_Rect rect = {x, y, size, size};
    SDL_RenderCopyEx(sdl_renderer, ast_texture, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
  }

  // Render Ship
  int x = ship.x * width;
  int y = ship.y * height;
  int size = ship.Size() * width;

  const SDL_Rect rect = {x, y, size, size + 20};
  SDL_RenderCopyEx(sdl_renderer, ship_texture, NULL, &rect, ship.degree_rotation - 270, NULL, SDL_FLIP_NONE);
  
  // Render Weapons
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  for (auto const &w : ship.weapons)
  {
    block.x = (w->x) * width;
    block.y = (w->y) * height;
    block.w = w->Size() * width;
    block.h = w->Size() * height;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Asteriods Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
