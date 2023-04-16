#include <SDL.h>
#include <SDL_image.h>
#include "MySDL_Texture.h"
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "mySDL_Texture.h"
#include "config.h"
#include "SDL_ttf.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    MySDL_Texture background;
    background.loadFromFile("C:\\Users\\DF\\CLionProjects\\SDLPractice\\resource\\image.png", renderer);
    background.render(0, 0, renderer);
    MySDL_Texture text;
    text.loadFromRenderedText("waifu", {0xE8, 0xE8, 0xB5, 255}, renderer);
    text.render(WINDOW_WIDTH - 500, WINDOW_HEIGHT - 300, renderer);
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
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
