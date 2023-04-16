//
// Created by DF on 4/17/2023.
//

#ifndef SDLPRACTICE_MYSDL_TEXTURE_H
#define SDLPRACTICE_MYSDL_TEXTURE_H


#include "SDL_blendmode.h"
#include "SDL_stdinc.h"
#include "SDL_render.h"
#include <string>
#include <vector>


class MySDL_Texture {
public:
    MySDL_Texture();
    ~MySDL_Texture();
    bool loadFromFile(const std::string& path, SDL_Renderer* renderer);
    void free();
    void render(const int& x = 0, const int& y = 0, SDL_Renderer* renderer = nullptr, SDL_Rect* clip = nullptr,
                double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

    // setters
    void toggleAnimation();
    void setFrame(int frame);

    // getters
    int getWidth();
    int getHeight();
    int getFrame() const;

private:
    SDL_Texture* _texture;
    int _width;
    int _height;
    static const int _walkAnimationFrames = 4;
    bool ifAnimationModeOn = false;
    std::vector<SDL_Rect> _walkClips;
    int _currentFrame = 0;
};


#endif //SDLPRACTICE_MYSDL_TEXTURE_H
