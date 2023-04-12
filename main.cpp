#include "SDL_events.h"
#include "SDL_pixels.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <SDL.h>
#include <cstdio>
#include <iostream>
#include "config.h"
#include "stuff.h"

int main(int argc, char*argv[]) {
    SDL_Window*window = nullptr;
    SDL_Surface*screenSurface = nullptr;
    std::vector<SDL_Surface*> keyImages;
    if (not init(window, screenSurface)) {
        std::cout << "Failed to initialize\n";
        return -1;
    }
    if (not loadMedia(keyImages)) {
        std::cout << "Failed to load media\n";
        return -1;
    }
    SDL_Surface*img = keyImages[0];
    SDL_BlitSurface(img, nullptr, screenSurface, nullptr);
    SDL_UpdateWindowSurface(window);
    bool quit = false;
    SDL_Event e;
    while (not quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP)
                    img = keyImages[KEY_PRESS_UP];
                else if (e.key.keysym.sym == SDLK_DOWN)
                    img = keyImages[KEY_PRESS_DOWN];
                else if (e.key.keysym.sym == SDLK_LEFT)
                    img = keyImages[KEY_PRESS_LEFT];
                else if (e.key.keysym.sym == SDLK_RIGHT)
                    img = keyImages[KEY_PRESS_RIGHT];
                else if (e.key.keysym.sym == SDLK_ESCAPE)
                    quit = true;
                else
                    img = keyImages[KEY_PRESS_NONE];
                SDL_BlitSurface(img, nullptr, screenSurface, nullptr);
                SDL_UpdateWindowSurface(window);
            }
        }
    }
    close(window, img);
    return 0;
}