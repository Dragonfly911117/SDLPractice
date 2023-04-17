#include <SDL.h>
#include <SDL_image.h>
#include <sstream>
#include <iostream>
#include "MySDL_Texture.h"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_timer.h"
#include "config.h"
#include "SDL_ttf.h"

bool init();

int main(int argc, char* argv[]) {
    if (!init()) {
        printf("Failed to initialize!\n");
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    MySDL_Texture background;
    background.loadFromFile("resource/image.png", renderer);
    background.render(0, 0, renderer);

    MySDL_Texture text;
    text.setColor(0xE8, 0xE8, 0xB5);
    text.setText("Press Enter to Reset Start Time.");
    text.loadFromRenderedText(renderer);
    text.render(0, 0, renderer);

    MySDL_Texture lastHitTimer;
    lastHitTimer.setColor(0xE8, 0xE8, 0xB5);

    MySDL_Texture fpsText;
    fpsText.setColor(0xE8, 0xE8, 0xB5);
    fpsText.setHeight(20);
    fpsText.setWidth(100);

    Uint32 startTime, lastTime;
    startTime = lastTime = SDL_GetTicks();
    Uint32 fps = 0;
    std::stringstream ss;

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
                if (event.key.keysym.sym == SDLK_RETURN) {
                    background.render(0, 0, renderer);
                    text.render(0, 0, renderer);
                    ss.str("");
                    ss << "Milliseconds since last hit: " << SDL_GetTicks() - startTime;
                    startTime = SDL_GetTicks();
                    lastHitTimer.setText(ss.str());
                    lastHitTimer.loadFromRenderedText(renderer);
                    lastHitTimer.render(0, WINDOW_HEIGHT - lastHitTimer.getHeight(), renderer);
                    fpsText.render(WINDOW_WIDTH - fpsText.getWidth(), 0, renderer);
                    SDL_RenderPresent(renderer);
                }
            }
        }
        if (SDL_GetTicks() - lastTime > 1000) {
            ss.str("");
            ss << "FPS: " << fps;
            fpsText.setText(ss.str());
            fpsText.loadFromRenderedText(renderer);
            SDL_RenderClear(renderer);
            background.render(0, 0, renderer);
            if (!text.getText().empty()) {
                text.render(0, 0, renderer);
            }
            if (!lastHitTimer.getText().empty())
                lastHitTimer.render(0, WINDOW_HEIGHT - lastHitTimer.getHeight(), renderer);
            fpsText.render(WINDOW_WIDTH - fpsText.getWidth(), 0, renderer);
            fps = 0;
            lastTime = SDL_GetTicks();
            SDL_RenderPresent(renderer);
        }
        fps++;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

// init SDL. SDL_IMG, SDL_TTF
bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not initialize! SDL Error: %s \n", SDL_GetError());
        success = false;
    }
    if (IMG_Init(IMG_INIT_PNG) < 0) {
        printf("SDL_image could not initialize! SDL_image Error: %s \n", IMG_GetError());
        success = false;
    }
    if (TTF_Init() < 0) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s \n", TTF_GetError());
        success = false;
    }
    return success;
}
