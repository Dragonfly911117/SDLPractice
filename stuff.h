//
// Created by DF on 4/13/2023.
//

#ifndef SDLPRACTICE_STUFF_H
#define SDLPRACTICE_STUFF_H

#include "SDL_rwops.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "SDL_image.h"
#include "config.h"
#include <SDL.h>
#include <vector>

bool init(SDL_Window*& window, SDL_Surface*& surface);
SDL_Surface*loadSurface(const std::string& path);
bool loadMedia(SDL_Surface*& pngSurface, SDL_Surface*& baseSurface);
void close(SDL_Window*& window, SDL_Surface*& img);

enum keyPress {
    KEY_PRESS_NONE = 0,
    KEY_PRESS_UP,
    KEY_PRESS_DOWN,
    KEY_PRESS_LEFT,
    KEY_PRESS_RIGHT,
};

#endif //SDLPRACTICE_STUFF_H
