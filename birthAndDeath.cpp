//
// Created by DF on 4/13/2023.
//

#include "birthAndDeath.h"


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

bool loadMedia(SDL_Surface*& img) {
    img = SDL_LoadBMP("../../garuda.bmp");
    if (img == nullptr){
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
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
