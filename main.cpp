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
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

//int WinMain() {
//  std::cout << "Hello, World!" << std::endl;
//  return 0;
//}
