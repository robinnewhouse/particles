#include <iostream>
#define SDL_MAIN_HANDLED
#include "SDL.h"
using namespace std;
//#undef main

int main() {
  std::cout << "Hello, World!" << std::endl;

//  SDL_SetMainReady();
  if (SDL_Init(SDL_INIT_VIDEO < 0)){
    cout << "SDL_Init Failed" << endl;
    return 6;
  };
  
  cout << "Success" << endl;

  SDL_Quit();

  return 0;
}

//int WinMain() {
//  std::cout << "Hello, World!" << std::endl;
//  return 0;
//}
