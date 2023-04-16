#include <SDL.h>
#include <SDL_image.h>
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "config.h"

int main(int argc, char*argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window*window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                         WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface*image = IMG_Load("C:\\Users\\DF\\CLionProjects\\SDLPractice\\resource\\image.png");
    SDL_Texture*texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    SDL_Rect rect = {0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);


    rect = {WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    rect = {0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);


    SDL_RenderPresent(renderer);


     SDL_Event event;
     bool running = true;
     while (running) {
         while (SDL_PollEvent(&event)) {
             if (event.type == SDL_KEYDOWN) {
                 if (event.key.keysym.sym == SDLK_ESCAPE) {
                     running = false;
                 }
             }
         }


     }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

#include "config.h"
