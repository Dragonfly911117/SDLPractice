//
// Created by DF on 4/13/2023.
//

#ifndef SDLPRACTICE_BIRTHANDDEATH_H
#define SDLPRACTICE_BIRTHANDDEATH_H

#include "SDL_rwops.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "config.h"
#include <SDL.h>

bool init(SDL_Window*& window, SDL_Surface*& surface);
bool loadMedia(SDL_Surface*& img);
void close(SDL_Window*& window, SDL_Surface*& img);

#endif //SDLPRACTICE_BIRTHANDDEATH_H
