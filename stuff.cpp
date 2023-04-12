//
// Created by DF on 4/13/2023.
//

#include "stuff.h"
#include "SDL_surface.h"


bool init(SDL_Window*& window, SDL_Surface*& surface) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {  // get -1 if errors occur
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    surface = SDL_GetWindowSurface(window);
    return true;
}

bool loadMedia(std::vector<SDL_Surface*>& vec) {
    vec.emplace_back(SDL_LoadBMP("../../resource/press.bmp"));
    if (vec[0] == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "press.bmp", SDL_GetError());
        return false;
    }
    vec.emplace_back(SDL_LoadBMP("../../resource/up.bmp"));
    if (vec[1] == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "up.bmp", SDL_GetError());
        return false;
    }
    vec.emplace_back(SDL_LoadBMP("../../resource/down.bmp"));
    if (vec[2] == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "down.bmp", SDL_GetError());
        return false;
    }
    vec.emplace_back(SDL_LoadBMP("../../resource/left.bmp"));
    if (vec[3] == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "left.bmp", SDL_GetError());
        return false;
    }
    vec.emplace_back(SDL_LoadBMP("../../resource/right.bmp"));
    if (vec[4] == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "right.bmp", SDL_GetError());
        return false;
    }


    return true;
}

void close(SDL_Window*& window, SDL_Surface*& img) {
    SDL_FreeSurface(img);
    img = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}
