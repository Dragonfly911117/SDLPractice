#include "SDL_events.h"
#include "SDL_pixels.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "config.h"
#include <SDL.h>
#include <cstdio>

int main(int argc, char*argv[]) {
    SDL_Window*window = nullptr;
    SDL_Surface*screenSurface = nullptr;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {  // get -1 if errors occur
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xaf, 0x00, 0xef));

            SDL_UpdateWindowSurface(window);

            SDL_Event e;
            bool quit = false;
            while (not quit) {
                while (SDL_PollEvent(&e)) {
                    quit = e.type == SDL_QUIT;
                }
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}