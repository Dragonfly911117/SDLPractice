#include <SDL.h>
#include <SDL_image.h>
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "mySDL_Texture.h"
#include "config.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* tex;
    SDL_Surface* surface;
    surface = IMG_Load("C:\\Users\\DF\\CLionProjects\\SDLPractice\\resource\\image.png");
    tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    MySDL_Texture texture;

    texture.loadFromFile("C:\\Users\\DF\\CLionProjects\\SDLPractice\\resource\\foo.png", renderer);
    texture.render(0, 0, renderer);
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
        SDL_RenderCopy(renderer, tex, NULL, NULL);
        texture.render(0, 0, renderer);
        texture.toggleAnimation();
        SDL_Delay(1000 / 10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

#include "config.h"
