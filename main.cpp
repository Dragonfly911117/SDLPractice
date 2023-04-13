#include "SDL_events.h"
#include "SDL_pixels.h"
#include "SDL_rect.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <SDL.h>
#include <cstdio>
#include <iostream>
#include "config.h"
#include "stuff.h"

int main() {
    SDL_Window*window = nullptr;
    SDL_Surface*screenSurface = nullptr;
    SDL_Surface* img = nullptr;
    if (not init(window, screenSurface)) {
        std::cout << "Failed to initialize\n";
        return -1;
    }
    if (not loadMedia(img, screenSurface)) {
        std::cout << "Failed to load media\n";
        return -1;
    }

    SDL_Rect stretched;
    stretched.x = 0;
    stretched.y = 0;
    stretched.w = WINDOW_WIDTH;
    stretched.h = WINDOW_HEIGHT;

    SDL_BlitScaled(img, nullptr, screenSurface, &stretched);
    SDL_UpdateWindowSurface(window);

    bool quit = false;
    SDL_Event e;
    while (not quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    quit = true;
//                SDL_BlitScaled(img, nullptr, screenSurface, &stretched);
//                SDL_UpdateWindowSurface(window);
            }
        }
    }
    close(window, img);
    return 0;
}