//
// Created by DF on 4/13/2023.
//

#include <string>
#include "stuff.h"


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
    if(not IMG_Init(IMG_INIT_PNG)){
        printf("SDL_image could not init! SDL_image Error:", IMG_GetError());
        return false;
    }

    surface = SDL_GetWindowSurface(window);
    return true;
}

bool loadMedia(SDL_Surface*& pngSurface, SDL_Surface*& baseSurface) {
    SDL_Surface*temp;
    temp = loadSurface("../resource/image.png");
    pngSurface = SDL_ConvertSurface(temp, baseSurface->format, 0);
    SDL_FreeSurface(temp);
    return pngSurface != nullptr;
}

void close(SDL_Window*& window, SDL_Surface*& img) {
    SDL_FreeSurface(img);
    img = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}

SDL_Surface*loadSurface(const std::string& path) {
    SDL_Surface*loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    return loadedSurface;
}
