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
    vec.emplace_back(loadSurface("../../resource/none.bmp"));
    vec.emplace_back(loadSurface("../../resource/up.bmp"));
    vec.emplace_back(loadSurface("../../resource/down.bmp"));
    vec.emplace_back(loadSurface("../../resource/left.bmp"));
    vec.emplace_back(loadSurface("../../resource/right.bmp"));
    for (const auto& img: vec) {
        if (img == nullptr) {
            return false;
        }
    }
    return true;
}

void close(SDL_Window*& window, SDL_Surface*& img, std::vector<SDL_Surface*>& vec) {
    SDL_FreeSurface(img);
    img = nullptr;

    for (auto& surface: vec) {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
    vec.clear();

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}

SDL_Surface*loadSurface(const char*path) {
    SDL_Surface*loadedSurface = SDL_LoadBMP(path);
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }
    return loadedSurface;
}
