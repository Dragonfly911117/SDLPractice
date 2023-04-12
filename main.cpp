#include "SDL_events.h"
#include "SDL_pixels.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <SDL.h>
#include <cstdio>
#include <iostream>
#include "config.h"
#include "birthAndDeath.h"

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;
    SDL_Surface* img = nullptr;
    if (not init(window, screenSurface)) {
        std::cout << "Failed to initialize\n";
        return -1;
    }
    if (not loadMedia(img)) {
        std::cout << "Failed to load image\n";
        return -1;
    }
    SDL_BlitSurface(img, nullptr, screenSurface, nullptr);
    SDL_UpdateWindowSurface(window);
    bool quit = false;
    SDL_Event e;
    while (not quit) {
        while (SDL_PollEvent(&e)) {
            quit = e.type == SDL_QUIT;
        }
    }
    close(window, img);
    return 0;
}