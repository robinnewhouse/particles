#include <iostream>

#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "windows.h"

using namespace std;
//#undef main

int main() {
  std::cout << "Hello, World!" << std::endl;

  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  if (SDL_Init(SDL_INIT_VIDEO < 0)) {
    cout << "SDL_Init Failed" << endl;
    return 1;
  };

  SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    cout << "Could not create window" << endl;
    return 2;
  };

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT); // try SDL_TEXTUREACCESS_STREAMING here

  if (renderer == nullptr) {
    cout << "Could not create renderer" << endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 3;
  }
  if (texture == nullptr) {
    cout << "Could not create texture" << endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 4;
  }

  Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
//  Uint32 * buffer2 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
  memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);


  bool quit = false;
  while (!quit) {
    // Update particles
    // Draw particles
    // Check for messages/events

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }
//  Sleep(5000);

  cout << "Destroying windows" << endl;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

//int WinMain() {
//  std::cout << "Hello, World!" << std::endl;
//  return 0;
//}
