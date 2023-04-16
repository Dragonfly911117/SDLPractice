#include <SDL.h>
#include <SDL_image.h>
#include "SDL_events.h"
#include "SDL_render.h"
#include "config.h"

int main(int argc, char*argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window*window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                         WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Rect rect;
    rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    SDL_Event event;
    bool running = true;
    int c = 0;
    bool flag = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN){
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xef, 0xff);
        SDL_RenderClear(renderer);

        if (flag) {
            c++;
            if (c == 255) {
                flag = false;
            }
        } else {
            c--;
            if (c == 0) {
                flag = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, c / 2 ,  0, c, 0xff);
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
        SDL_RenderDrawLine(renderer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
        SDL_RenderDrawLine(renderer, 0, WINDOW_HEIGHT, WINDOW_WIDTH, 0);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}